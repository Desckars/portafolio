package org.taller.moduloDeCompra.dominio;
import java.time.LocalDate;
import jakarta.json.bind.annotation.JsonbProperty;
import jakarta.persistence.Embeddable;
import lombok.Data;
@Data

@Embeddable
public class DataFecha {
    @JsonbProperty("dia")
    public int dia;

    @JsonbProperty("mes")
    public int mes;

    @JsonbProperty("anio")
    public int anio;

    
    public DataFecha() {
    }

    public DataFecha(int dia, int mes, int anio) {
        this.dia = dia;
        this.mes = mes;
        this.anio = anio;
    }

    public static DataFecha hoy() {
        LocalDate ahora = LocalDate.now();
        DataFecha fecha = new DataFecha();
        fecha.dia = ahora.getDayOfMonth();
        fecha.mes = ahora.getMonthValue();
        fecha.anio = ahora.getYear();
        return fecha;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof DataFecha)) return false;
        DataFecha f = (DataFecha) o;
        return this.dia == f.dia && this.mes == f.mes && this.anio == f.anio;
    }
    @Override
    public int hashCode() {
        int result = Integer.hashCode(dia);
        result = 31 * result + Integer.hashCode(mes);
        result = 31 * result + Integer.hashCode(anio);
        return result;
    }
}
