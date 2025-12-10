package org.taller.moduloDeTransferencia.interfase.remota;

import jakarta.ws.rs.ApplicationPath;
import jakarta.ws.rs.core.Application;

@ApplicationPath("/remota")  //este es el prefijo de mis endpoints
public class TransferenciaApplication extends Application {
    // En teoría no necesita nada más, pero puedes agregar configuraciones adicionales si es necesario.
    
}
