package org.taller.moduloDeTransferencia.dominio;

import jakarta.json.bind.annotation.JsonbTransient;
import jakarta.persistence.Embedded;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor

@Entity
@Table(name = "DEPOSITO")
public class Deposito {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    float importe;
    
    @Embedded
    private DataFecha fecha;

    private int idCompra;       // Identificador de la compra
    
    @ManyToOne
    @JoinColumn(name = "cuenta")
    @JsonbTransient
    private CuentaBancoComercio cuenta;

    public Deposito(float importe, DataFecha fecha, int idCompra, CuentaBancoComercio Cuenta) {
        this.importe = importe;
        this.fecha = fecha;
        this.idCompra = idCompra;
        this.cuenta = Cuenta;
    }
}
