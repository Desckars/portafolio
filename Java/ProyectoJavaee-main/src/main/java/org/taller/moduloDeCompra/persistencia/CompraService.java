package org.taller.moduloDeCompra.persistencia;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.stream.Collectors;

import org.taller.moduloDeCompra.dominio.DataCompra;
import org.taller.moduloDeCompra.dominio.DataFecha;
import jakarta.enterprise.context.ApplicationScoped;
import jakarta.persistence.*;
import jakarta.transaction.Transactional;

@ApplicationScoped
public class CompraService {

    @PersistenceContext
    private EntityManager em;

    @Transactional
    public void guardar(DataCompra compra) {
       if (em == null) {
        System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando persistir comercio...");
        }

        // Manejo manual de la transacción
        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            em.persist(compra);
            tx.commit();
            System.out.println("[INFO] Persist ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }

    }   
    public List<DataCompra> listarComprasPorRutComercio(String rutComercio) {
        TypedQuery<DataCompra> query = em.createQuery(
            "SELECT c FROM DataCompra c WHERE c.rutComercio = :rutComercio", DataCompra.class);
        query.setParameter("rutComercio", rutComercio);
        return query.getResultList();
        
    }

    /*ACA HECHO POR THIAGO
    private List<DataCompra> compras;

    public CompraService() {
        this.compras = List.of(); // o dejarlo nulo si luego lo vas a setear
    }

    public CompraService(List<DataCompra> compras) {
        this.compras = compras;
    }
    */
    //Modificado por Enzo
    public List<DataCompra> listarVentasPorPeriodo(String idComercio, String fechaIniStr, String fechaEndStr) {
        DataFecha fechaIni = parseFecha(fechaIniStr);
        DataFecha fechaEnd = parseFecha(fechaEndStr);
        List<DataCompra> compras = listarComprasPorRutComercio(idComercio);

            return compras.stream()
            .filter(c -> esFechaEnRango(c.getFecha(), fechaIni, fechaEnd))
            .collect(Collectors.toList());
    }

    private DataFecha parseFecha(String fechaStr) {
        // Acepta formato "dd-MM-yyyy"
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        LocalDate fecha = LocalDate.parse(fechaStr, formatter);
        return new DataFecha(fecha.getDayOfMonth(), fecha.getMonthValue(), fecha.getYear());
    }

    private boolean esFechaEnRango(DataFecha f, DataFecha ini, DataFecha fin) {
        LocalDate fecha = LocalDate.of(f.getAnio(), f.getMes(), f.getDia());
        LocalDate desde = LocalDate.of(ini.getAnio(), ini.getMes(), ini.getDia());
        LocalDate hasta = LocalDate.of(fin.getAnio(), fin.getMes(), fin.getDia());
        return (fecha.isEqual(desde) || fecha.isAfter(desde)) &&
            (fecha.isEqual(hasta) || fecha.isBefore(hasta));
    }
}
