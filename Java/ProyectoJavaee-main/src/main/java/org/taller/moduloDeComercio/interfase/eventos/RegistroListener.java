package org.taller.moduloDeComercio.interfase.eventos;

import jakarta.annotation.PostConstruct;
import jakarta.ejb.Singleton;
import jakarta.ejb.Startup;
import jakarta.inject.Inject;

import org.taller.moduloDeComercio.aplicacion.implementation.ImplModuloComercio;
import org.taller.moduloDeTransferencia.interfase.evento.in.ObservadorDeEventos;

@Singleton
@Startup
public class RegistroListener {
    @Inject
    ImplModuloComercio servicioComercio;

    @Inject
    ObservadorDeEventos observador;

    @PostConstruct
    public void init() {
        System.out.println(">>> RegistroListener iniciado<<<");
        servicioComercio.registrarListener(observador);
    }
}
