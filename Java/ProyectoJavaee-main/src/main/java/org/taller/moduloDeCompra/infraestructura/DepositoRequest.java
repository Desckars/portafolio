package org.taller.moduloDeCompra.infraestructura;

public class DepositoRequest {
    public int idCompra;
    public String rutComercio;

    public DepositoRequest(int idCompra, String rutComercio) {
        this.idCompra = idCompra;
        this.rutComercio = rutComercio;
    }
}
