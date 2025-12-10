package org.taller.moduloDeTransferencia.interfase.remota.rest;
import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@AllArgsConstructor
@NoArgsConstructor
@Data
public class FiltroDepositosDTO {
    private int dia;
    private int mes;
    private int anio;
}
