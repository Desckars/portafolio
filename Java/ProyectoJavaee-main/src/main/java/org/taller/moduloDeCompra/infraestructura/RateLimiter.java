package org.taller.moduloDeCompra.infraestructura;

import java.time.Duration;

import io.github.bucket4j.Bandwidth;
import io.github.bucket4j.Bucket;
import jakarta.annotation.PostConstruct;
import jakarta.enterprise.context.ApplicationScoped;
import io.github.bucket4j.Refill;

/**
 * Rate limiter del tipo token bucket
 */
@ApplicationScoped
public class RateLimiter {

    private Bucket bucket;
    private boolean activo;

    @PostConstruct
    public void inicializar() {
        activo = true;
        Bandwidth bucketConf = Bandwidth.classic(10, Refill.greedy(5, Duration.ofSeconds(1))); // Capacidad máxima de tokens y reabastecimiento

        bucket = Bucket.builder().addLimit(bucketConf).build();
    }

    public boolean consumir() {
        boolean result = bucket.tryConsume(1);
        System.out.println("Tokens restantes: " + bucket.getAvailableTokens());
        return result;
    }

    public void activarRateLimiter(boolean estado) {
        System.out.println("RateLimiter estado: " + estado);
        this.activo = estado;
    }

    public boolean isActivo() {
        return this.activo;
    }
}