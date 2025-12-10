package org.taller.moduloDeComercio.aplicacion.implementation;

import java.util.ArrayList;
import java.util.List;

import org.taller.moduloDeComercio.aplicacion.InterfaceModuloComercio;
import org.taller.moduloDeComercio.dominio.Comercio;
import org.taller.moduloDeComercio.dominio.DatosComercio;
import org.taller.moduloDeComercio.dominio.POS;
import org.taller.moduloDeComercio.interfase.eventos.ListenerEventosComercio;
import org.taller.moduloDeComercio.interfase.eventos.RegistroListener;
import org.taller.moduloDeComercio.messaging.ReclamoProducer;
import org.taller.moduloDeComercio.repositorio.RepositorioComercio;
import org.taller.moduloDeComercio.repositorio.RepositorioPOS;
//import org.taller.moduloDeComercio.repositorio.RepositorioReclamoComercio;
import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;
import org.mindrot.jbcrypt.BCrypt;

@ApplicationScoped
public class ImplModuloComercio implements InterfaceModuloComercio {

    @Inject
    private RepositorioComercio repositorioComercio;

//    @Inject
//    private RepositorioReclamoComercio repositorioReclamoComercio;

    @Inject
    private RepositorioPOS repositorioPOS;

    @Inject
    private ReclamoProducer reclamoProducer;


    @Inject
    RegistroListener dummy;


    private final List<ListenerEventosComercio> listeners = new ArrayList<>();

    public void registrarListener(ListenerEventosComercio listener) {
        listeners.add(listener);
    }

    @Override
    public void altaComercio(DatosComercio datos) {
        //control de que no exista otro con la misma id, cambiar por la version de JPA
        if (repositorioComercio.existe(datos.getId())) {
            throw new RuntimeException("Comercio ya existe");
        }
        //Hash de contraseña
        String hash = BCrypt.hashpw(datos.getContraseniaHash(), BCrypt.gensalt());
        //crear objeto
        Comercio nuevo = new Comercio(
                datos.getId(),
                datos.getNombre(),
                datos.getDireccion(),
                datos.getTelefono(),
                datos.getEmail(),
                hash
        );
        //luego cambiar a subir a la base de datos con JPA
        System.out.println("Antes de persistir: " + nuevo.getRut());
        repositorioComercio.guardar(nuevo);
        System.out.println("Después de persistir");

        for (ListenerEventosComercio listener : listeners) {
            listener.alCrearComercio(nuevo);
        }
    }

    @Override
    public void modificarDatosComercio(DatosComercio datos) {
        //luego get con JPA
        Comercio comercio = repositorioComercio.obtenerPorRut(datos.getId());//Lo edite yo (enzo)
        //control de existencia (necesito que exista obviamente)
        if (comercio == null) throw new RuntimeException("No existe el comercio");

        //modificacion de datos, despues seria con jpa o una consulta SQL directa
        comercio.setNombreComercio(datos.getNombre());
        comercio.setDireccionComercio(datos.getDireccion());
        comercio.setTelefonoComercio(datos.getTelefono());
        comercio.setMailComercio(datos.getEmail());

        repositorioComercio.actualizar(comercio); 
        System.out.println("Después de Actualizar");

        for (ListenerEventosComercio listener : listeners) {
            listener.alModificarComercio(comercio);
        }
    }

    @Override
    public void altaPos(String rutComercio) {
        //luego get con JPA
        Comercio comercio = repositorioComercio.obtenerPorRut(rutComercio);//Lo edite yo (enzo)
        //mismo control que antes
        if (comercio == null) throw new RuntimeException("Comercio no encontrado");

        POS posNuevo = new POS(comercio);
        repositorioPOS.guardar(posNuevo); // Guardar el nuevo POS en la base de DatosComercio
        System.out.println("Después de crear POS");
        //agregar a la lista, deberia subir a la base de datos tambien
        comercio.agregarPOS(posNuevo);
    }

    @Override
    public void cambiarEstadoPos(String rutComercio, int idPos, boolean habilitado) {
        //get base de datos
        Comercio comercio = repositorioComercio.obtenerPorRut(rutComercio);//Lo edite yo (enzo)
        //control
        if (comercio == null) throw new RuntimeException("Comercio no encontrado");

        //buscar el POS en la lista del comercio
        POS pos = repositorioPOS.buscarPorIdYComercio(idPos, rutComercio);
        System.out.println("Despues de encontrar el POS: " + pos);
        //control de que exista el POS
        if (pos == null) throw new RuntimeException("POS no encontrado");
        //si existe, lo habilito 
        pos.setHabilitadoPOS(habilitado);

        repositorioPOS.actualizar(pos); // Actualizar el POS en la base de datos
        System.out.println("Después de Actualizar Estado POS");        
    }

    @Override
    public void cambioContrasenia(String idComercio, String nuevaContrasenia) {
        Comercio comercio = repositorioComercio.obtenerPorRut(idComercio);//Lo edite yo (enzo)
        if (comercio == null) throw new RuntimeException("Comercio no encontrado");
         String hash = BCrypt.hashpw(nuevaContrasenia, BCrypt.gensalt());
        comercio.setContraComercio(hash);
        repositorioComercio.actualizar(comercio); // Actualizar el comercio en la base de datos
        System.out.println("Después de cambiar contraseña del comercio");
        
        for (ListenerEventosComercio listener : listeners) {
            listener.alCambiarContrasenia(comercio);
        }
    }

    @Override
    public void realizarReclamo(String idComercio, String textoReclamo) {
        //ReclamoComercio reclamo = new ReclamoComercio(textoReclamo, idComercio);
        //repositorioReclamoComercio.guardarR(reclamo);
        // Comenté estas 2 lineas por el cambio a la queue, asi solo guarda cuando vuelven de la queue
        reclamoProducer.enviarReclamo(idComercio, textoReclamo); // ahora se manda el JSON correcto
        System.out.println("Reclamo recibido del comercio " + idComercio + ": " + textoReclamo);
    }

    @Override
    public List<POS> listarPOS(String rutComercio) {
        Comercio comercio = repositorioComercio.obtenerPorRut(rutComercio);//Lo edite yo (enzo)
        //control
        if (comercio == null) throw new RuntimeException("Comercio no encontrado");
        return comercio.getPos(); // Retorna la lista de POS del comercio
    }
}
