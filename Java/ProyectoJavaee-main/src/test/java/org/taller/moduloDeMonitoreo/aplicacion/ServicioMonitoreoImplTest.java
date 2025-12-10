/*
package org.taller.moduloDeMonitoreo.aplicacion;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.taller.moduloDeMonitoreo.infraestructura.eventos.BusDeEventos;
import org.taller.moduloDeMonitoreo.repositorio.RepositorioEventos;
import org.taller.moduloDeMonitoreo.dominio.ServicioMonitoreo;

import static org.mockito.Mockito.*;

public class ServicioMonitoreoImplTest {

    private RepositorioEventos repositorioMock;
    private BusDeEventos bus;
    private ServicioMonitoreo servicio;

    @BeforeEach
    public void setUp() {
        repositorioMock = mock(RepositorioEventos.class);
        bus = new BusDeEventos();
        bus.registrar(new ObservadorMonitoreo(repositorioMock));
        servicio = new ServicioMonitoreoImpl(bus);
    }

    @Test
    public void testNotificarPago() {
        servicio.notificarPago();
        verify(repositorioMock).guardarEvento("PAGO", "Se realizó un pago");
    }

    @Test
    public void testNotificarPagoOk() {
        servicio.notificarPagoOk();
        verify(repositorioMock).guardarEvento("PAGO_OK", "Pago exitoso");
    }

    @Test
    public void testNotificarPagoError() {
        servicio.notificarPagoError();
        verify(repositorioMock).guardarEvento("PAGO_ERROR", "Pago rechazado");
    }

    @Test
    public void testNotificarTransferencia() {
        servicio.notificarTransferencia();
        verify(repositorioMock).guardarEvento("TRANSFERENCIA", "Se realizó una transferencia");
    }

    @Test
    public void testNotificarReclamoComercio() {
        servicio.notificarReclamoComercio();
        verify(repositorioMock).guardarEvento("RECLAMO", "Reclamo del comercio recibido");
    }
}

	
*/