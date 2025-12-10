package org.taller.moduloDeMonitoreo.aplicacion;

import io.micrometer.core.instrument.Counter;
import io.micrometer.core.instrument.MeterRegistry;
import org.taller.moduloDeMonitoreo.dominio.ServicioMonitoreo;
import org.taller.moduloDeMonitoreo.infraestructura.eventos.BusDeEventos;

public class ServicioMonitoreoImpl implements ServicioMonitoreo {

    @SuppressWarnings("unused")
    private final BusDeEventos bus;
    private final Counter pagosOkCounter;
    private final Counter pagosErrorCounter;
    private final Counter pagoCounter;
    private final Counter transferenciaCounter;
    private final Counter reclamoCounter;

    public ServicioMonitoreoImpl(BusDeEventos bus, MeterRegistry registry) {
        this.bus = bus;
        this.pagosOkCounter = registry.counter("pagos_ok");
        this.pagosErrorCounter = registry.counter("pagos_error");
        this.pagoCounter = registry.counter("pagos");
        this.transferenciaCounter = registry.counter("transferencias");
        this.reclamoCounter = registry.counter("reclamos");
    }
    
    @Override
    public void notificarPago() {
        pagoCounter.increment();
    }

    @Override
    public void notificarPagoOk() {
        pagosOkCounter.increment();
    }

    @Override
    public void notificarPagoError() {
        pagosErrorCounter.increment();
    }

    @Override
    public void notificarTransferencia() {
        transferenciaCounter.increment();
    }

    @Override
    public void notificarReclamoComercio() {
        reclamoCounter.increment();
    }
}
