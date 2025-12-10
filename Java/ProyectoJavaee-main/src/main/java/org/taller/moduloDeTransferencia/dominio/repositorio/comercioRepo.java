package org.taller.moduloDeTransferencia.dominio.repositorio;
import java.util.ArrayList;
import java.util.List;
import org.taller.moduloDeTransferencia.dominio.Comercio;

public class comercioRepo {
     private List<Comercio> comercios = new ArrayList<>();

    public Comercio guardar(Comercio comercio) {
        comercios.add(comercio);
        return comercio;
    }

    public List<Comercio> listarTodos() {
        return new ArrayList<>(comercios); // Copia defensiva
    }

   public Comercio buscarPorRut(String rut) {
    return comercios.stream()
            .filter(c -> c.getRut().equals(rut))
            .findFirst()
            .orElse(null);
    }

}