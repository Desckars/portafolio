package org.taller.moduloDeMonitoreo.aplicacion;

import org.taller.moduloDeMonitoreo.dominio.eventos.Evento;
import org.taller.moduloDeMonitoreo.interface_.observador.ObservadorDeEventos;
import org.taller.moduloDeMonitoreo.repositorio.RepositorioEventos;

public class ObservadorMonitoreo implements ObservadorDeEventos {

    private final RepositorioEventos repositorio;

    public ObservadorMonitoreo(RepositorioEventos repositorio) {
        this.repositorio = repositorio;
    }

    @Override
    public void manejar(Evento evento) {
        System.out.println("ObservadorMonitoreo recibió: " + evento.tipo());
        repositorio.guardarEvento(evento.tipo(), evento.mensaje());
    }

}
