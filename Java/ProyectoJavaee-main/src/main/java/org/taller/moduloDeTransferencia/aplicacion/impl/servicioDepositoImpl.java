package org.taller.moduloDeTransferencia.aplicacion.impl;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.List;

import org.taller.moduloDeTransferencia.aplicacion.servicioDeposito;
import org.taller.moduloDeTransferencia.dominio.CuentaBancoComercio;
import org.taller.moduloDeTransferencia.dominio.DataFecha;
import org.taller.moduloDeTransferencia.dominio.Deposito;
import org.taller.moduloDeTransferencia.dominio.repositorio.cuentaRepo;
import org.taller.moduloDeTransferencia.dominio.repositorio.depositoRepo;
import org.taller.moduloDeTransferencia.interfase.evento.out.PublicarEvento;
import org.taller.moduloDeTransferencia.wscliente.BancoClienteService;
import org.taller.moduloDeTransferencia.wscliente.BancoClienteService_Service;
import org.taller.moduloDeTransferencia.wscliente.ConfirmationResponse;
import org.taller.moduloDeTransferencia.wscliente.NotificationRequest;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;
import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

@ApplicationScoped
public class servicioDepositoImpl implements servicioDeposito {
    @Inject
    private  depositoRepo repo; // repositorio en memoria
    
    @Inject
    private  cuentaRepo repo2; // repositorio en memoria
    
    @Inject
    private BancoClienteService_Service service; // Cliente del servicio web del banco
    
    @PersistenceContext
    private EntityManager em;

    @Inject
    private PublicarEvento evento;
    
    @Override
    public void realizarDeposito(int idCompra, String rutComercio) {

       Float monto;
        try {
            monto = em.createQuery(
                    "SELECT c.importe FROM DataCompra c WHERE c.id = :idCompra", Float.class)
                .setParameter("idCompra", idCompra)
                .getSingleResult();
        } catch (Exception e) {
            System.out.println("❌ No se pudo obtener el monto de la compra con ID: " + idCompra);
            return;
        }
        float comision = monto * 0.02f;
        float montoNeto = monto - comision;

        CuentaBancoComercio cuentaBanco = repo2.buscarPorRut(rutComercio);
        if (cuentaBanco == null) {
            throw new RuntimeException("❌ Cuenta bancaria no encontrada para el comercio con RUT: " + rutComercio);
        }

        Deposito deposito = new Deposito();
        deposito.setImporte(montoNeto);
        deposito.setIdCompra(idCompra);
        deposito.setCuenta(cuentaBanco); // Asignar la cuenta al depósito
        deposito.setFecha(DataFecha.now()); 
        if (repo.existe(idCompra)) {
            throw new RuntimeException("❌ Ya existe un depósito para la compra con ID: " + idCompra);
        }
        repo.guardar(deposito);
        cuentaBanco.addDeposito(deposito); // Agregar el depósito a la cuenta
        repo2.Actualizar(cuentaBanco); // Guardar la cuenta actualizada
        notificarAlBanco(idCompra, rutComercio, montoNeto);
        evento.publicarTransferencia( "Transferencia realizada: \nRut Comercio:" + rutComercio +  "\nMonto Bruto:" + monto + "\nMonto neto depositado" + montoNeto);
    }

    public void notificarAlBanco(int idCompra, String rutComercio, float monto) {
        try {
            // Crear el cliente del servicio web del banco
            BancoClienteService port = service.getBancoClientePort();

            // Armar el request
            NotificationRequest request = new NotificationRequest();
            request.setIdCompra(idCompra);
            request.setRutComercio(rutComercio);
            request.setMonto(monto);

            // Invocar la operación
            ConfirmationResponse response = port.notificarTransferencia(request);

            // Manejar respuesta
            System.out.println("Respuesta del banco: " + response); // Mejor si imprimís algún campo
        } catch (Exception e) {
            System.err.println("Error al notificar transferencia al banco:");
            e.printStackTrace();
        }
    }
    
    @Override
    public List<Deposito> MostrarHistorialDeDepositos(String rutComercio, String fechaIni, String fechaEnd) {
        CuentaBancoComercio cuentaBanco = repo2.buscarPorRut(rutComercio);
        if (cuentaBanco == null) {
            throw new RuntimeException("❌ Cuenta bancaria no encontrada para el comercio con RUT: " + rutComercio);
        }
        List<Deposito> listaDepositos = cuentaBanco.getListaDepositos();
        if (listaDepositos == null || listaDepositos.isEmpty()) {
            throw new RuntimeException("❌ No hay depósitos registrados para el comercio con RUT: " + rutComercio);
        }
        DataFecha Inicio = parseFecha(fechaIni);
        DataFecha Fin = parseFecha(fechaEnd);
        // Filtrar los depósitos por rango de fecha
        if (fechaIni == null || fechaEnd == null) {
            throw new IllegalArgumentException("❌ Las fechas de inicio y fin no pueden ser nulas.");
        }
        List<Deposito> depositosFiltrados = repo.buscarPorRangoDeFecha(listaDepositos, Inicio, Fin);
         
        return depositosFiltrados;   
    }
    private DataFecha parseFecha(String fechaStr) {
        // Acepta formato "dd-MM-yyyy"
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        LocalDate fecha = LocalDate.parse(fechaStr, formatter);
        return new DataFecha(fecha.getDayOfMonth(), fecha.getMonthValue(), fecha.getYear());
    }
   
}