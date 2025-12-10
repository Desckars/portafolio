package org.taller.moduloDeTransferencia.interfase.evento.out;

import jakarta.inject.Inject;
import jakarta.enterprise.context.ApplicationScoped;
import jakarta.enterprise.event.Event;

@ApplicationScoped
public class PublicarEvento {
    @Inject
    private Event<ComercioCreadoEvent> ComercioCreadoEvent;

    @Inject
    private Event<EventoTransferencia> EventoTransferencia;

    public void publicarComercioCreado(int rutComercio){
        ComercioCreadoEvent.fire(new ComercioCreadoEvent(rutComercio));
    }

    public void publicarTransferencia(String mensaje){
        EventoTransferencia.fire(new EventoTransferencia(mensaje));
    }
}
