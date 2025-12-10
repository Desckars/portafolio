package org.taller.moduloDeComercio.infraestructura.persistencia;

import jakarta.persistence.*;

@Entity
@Table(name = "POS")
public class POSMap {

    @Id
    private int idPOS;

    @ManyToOne
    @JoinColumn(name = "Comercio_id")
    private ComercioMap comercio;

    private boolean habilitadoPOS;

    public POSMap() {}

    public POSMap(int id, ComercioMap comercio) {
        this.idPOS = id;
        this.comercio = comercio;
        this.habilitadoPOS = false;
    }

    public int getIdPOS() {
        return idPOS;
    }

    public ComercioMap getComercio() {
        return comercio;
    }

    public boolean getHabilitadoPOS() {
        return habilitadoPOS;
    }

    public void setIdPOS(int id) {
        this.idPOS = id;
    }

    public void setComercio(ComercioMap comercio) {
        this.comercio = comercio;
    }

    public void setHabilitadoPOS(boolean habilitado) {
        this.habilitadoPOS = habilitado;
    }
}