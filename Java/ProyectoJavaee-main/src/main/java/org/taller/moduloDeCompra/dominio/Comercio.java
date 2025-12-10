package org.taller.moduloDeCompra.dominio;

import java.util.ArrayList;
import java.util.List;

public class Comercio {

    private Integer rut;
    private String direccion;
    private Integer telefono;
    private String mail;
    private List<DataCompra> compras = new ArrayList<>();

    public Comercio() {}

    public Comercio(Integer rut) {
        this.rut = rut;
    }

    public Comercio(Integer rut, String direccion, Integer telefono, String mail) {
        this.rut = rut;
        this.direccion = direccion;
        this.telefono = telefono;
        this.mail = mail;
    }

    // Getters y setters

    public Integer getRut() {
        return rut;
    }

    public void setRut(Integer rut) {
        this.rut = rut;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public Integer getTelefono() {
        return telefono;
    }

    public void setTelefono(Integer telefono) {
        this.telefono = telefono;
    }

    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public List<DataCompra> getCompras() {
        return compras;
    }

    public void addCompra(DataCompra compra) {
        this.compras.add(compra);
    }
}
