package org.taller.moduloDeComercio.interfase.remota;

import jakarta.ws.rs.ApplicationPath;
import jakarta.ws.rs.core.Application;

@ApplicationPath("/remota")  //este es el prefijo de mis endpoints
public class ComercioApplication extends Application {
    //en teoria no necesita nada mas
}
