package org.taller.moduloDeComercio.interfase.remota;

import java.util.ArrayList;
import java.util.List;

import org.taller.moduloDeComercio.dominio.Comercio;
import org.taller.moduloDeComercio.dominio.DatosComercio;
import org.taller.moduloDeComercio.dominio.POS;

public class ComercioDTO {
    //campos que mapean el dominio
    private String id;
    private String nombre;
    private String direccion;
    private String telefono;
    private String email;
    private String contraseniaHash;
    private List<POSDTO> listaPOS;

    public ComercioDTO() {}

    // getters / setters
    public String getId() { 
        return id; 
    }
    public void setId(String id) { 
        this.id = id; 
    }

    public String getNombre() { 
        return nombre; 
    }
    public void setNombre(String nombre) { 
        this.nombre = nombre; 
    }

    public String getDireccion() { 
        return direccion; 
    }
    public void setDireccion(String direccion) { 
        this.direccion = direccion; 
    }

    public String getTelefono() {
         return telefono; 
        }
    public void setTelefono(String telefono) {
         this.telefono = telefono; 
        }

    public String getEmail() {
         return email; 
        }
    public void setEmail(String email) { 
        this.email = email; 
    }

    public String getContraseniaHash() { 
        return contraseniaHash; 
    }
    public void setContraseniaHash(String contraseniaHash) { 
        this.contraseniaHash = contraseniaHash; 
    }

    public List<POSDTO> getListaPOS() { 
        return listaPOS; 
    }
    public void setListaPOS(List<POSDTO> listaPOS) { 
        this.listaPOS = listaPOS; 
    }

    //conversión a DatosComercio
    public DatosComercio toDatosComercio() {
        List<POS> lista = new ArrayList<>();
        Comercio comercio = new Comercio(id, nombre, direccion, telefono, email, contraseniaHash);

        if (listaPOS != null) {
            for (POSDTO posDto : listaPOS) {
                POS pos = new POS(comercio); // Usar el nombre del POS
                pos.setHabilitadoPOS(posDto.isHabilitadoPOS());
                lista.add(pos);
            }
        }

        return new DatosComercio(id, nombre, direccion, telefono, email, contraseniaHash, lista);
    }
}
