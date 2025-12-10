package org.taller.moduloDeTransferencia.dominio.repositorio;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.taller.moduloDeTransferencia.dominio.DataFecha;
import org.taller.moduloDeTransferencia.dominio.Deposito;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.persistence.EntityManager;
import jakarta.persistence.NoResultException;
import jakarta.persistence.PersistenceContext;
import jakarta.transaction.Transactional;


@ApplicationScoped
public class depositoRepo {


    @PersistenceContext
    private EntityManager em;

    @Transactional
    public void guardar(Deposito deposito) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando persistir cuenta...");
        }

        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            em.persist(deposito);
            tx.commit();
            System.out.println("[INFO] Persist ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }

    public boolean existe(int idCompra) {
        try {
        em.createQuery("SELECT c FROM Deposito c WHERE c.idCompra = :idCompra", Deposito.class)
          .setParameter("idCompra", idCompra)
          .getSingleResult();
        return true;  // Si llegó acá, existe
        } catch (NoResultException e) {
            return false; // No encontró resultado
        }
    }  

    public List<Deposito> buscarPorRangoDeFecha(List<Deposito> depositos, DataFecha fechaIni, DataFecha fechaEnd) {
        List<Deposito> filtrados = new ArrayList<>();
        for (Deposito d : depositos) {
            DataFecha f = d.getFecha();
            if (f != null && esFechaEnRango(f, fechaIni, fechaEnd)) {
                filtrados.add(d);
            }
        }
        return filtrados;
    }

    private boolean esFechaEnRango(DataFecha f, DataFecha ini, DataFecha fin) {
        LocalDate fecha = LocalDate.of(f.getAnio(), f.getMes(), f.getDia());
        LocalDate desde = LocalDate.of(ini.getAnio(), ini.getMes(), ini.getDia());
        LocalDate hasta = LocalDate.of(fin.getAnio(), fin.getMes(), fin.getDia());
        return (fecha.isEqual(desde) || fecha.isAfter(desde)) &&
            (fecha.isEqual(hasta) || fecha.isBefore(hasta));
    }
}
