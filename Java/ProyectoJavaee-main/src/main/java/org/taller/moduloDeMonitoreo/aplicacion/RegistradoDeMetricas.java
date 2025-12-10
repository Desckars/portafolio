package org.taller.moduloDeMonitoreo.aplicacion;

import java.time.Duration;

import io.micrometer.core.instrument.Clock;
import io.micrometer.core.instrument.MeterRegistry;
import io.micrometer.influx.InfluxConfig;
import io.micrometer.influx.InfluxMeterRegistry;
import jakarta.annotation.PostConstruct;
import jakarta.enterprise.context.ApplicationScoped;

@ApplicationScoped
public class RegistradoDeMetricas{

    public static final String transferenciaCounter = "transferenciaCounter"; //Hecho
    public static final String reclamoCounter = "reclamoCounter"; //Hecho
    public static final String reportesCounter = "reporteCounter"; // Hecho
    MeterRegistry meterRegistry;

    private InfluxConfig config;
    

    @PostConstruct
    public void init(){
        config = new InfluxConfig() {
            @Override
            public String get(String key) {
                return null; // Default config for everything else
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
        this.meterRegistry = new InfluxMeterRegistry(config, Clock.SYSTEM);
    }

    public void incrementarCounter(String nombreCounter) {
        this.meterRegistry.counter(nombreCounter).increment();
    }

    public void notificarPagoOk() {
        this.meterRegistry.counter("pagos", "estado", "ok").increment();
    }

    public void notificarPagoError() {
        this.meterRegistry.counter("pagos", "estado", "error").increment();
    }

    public void notificarReclamoTotal() {
        this.meterRegistry.counter(reclamoCounter, "etiqueta", "TOTAL").increment();
    }

    public void notificarReclamoNegativo() {
        this.meterRegistry.counter(reclamoCounter, "etiqueta", "NEGATIVO").increment();
    }

}
