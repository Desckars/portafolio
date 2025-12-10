package org.taller.moduloDeComercio.interfase.eventos; //ya entendi por que el profesor lo tenia con s, 
//"interface" es una palabra reservada

import org.taller.moduloDeComercio.dominio.Comercio;

public interface ListenerEventosComercio {
    void alCrearComercio(Comercio comercio);
    void alModificarComercio(Comercio comercio);
    void alCambiarContrasenia(Comercio comercio);
    void alRecibirReclamo(String idComercio, String textoReclamo);
}
