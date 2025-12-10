package org.taller.moduloDeMonitoreo.repositorio;

public interface RepositorioEventos {
    void guardarEvento(String tipo, String mensaje);
}
