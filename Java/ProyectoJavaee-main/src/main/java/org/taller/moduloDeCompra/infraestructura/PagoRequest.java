package org.taller.moduloDeCompra.infraestructura;

public class PagoRequest {
    public String numeroTarjeta;
    public double monto;

    public PagoRequest(String numeroTarjeta, double monto) {
        this.numeroTarjeta = numeroTarjeta;
        this.monto = monto;
    }
}