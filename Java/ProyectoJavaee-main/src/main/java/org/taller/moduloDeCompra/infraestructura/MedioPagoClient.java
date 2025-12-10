package org.taller.moduloDeCompra.infraestructura;

import jakarta.ws.rs.client.Client;
import jakarta.ws.rs.client.ClientBuilder;
import jakarta.ws.rs.client.Entity;
import jakarta.ws.rs.core.MediaType;
import jakarta.ws.rs.core.Response;

public class MedioPagoClient {
    /* 
    private static final String BASE_URL = "http://localhost:8080/ServicioMedioPagoMock/api/pagos";

    public PagoResponse procesarPago(PagoRequest request) {
        Client client = ClientBuilder.newClient();
        Response response = client.target(BASE_URL)
                .request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(request, MediaType.APPLICATION_JSON));

        if (response.getStatus() == 200) {
            return response.readEntity(PagoResponse.class);
        } else {
            throw new RuntimeException("Error al procesar el pago: " + response.getStatus());
        }
    }*/

    public PagoResponse procesarPago(PagoRequest request) {
        String BASE_URL = "http://localhost:8080/ServicioMedioPagoMock/api/pagos";
        Client client = ClientBuilder.newClient();
        try {//Se agrega try-finally para cerrar el cliente y evitar warnings
        Response response = client.target(BASE_URL)
                .request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(request, MediaType.APPLICATION_JSON));

        if (response.getStatus() == 200) {
            return response.readEntity(PagoResponse.class);
        } else {
            throw new RuntimeException("Error al procesar el pago: " + response.getStatus());
        }
            } finally {
            client.close();  // Esto evita el warning
        }
    }
    
    public void notificarDeposito(Integer idCompra, String rutComercio) {
        String BASE_URL = "http://localhost:8080/ServicioMedioPagoMock/api/notificarDeposito";

        DepositoRequest request = new DepositoRequest(idCompra, rutComercio);

        Client client = ClientBuilder.newClient();
        try {//Se agrega try-finally para cerrar el cliente y evitar warnings
        Response response = client.target(BASE_URL)
                .request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(request, MediaType.APPLICATION_JSON));

        if (response.getStatus() == 200) {
            System.out.println("✅ Notificación enviada correctamente al mock.");
        } else {
            throw new RuntimeException("Error al notificar al mock: " + response.getStatus());
        }
        } finally {
        client.close();  // 👈 Esto evita el warning
    }
    }

}