/*

package org.taller.moduloDeMonitoreo.aplicacion;

import io.micrometer.core.instrument.Counter;
import io.micrometer.core.instrument.Clock;
import io.micrometer.influx.InfluxConfig;
import io.micrometer.influx.InfluxMeterRegistry;
import org.taller.moduloDeMonitoreo.dominio.ServicioMonitoreo;
import org.taller.moduloDeMonitoreo.dominio.eventos.EventoPago;
import org.taller.moduloDeMonitoreo.infraestructura.eventos.BusDeEventos;

import java.time.Duration;

public class ServicioMonitoreoInfluxImpl implements ServicioMonitoreo {

    private final Counter pagosOkCounter;
    private final Counter pagosErrorCounter;
    private final Counter pagoCounter;
    private final Counter transferenciaCounter;
    private final Counter reclamoCounter;
    private final BusDeEventos bus;
    private final InfluxMeterRegistry registry;
    
    public ServicioMonitoreoInfluxImpl(BusDeEventos bus) {
        this.bus = bus;

        InfluxConfig config = new InfluxConfig() {
            @Override
            public String get(String key) {
                return null; // Default config for everything else
            }

            @Override
            public String uri() {
                return "http://localhost:8086";
            }

            @Override
            public String db() {
                return "micrometer"; // tu base de datos InfluxDB
            }

            @Override
            public Duration step() {
                return Duration.ofSeconds(10);
            }

        };
        
        this.registry = new InfluxMeterRegistry(config, Clock.SYSTEM);

        this.pagosOkCounter = registry.counter("pagos_ok");
        this.pagosErrorCounter = registry.counter("pagos_error");
        this.pagoCounter = registry.counter("pagos");
        this.transferenciaCounter = registry.counter("transferencias");
        this.reclamoCounter = registry.counter("reclamos");
    }

    @Override
    public void notificarPago() {
        bus.publicar(new EventoPago("PAGO", "Se realizó un pago"));
        pagoCounter.increment();
    }

    @Override
    public void notificarPagoOk() {
        bus.publicar(new EventoPago("PAGO_OK", "Pago exitoso"));
        pagosOkCounter.increment();
    }

    @Override
    public void notificarPagoError() {
        bus.publicar(new EventoPago("PAGO_ERROR", "Pago rechazado"));
        pagosErrorCounter.increment();
    }

    @Override
    public void notificarTransferencia() {
        bus.publicar(new EventoPago("TRANSFERENCIA", "Se realizó una transferencia"));
        transferenciaCounter.increment();
    }

    @Override
    public void notificarReclamoComercio() {
        bus.publicar(new EventoPago("RECLAMO", "Reclamo del comercio recibido"));
        reclamoCounter.increment();
    }
}

*/
