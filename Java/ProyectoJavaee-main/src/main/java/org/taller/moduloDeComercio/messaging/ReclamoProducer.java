package org.taller.moduloDeComercio.messaging;

import jakarta.annotation.Resource;
import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;
import jakarta.jms.JMSContext;
import jakarta.jms.Queue;

@ApplicationScoped
public class ReclamoProducer {

    @Resource(lookup = "java:/jms/queue/ReclamosQueue")
    private Queue reclamosQueue;

    @Inject
    private JMSContext jmsContext;

    public void enviarReclamo(String idComercio, String textoReclamo) {
        try {
            // Construir JSON manualmente (y escapar comillas del texto)
            String mensajeJson = "{"
                    + "\"rutComercio\":\"" + idComercio + "\","
                    + "\"textoReclamo\":\"" + textoReclamo.replace("\"", "\\\"") + "\""
                    + "}";

            jmsContext.createProducer().send(reclamosQueue, mensajeJson);
            System.out.println("Reclamo enviado a la queue: " + mensajeJson);
        } catch (Exception e) {
            System.err.println("Error al enviar el reclamo: " + e.getMessage());
        }
    }
}
