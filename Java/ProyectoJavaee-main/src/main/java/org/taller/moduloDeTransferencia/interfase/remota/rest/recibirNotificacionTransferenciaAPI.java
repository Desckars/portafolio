package org.taller.moduloDeTransferencia.interfase.remota.rest;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;
import jakarta.ws.rs.*;
import jakarta.ws.rs.core.MediaType;
import jakarta.ws.rs.core.Response;

import java.time.format.DateTimeParseException;
import java.util.List;

import org.taller.moduloDeTransferencia.aplicacion.servicioDeposito;
import org.taller.moduloDeTransferencia.dominio.Deposito;
import jakarta.annotation.security.PermitAll;

@ApplicationScoped
@Path("/transferencia")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class recibirNotificacionTransferenciaAPI {

    @Inject
    servicioDeposito SD;

    //curl -X POST http://localhost:8080/ProyectoJavaee/remota/transferencia/notificacion \
    //-H "Content-Type: application/json" \
    // -d '{"idCompra": 1, "rutComercio": 123}'
    @POST
    @PermitAll
    @Path("/notificacion")
    public Response recibirNotificacion(NotificacionDepositoDTO dto) {
        SD.realizarDeposito(dto.getIdCompra(), dto.getRutComercio());
        return Response.ok().build();
    }

    // curl -X GET http://localhost:8080/ProyectoJavaee/remota/transferencia/listar?rutComercio=123&fechaini=01-05-2025&fechaend=20-05-2025" \
    //-H "Content-Type: application/json" \
    @GET
    @Path("/listar")
    @Produces(MediaType.APPLICATION_JSON)
    public Response mostrarDepositosFiltrados(@QueryParam("rutComercio") String rutComercio,
                                            @QueryParam("fechaini") String fechaIni,
                                            @QueryParam("fechaend") String fechaEnd) {
        try {
            // Validación básica
            if (rutComercio == null || fechaIni == null || fechaEnd == null) {
                return Response.status(Response.Status.BAD_REQUEST)
                            .entity("❌ Faltan parámetros obligatorios.")
                            .build();
            }

            List<Deposito> depositos = SD.MostrarHistorialDeDepositos(rutComercio, fechaIni, fechaEnd);

            if (depositos.isEmpty()) {
                return Response.status(Response.Status.NOT_FOUND)
                            .entity("⚠️ No se encontraron depósitos para ese comercio y fecha.")
                            .build();
            }

            return Response.ok(depositos).build();

        } catch (DateTimeParseException e) {
            return Response.status(Response.Status.BAD_REQUEST)
                        .entity("❌ Formato de fecha inválido. Usa yyyy-MM-dd.")
                        .build();
        } catch (RuntimeException e) {
            return Response.status(Response.Status.INTERNAL_SERVER_ERROR)
                        .entity("❌ " + e.getMessage())
                        .build();
        }
    }
}