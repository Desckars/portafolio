package org.taller.moduloDeMonitoreo.infraestructura.eventos;

import org.taller.moduloDeMonitoreo.dominio.eventos.Evento;
import org.taller.moduloDeMonitoreo.interface_.observador.ObservadorDeEventos;

import java.util.ArrayList;
import java.util.List;

public class BusDeEventos {

    private final List<ObservadorDeEventos> observadores = new ArrayList<>();

    public void registrar(ObservadorDeEventos observador) {
        observadores.add(observador);
    }

    public void publicar(Evento evento) {
        for (ObservadorDeEventos obs : observadores) {
            System.out.println("Publicando evento a observador: " + evento.tipo());
            obs.manejar(evento);
        }
    }

}
