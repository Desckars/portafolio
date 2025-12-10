package org.taller.moduloDeTransferencia.interfase.remota.rest;
import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@AllArgsConstructor
@NoArgsConstructor
@Data
public class NotificacionDepositoDTO {
    private int idCompra;
    private String rutComercio;
}
