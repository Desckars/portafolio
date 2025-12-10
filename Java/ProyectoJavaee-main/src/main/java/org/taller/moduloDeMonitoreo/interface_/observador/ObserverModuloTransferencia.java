package org.taller.moduloDeMonitoreo.interface_.observador;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.enterprise.event.Observes;
import jakarta.inject.Inject;
import org.jboss.logging.Logger;
import org.taller.moduloDeMonitoreo.aplicacion.RegistradoDeMetricas;
import org.taller.moduloDeTransferencia.interfase.evento.out.EventoTransferencia;

@ApplicationScoped
public class ObserverModuloTransferencia {
    private static final Logger log = Logger.getLogger(ObserverModuloTransferencia.class);

    @Inject
    private RegistradoDeMetricas register;

    public void accept(@Observes EventoTransferencia event) {
        log.infof("Evento procesado:", event.getMessage());
        register.incrementarCounter(RegistradoDeMetricas.transferenciaCounter);
    }
}
