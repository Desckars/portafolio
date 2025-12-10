package org.taller.moduloDeCompra.dominio;
import jakarta.json.bind.annotation.JsonbProperty;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
@Data
@AllArgsConstructor
@NoArgsConstructor

@Entity
@Table(name = "TARJETA")
public class DataTarjeta implements java.io.Serializable {
    //No es obligatorio, pero es buena práctica definirlo para evitar advertencias y problemas si cambias la clase en el futuro.
    private static final long serialVersionUID = 1L;//dentificador de versión para la clase serializable.
   
    @Id
    @JsonbProperty("nro")
    public String nro;

    @JsonbProperty("marca")
    public String marca;

    @JsonbProperty("fechaVto")
    public DataFecha fechaVto;

}
