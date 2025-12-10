package org.taller.moduloDeTransferencia.dominio;
import java.util.ArrayList;
import java.util.List;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Entity
@Table(name = "CUENTA_BANCO_COMERCIO")
public class CuentaBancoComercio {
    @Id
    private int nroCuenta;

    @Column(name = "rut_comercio")
    private String rutComercio; // Usás solo el RUT, no el objeto `Comercio`
    
    @OneToMany(mappedBy = "cuenta", cascade = CascadeType.ALL, orphanRemoval = true)
    private List<Deposito> listaDepositos = new ArrayList<>(); // Lista de depósitos asociados a la cuenta
    
    public void addDeposito(Deposito deposito) {
        this.listaDepositos.add(deposito);
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof CuentaBancoComercio)) return false;
        CuentaBancoComercio other = (CuentaBancoComercio) o;
        return nroCuenta == other.nroCuenta;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(nroCuenta);
    }
}
