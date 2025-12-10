package org.taller.moduloDeCompra.dominio;
import jakarta.json.bind.annotation.JsonbProperty;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
@Data
@AllArgsConstructor

@Entity
@Table(name = "COMPRA")
public class DataCompra {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @JsonbProperty("id")
    public Integer id;

    @JsonbProperty("importe")
    public float importe;

    @JsonbProperty("fecha")
    public DataFecha fecha;

    @JsonbProperty("descripcion")
    public String descripcion;

    @ManyToOne
    @JoinColumn(name = "tarjeta_nro")
    @JsonbProperty("tarjeta")
    public DataTarjeta tarjeta;

    @JsonbProperty("idPos")
    public Integer idPos;

    @JsonbProperty("rutComercio")
    public String rutComercio;

    public DataCompra(){
        this.importe=0;
        this.fecha=null;
        this.descripcion=null;
        this.tarjeta=null;
    }

    public Integer getId() {
        return id;
    }
    public void setId(Integer id) {
        this.id = id;
    }
    public float getImporte() {
        return importe;
    }
    public void setImporte(float importe) {
        this.importe = importe;
    }
    public DataFecha getFecha() {
        return fecha;
    }
    public void setFecha(DataFecha fecha) {
        this.fecha = fecha;
    }
    public DataTarjeta getTarjeta() {
        return tarjeta;
    }
    public void setTarjeta(DataTarjeta tarjeta) {
        this.tarjeta = tarjeta;
    }
    public String getRutComercio() {
        return rutComercio;
    }

    public void setRutComercio(String rutComercio) {
        this.rutComercio = rutComercio;
    }
    
}
