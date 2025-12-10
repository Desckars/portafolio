package org.taller.moduloDeComercio.interfase.eventos.out;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.enterprise.event.Event;
import jakarta.inject.Inject;

@ApplicationScoped
public class PublicadorEvento {
    @Inject
    private Event<EventoReclamo> ReclamoRealizado;

    @Inject
    private Event<EventoReclamoNegativo> ReclamoNegativo;
//    @Inject
//    private Event<PeajePagoSucive> pagoSuciveEvento;

    public void publicarReclamo(String mensaje){
        ReclamoRealizado.fire(new EventoReclamo(mensaje));
    }

    public void publicarReclamoNegativo(String mensaje){
        ReclamoNegativo.fire(new EventoReclamoNegativo(mensaje));
    }

//    public void publicarPagoSucive(String mensaje){
//        pagoSuciveEvento.fire(new PeajePagoSucive(mensaje));
//    }
}
