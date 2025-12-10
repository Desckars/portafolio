package org.taller.moduloDeComercio.repositorio;
import jakarta.persistence.*;
import jakarta.transaction.Transactional;

import java.util.List;
import org.taller.moduloDeComercio.dominio.ReclamoComercio;

import jakarta.enterprise.context.ApplicationScoped;

@ApplicationScoped
public class RepositorioReclamoComercio {

    @PersistenceContext
    private EntityManager em;

    @Transactional
    public void guardarR(ReclamoComercio Reclamo) {
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
            em.persist(Reclamo);
            tx.commit();
            System.out.println("[INFO] Persist ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }

    }
    //Metodo generado para obtener un reclamo por su id
    public ReclamoComercio obtener(int id) {
        return em.find(ReclamoComercio.class, id);
    }
    //Metodo generado para verificar si un reclamo existe por su id
    public boolean existe(int id) {
        return em.find(ReclamoComercio.class, id) != null;
    }
    //Metodo generado para obtener un reclamo por el rut del comercio(Es lo que deveriamos usar para saber cuantos reclamos tiene tu comercio)
    public ReclamoComercio obtenerPorRutComercio(String rutComercio) {
        TypedQuery<ReclamoComercio> query = em.createQuery(
            "SELECT r FROM ReclamoComercio r WHERE r.rutComercio = :rut", ReclamoComercio.class);
        query.setParameter("rut", rutComercio);

        List<ReclamoComercio> resultados = query.getResultList();
        return resultados.isEmpty() ? null : resultados.get(0);
    }
}
