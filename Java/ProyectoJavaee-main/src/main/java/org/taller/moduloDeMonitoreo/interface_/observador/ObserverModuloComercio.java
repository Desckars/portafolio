package org.taller.moduloDeMonitoreo.interface_.observador;

import org.jboss.logging.Logger;
import org.taller.moduloDeComercio.interfase.eventos.out.EventoReclamo;
import org.taller.moduloDeComercio.interfase.eventos.out.EventoReclamoNegativo;
import org.taller.moduloDeMonitoreo.aplicacion.RegistradoDeMetricas;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.enterprise.event.Observes;
import jakarta.inject.Inject;

@ApplicationScoped
public class ObserverModuloComercio {
    private static final Logger log = Logger.getLogger(ObserverModuloTransferencia.class);

    @Inject
    private RegistradoDeMetricas register;

    public void aceptarReclamo(@Observes EventoReclamo evento) {
        log.infof("Reclamo recibido: %s", evento.getDescripcion());
        register.notificarReclamoTotal();
    }

    public void aceptarReclamoNegativo(@Observes EventoReclamoNegativo evento) {
        log.infof("Reclamo NEGATIVO recibido: %s", evento.getDescripcion());
        register.notificarReclamoNegativo();
    }

}
