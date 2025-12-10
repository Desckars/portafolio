package org.taller.moduloDeMonitoreo.interface_.observador;

import org.taller.moduloDeMonitoreo.dominio.eventos.Evento;

public interface ObservadorDeEventos {
    void manejar(Evento evento);
}
