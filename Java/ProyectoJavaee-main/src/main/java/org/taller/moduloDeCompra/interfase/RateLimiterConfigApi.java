package org.taller.moduloDeCompra.interfase;

import org.taller.moduloDeCompra.infraestructura.RateLimiter;

import jakarta.inject.Inject;
import jakarta.ws.rs.*;
import jakarta.ws.rs.core.MediaType;

@Path("/config")
public class RateLimiterConfigApi {

    @Inject
    private RateLimiter rateLimiter;

    @GET
    @Path("/activarRateLimiter")
    @Produces(MediaType.APPLICATION_JSON)
    public String activarRateLimiter(@QueryParam("estado") boolean estado) {
        rateLimiter.activarRateLimiter(estado);
        return "{\"estado\": " + estado + "}";
    }
}