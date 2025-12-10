package org.taller.moduloDeMonitoreo.interface_.observador;

import org.jboss.logging.Logger;
import org.taller.moduloDeCompra.interfase.eventos.out.EventoPagoError;
import org.taller.moduloDeCompra.interfase.eventos.out.EventoPagoExitoso;
import org.taller.moduloDeCompra.interfase.eventos.out.EventoReporte;
import org.taller.moduloDeMonitoreo.aplicacion.RegistradoDeMetricas;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.enterprise.event.Observes;
import jakarta.inject.Inject;

@ApplicationScoped
public class ObserverModuloCompra {
    private static final Logger log = Logger.getLogger(ObserverModuloTransferencia.class);

    @Inject
    private RegistradoDeMetricas register;

    public void accept(@Observes EventoPagoExitoso evento) {
        log.infof("Evento procesado:", evento.getDescripcion());
        register.notificarPagoOk();
    }

    public void accept(@Observes EventoPagoError evento) {
        log.infof("Evento procesado:", evento.getDescripcion());
        register.notificarPagoError();
    }

    public void accept(@Observes EventoReporte evento) {
        log.infof("Evento procesado:", evento.getDescripcion());
        register.incrementarCounter(RegistradoDeMetricas.reportesCounter);
    }
}
