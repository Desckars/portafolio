package org.taller.moduloDeCompra.dominio;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
@Data
@AllArgsConstructor
@NoArgsConstructor

public class DataComercio {

    Integer id;
    String desc;
    float importe;

    DataComercio(Integer rut,String direccion,Integer telefono,String mail){}
}
