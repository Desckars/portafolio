// Lógica desacoplada de REST
package org.taller.moduloDeCompra.aplicacion.Impl;

import java.util.List;
import java.util.stream.Collectors;

import org.taller.moduloDeCompra.aplicacion.ModuloCompras;
import org.taller.moduloDeCompra.dominio.DataCompra;
import org.taller.moduloDeCompra.dominio.DataFecha;
import org.taller.moduloDeCompra.dominio.DataTarjeta;
import org.taller.moduloDeCompra.infraestructura.MedioPagoClient;
import org.taller.moduloDeCompra.infraestructura.PagoRequest;
import org.taller.moduloDeCompra.infraestructura.PagoResponse;
import org.taller.moduloDeCompra.infraestructura.RateLimiter;
import org.taller.moduloDeCompra.interfase.eventos.out.PublicadorEvento;
import org.taller.moduloDeCompra.persistencia.ComercioService;
import org.taller.moduloDeCompra.persistencia.CompraService;
import org.taller.moduloDeCompra.persistencia.TarjetaService;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;

@ApplicationScoped
public class ModuloComprasImpl implements ModuloCompras {

    @Inject
    ComercioService comercioService;
    
    @Inject
    RateLimiter rateLimiter;
    @Inject
    private CompraService compraService;

    @Inject
    private TarjetaService tarjetaservice;

    @Inject
    private PublicadorEvento evento;

    @Override
    public void procesarPago(DataCompra datosCompra) {
    // Verificar el RateLimiter
    if (rateLimiter.isActivo() && !rateLimiter.consumir()) {
        throw new IllegalStateException("Rate limit exceeded. Try again later.");
    }

    // Validar que la tarjeta esté presente
    if (datosCompra.getTarjeta() == null || datosCompra.getTarjeta().getNro() == null) {
        throw new IllegalArgumentException("La tarjeta asociada a la compra no puede ser nula.");
    }

    // Crear el cliente REST para el medio de pago
    MedioPagoClient medioPagoClient = new MedioPagoClient();
    PagoRequest request = new PagoRequest(datosCompra.getTarjeta().getNro(), datosCompra.getImporte());

    try {
        // Enviar la transacción (registro del evento)
        enviarTransaccion(datosCompra.getImporte(), datosCompra);

        // Enviar la solicitud al medio de pago
        PagoResponse response = medioPagoClient.procesarPago(request);

        // Esperar respuesta (simulación o registro del evento)
        String respuesta = esperarRespuesta();
        System.out.println("Respuesta recibida: " + respuesta);

        if (response.autorizado) {
            // Pago autorizado
            System.out.println("✅ Pago autorizado: " + response.codigo);
            notificarPagoOk();

            // Persistir la tarjeta si no existe
            DataTarjeta tarjetaPersistida = tarjetaservice.guardarSiNoExiste(datosCompra.getTarjeta());
            datosCompra.setTarjeta(tarjetaPersistida);

            // Asignar la fecha actual a la compra
            DataFecha fechaHoy = DataFecha.hoy();
            datosCompra.setFecha(fechaHoy);
            System.out.println("✅ Pasa data fecha: ");
            // Persistir la compra
            compraService.guardar(datosCompra);
            System.out.println("ID generado: " + datosCompra.getId()); // ← ya tiene ID
            
            // Notificar al módulo de transferencia
            medioPagoClient.notificarDeposito(datosCompra.getId(), datosCompra.getRutComercio());
            System.out.println("✅ Notificación de depósito enviada.");
            
        } else {
            // Pago rechazado
            System.out.println("❌ Pago rechazado: " + response.codigo);
            notificarPagoError();
        }
    } catch (RuntimeException e) {
        // Manejar errores de comunicación con el medio de pago
        System.err.println("❌ Error al procesar el pago: " + e.getMessage());
        notificarPagoError();
    }
}

    private void enviarTransaccion(Float monto, DataCompra datos) {
        System.out.println("Evento: enviarTransaccion(" + monto + ", " + datos + ")");
    }

    private String esperarRespuesta() {
        return "OK:123456";
    }

    private void notificarPagoOk() {
        System.out.println("Evento: notificarPagoOk");
        evento.publicarPagoOk("PagoOk");
    }

    private void notificarPagoError() {
        System.out.println("Evento: notificarPagoError");
        evento.publicarPagoError("PagoError");
    }

    @Override
    public List<DataCompra> resumenVentasDiarias(String idComercio) {
        // Obtener el compras por RUT de Comercio
        List<DataCompra> compras = compraService.listarComprasPorRutComercio(idComercio);
        if (compras == null || compras.isEmpty()) {
            throw new IllegalArgumentException("No se encontraron compras para el comercio con RUT: " + idComercio);
        }
        evento.publicarReporte("Reporte Ventas Diarias");
        // Filtrar las compras del día de hoy y sumar sus importes
        DataFecha hoy = DataFecha.hoy();
        return compras.stream()
        .filter(compra -> compra.getFecha().equals(hoy))
        .collect(Collectors.toList());
    }

    @Override
    public List<DataCompra> resumenVentasPorPeriodo(String idComercio, String fechaIni, String fechaEnd) {
        // Validar que las fechas no sean nulas o vacías
        if (fechaIni == null || fechaIni.isEmpty() || fechaEnd == null || fechaEnd.isEmpty()) {
            throw new IllegalArgumentException("Las fechas de inicio y fin no pueden ser nulas o vacías.");
        }
        // Validar que el idComercio no sea nulo
        if (idComercio == null) {
            throw new IllegalArgumentException("El id del comercio no puede ser nulo.");
        }
        evento.publicarReporte("Reporte Ventas x Periodo");
        return compraService.listarVentasPorPeriodo(idComercio, fechaIni, fechaEnd);
    }

    @Override
    public float montoActualVendido(String idComercio) {
        // Obtener el compras por RUT de Comercio
        List<DataCompra> compras = compraService.listarComprasPorRutComercio(idComercio);
        if (compras == null || compras.isEmpty()) {
            throw new IllegalArgumentException("No se encontraron compras para el comercio con RUT: " + idComercio);
        }
        // Filtrar las compras del día de hoy y sumar sus importes
        DataFecha hoy = DataFecha.hoy();
        double total = compras.stream()
            .filter(compra -> compra.getFecha().equals(hoy))
            .mapToDouble(DataCompra::getImporte)
            .sum();
        evento.publicarReporte("Reporte Ventas Totales");
        return (float) total;
    }


}
