package org.taller.moduloDeComercio.infraestructura.persistencia;

import jakarta.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "COMERCIO")
public class ComercioMap {

    @Id
    private String rutComercio;

    private String nombreComercio;
    private String direccionComercio;
    private String telefonoComercio;
    private String mailComercio;
    private String contraComercio;

    @OneToMany(mappedBy = "comercio", cascade = CascadeType.ALL, orphanRemoval = true)
    private List<POSMap> listaPOS = new ArrayList<>();

    public ComercioMap() {}

    public ComercioMap(String rut, String nombre, String direccion, String telefono, String mail, String contra) {
        this.rutComercio = rut;
        this.nombreComercio = nombre;
        this.direccionComercio = direccion;
        this.telefonoComercio = telefono;
        this.mailComercio = mail;
        this.contraComercio = contra;
    }

    public String getRut() {
        return rutComercio;
    }

    public void setRut(String rut) {
        this.rutComercio = rut;
    }

    public String getNombreComercio() {
        return nombreComercio;
    }

    public void setNombreComercio(String nombre) {
        this.nombreComercio = nombre;
    }

    public String getDireccionComercio() {
        return direccionComercio;
    }

    public void setDireccionComercio(String direccion) {
        this.direccionComercio = direccion;
    }

    public String getTelefonoComercio() {
        return telefonoComercio;
    }

    public void setTelefonoComercio(String telefono) {
        this.telefonoComercio = telefono;
    }

    public String getMailComercio() {
        return mailComercio;
    }

    public void setMailComercio(String mail) {
        this.mailComercio = mail;
    }

    public String getContraComercio() {
        return contraComercio;
    }

    public void setContraComercio(String contra) {
        this.contraComercio = contra;
    }

    public List<POSMap> getPos() {
        return listaPOS;
    }

    public void setPos(List<POSMap> pos) {
        this.listaPOS = pos;
    }

    public void agregarPOS(POSMap pos) {
        this.listaPOS.add(pos);
        pos.setComercio(this);
    }

    public POSMap buscarPOSPorId(int id) {
        for (POSMap pos : listaPOS) {
            if (pos.getIdPOS() == id) return pos;
        }
        return null;
    }
}