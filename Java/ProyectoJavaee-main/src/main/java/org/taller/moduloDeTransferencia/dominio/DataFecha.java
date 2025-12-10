package org.taller.moduloDeTransferencia.dominio;

import java.io.Serializable;
import java.time.LocalDate;

import jakarta.persistence.Embeddable;
@Embeddable
public class DataFecha implements Serializable{
    private int dia;
    private int mes;
    private int anio;

    public DataFecha() {
    }

    public DataFecha(int dia, int mes, int anio) {
        this.dia = dia;
        this.mes = mes;
        this.anio = anio;
    }
    public static DataFecha now() {
        LocalDate hoy = LocalDate.now();
        return new DataFecha(hoy.getDayOfMonth(), hoy.getMonthValue(), hoy.getYear());
    }

    @Override
    public boolean equals(Object o) {//El método recibe un objeto cualquiera (o) 
        if (this == o) return true;//Si el objeto que llega es exactamente el mismo que este (this), entonces claramente son iguales.
        if (o == null || getClass() != o.getClass()) return false;//Si el objeto o es nulo o no es de la misma clase que este, entonces no son iguales.
        DataFecha that = (DataFecha) o;//Hace un cast seguro del objeto o a tipo DataFecha, ya que pasó la validación anterior.
        return dia == that.dia && mes == that.mes && anio == that.anio;//Compara los atributos dia, mes y anio de ambos objetos. Si son iguales, devuelve true.
    }

    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getAnio() {
        return anio;
    }

    public void setAnio(int anio) {
        this.anio = anio;
    }
}
