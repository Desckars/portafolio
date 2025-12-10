package org.taller.moduloDeComercio.dominio;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
@Entity
public class ReclamoComercio {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int idReclamo;

    private String descripcionReclamo;

    private String etiquetaString;

    private String rutComercio;

    public ReclamoComercio() {
        // Constructor por defecto requerido por JPA
    }
    public ReclamoComercio( String descripcionReclamo, String rutComercio) {
        // Constructor para crear un reclamo con descripción y comercio
        this.descripcionReclamo = descripcionReclamo;
        this.rutComercio = rutComercio;
        this.etiquetaString = "NEUTRO";
    }
    public int getIdReclamo() {
        return idReclamo;
    }
    public void setIdReclamo(int idReclamo) {
        this.idReclamo = idReclamo;
    }
    public String getDescripcionReclamo() {
        return descripcionReclamo;
    }
    public void setDescripcionReclamo(String descripcionReclamo) {
        this.descripcionReclamo = descripcionReclamo;
    }
    public String getRutComercio() {
        return rutComercio;
    }
    public void setRutComercio(String rutComercio) {
        this.rutComercio = rutComercio;
    }
    public String getEtiqueta() {
        return etiquetaString;
    }
    public void setEtiqueta(String etiqueta) {
        this.etiquetaString = etiqueta;
    }
}
