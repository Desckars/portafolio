package org.taller.moduloDeComercio.aplicacion;

import java.util.List;

import org.taller.moduloDeComercio.dominio.DatosComercio;
import org.taller.moduloDeComercio.dominio.POS;

public interface InterfaceModuloComercio {
    //permite registrar un comercio en el sistema
    abstract void altaComercio(DatosComercio datos);

    //permite modificar información relacionada al comercio.
    abstract void modificarDatosComercio(DatosComercio datos);

    //registra un nuevo POS en el sistema
    abstract void altaPos(String rutComercio);

    //permite habilitar o deshabilitar un POS
    abstract void cambiarEstadoPos(String rutComercio,int idPos, boolean habilitado);

    //cambia contraseña del comercio. La contraseña se utilizará 
    //para poder invocar a la API remota que ofrece información de ventas (a
    //desarrollar en siguiente iteración)
    abstract void cambioContrasenia(String rutComercio, String nuevaContrasenia);

    //recibe un reclamo del comercio, el cual deberá ser atendido por el departamento de Soporte.
    abstract void realizarReclamo(String rutComercio, String textoReclamo);
    
    //devuelve una lista de POS asociados a un comercio
    abstract List<POS> listarPOS(String rutComercio);
}
