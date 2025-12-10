package org.taller.moduloDeCompra.interfase.eventos.out;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.enterprise.event.Event;
import jakarta.inject.Inject;

@ApplicationScoped
public class PublicadorEvento {
    @Inject
    private Event<EventoPagoExitoso> PagoOk;
    @Inject
    private Event<EventoPagoError> PagoError;
    @Inject
    private Event<EventoReporte> Reportes;

    public void publicarPagoOk(String mensaje){
        PagoOk.fire(new EventoPagoExitoso(mensaje));
    }

    public void publicarPagoError(String mensaje){
        PagoError.fire(new EventoPagoError(mensaje));
    }

    public void publicarReporte(String mensaje){
        Reportes.fire(new EventoReporte(mensaje));
    }
}
