package org.taller.moduloDeTransferencia.interfase.evento.in;
import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;

import java.util.ArrayList;
import java.util.logging.Logger;

import org.taller.moduloDeComercio.interfase.eventos.ListenerEventosComercio;
import org.taller.moduloDeTransferencia.dominio.CuentaBancoComercio;
import org.taller.moduloDeTransferencia.dominio.repositorio.comercioRepo;
import org.taller.moduloDeTransferencia.dominio.repositorio.cuentaRepo;

@ApplicationScoped
public class ObservadorDeEventos implements ListenerEventosComercio {
    private static final Logger log = Logger.getLogger(ObservadorDeEventos.class.getName());

    @Inject
    comercioRepo repo;
    @Inject
    cuentaRepo repo2;

    @Override
    public void alCrearComercio(org.taller.moduloDeComercio.dominio.Comercio comercio) {
        log.info("Listener recibido: alCrearComercio - " + comercio.getNombreComercio());

        // Crear una nueva cuenta bancaria con número único (ejemplo sencillo)
        CuentaBancoComercio cuenta = new CuentaBancoComercio();
       // Crear cuenta bancaria con número aleatorio de 5 dígitos
        int nroCuenta = 10000 + (int)(Math.random() * 90000);

        cuenta.setNroCuenta(nroCuenta);
        cuenta.setRutComercio(comercio.getRut()); // Asociar el RUT del comercio a la cuenta
        cuenta.setListaDepositos(new ArrayList<>());

        repo2.guardar(cuenta);
        System.out.println("Cuenta bancaria creada para el comercio: " + comercio.getNombreComercio() + " con número: " + nroCuenta);
    }
    @Override
    public void alModificarComercio(org.taller.moduloDeComercio.dominio.Comercio comercio) {
        // No hacer nada (por ahora)
    }

    @Override
    public void alRecibirReclamo(String rut, String mensaje) {
        // No hacer nada (por ahora)
    }

    @Override
    public void alCambiarContrasenia(org.taller.moduloDeComercio.dominio.Comercio comercio) {
        // No hacer nada (por ahora)
    }
}
