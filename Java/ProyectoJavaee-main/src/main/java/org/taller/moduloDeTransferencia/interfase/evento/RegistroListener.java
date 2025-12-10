package org.taller.moduloDeTransferencia.interfase.evento;

import jakarta.annotation.PostConstruct;
import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;

import org.taller.moduloDeComercio.aplicacion.implementation.ImplModuloComercio;
import org.taller.moduloDeTransferencia.interfase.evento.in.ObservadorDeEventos;
@ApplicationScoped
public class RegistroListener {
    @Inject
    ImplModuloComercio servicioComercio;

    @Inject
    ObservadorDeEventos observador;

    @PostConstruct
    public void init() {
        servicioComercio.registrarListener(observador);
    }
}
