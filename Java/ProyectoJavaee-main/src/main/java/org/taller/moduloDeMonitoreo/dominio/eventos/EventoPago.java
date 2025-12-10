package org.taller.moduloDeMonitoreo.dominio.eventos;

public class EventoPago implements Evento {
    private final String tipo;
    private final String mensaje;

    public EventoPago(String tipo, String mensaje) {
        this.tipo = tipo;
        this.mensaje = mensaje;
    }

    @Override
    public String tipo() {
        return tipo;
    }

    @Override
    public String mensaje() {
        return mensaje;
    }
}
