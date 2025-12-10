package org.taller.moduloDeComercio.security;

import java.util.Base64;

import jakarta.annotation.Priority;
import jakarta.inject.Inject;
import jakarta.ws.rs.Priorities;
import jakarta.ws.rs.container.ContainerRequestContext;
import jakarta.ws.rs.container.ContainerRequestFilter;
import jakarta.ws.rs.core.Response;
import jakarta.ws.rs.ext.Provider;

import jakarta.ws.rs.container.ResourceInfo;
import jakarta.ws.rs.core.Context;
import jakarta.annotation.security.PermitAll; 

@Provider
@Priority(Priorities.AUTHENTICATION)
public class AuthenticationFilter implements ContainerRequestFilter {

    @Inject
    private AuthService authService;
    @Context
    private ResourceInfo resourceInfo;
    @Override
    public void filter(ContainerRequestContext ctx) {
        if (resourceInfo.getResourceMethod().isAnnotationPresent(PermitAll.class) ||
            resourceInfo.getResourceClass().isAnnotationPresent(PermitAll.class)) {
            return;
        }

        String header = ctx.getHeaderString("Authorization");
        if (header == null || !header.startsWith("Basic ")) {
            ctx.abortWith(Response.status(Response.Status.UNAUTHORIZED).build());
            return;
        }

        var creds = new String(Base64.getDecoder()
             .decode(header.substring(6)))
             .split(":", 2);
        if (creds.length != 2
            || !authService.authenticate(creds[0], creds[1])) {
            ctx.abortWith(Response.status(Response.Status.UNAUTHORIZED).build());
            return;
        }
    }
}
