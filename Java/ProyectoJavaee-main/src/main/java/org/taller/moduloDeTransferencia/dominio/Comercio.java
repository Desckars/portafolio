package org.taller.moduloDeTransferencia.dominio;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Entity
@Table(name = "TRANSFERENCIA_COMERCIO")
public class Comercio {
     @Id
     private String rut;
     @OneToOne(mappedBy = "comercio", cascade = CascadeType.ALL)
     private CuentaBancoComercio cuentaBancoComercio; // Cuenta bancaria asociada al comercio  
    
}
//A borrar la clase