package org.taller.moduloDeComercio.repositorio;


import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import jakarta.persistence.TypedQuery;
import jakarta.transaction.Transactional;

import org.taller.moduloDeComercio.dominio.Comercio;

import java.util.List;
import jakarta.enterprise.context.ApplicationScoped;

@ApplicationScoped
public class RepositorioComercio {

    @PersistenceContext
    private EntityManager em;

    @Transactional
    public void guardar(Comercio comercio) {
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
            em.persist(comercio);
            tx.commit();
            System.out.println("[INFO] Persist ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }

    }
    @Transactional
    public void actualizar(Comercio comercio) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando actualizar comercio...");
        }

        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            em.merge(comercio);
            tx.commit();
            System.out.println("[INFO] Comercio actualizado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }

    public Comercio obtener(int id) {
        return em.find(Comercio.class, id);
    }

    public boolean existe(String id) {
        return em.find(Comercio.class, id) != null;
    }

    public Comercio obtenerPorRut(String rut) {
        TypedQuery<Comercio> query = em.createQuery(
            "SELECT c FROM Comercio c WHERE c.rutComercio = :rut", Comercio.class);
        query.setParameter("rut", rut);

        List<Comercio> resultados = query.getResultList();
        return resultados.isEmpty() ? null : resultados.get(0);
    }

    @Transactional
    public void eliminar(int id) {
         if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando eliminar comercio...");
        }

        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            Comercio comercio = em.find(Comercio.class, id);
            if (comercio != null) {
                em.remove(comercio);
                System.out.println("[INFO] Comercio eliminado");
            } else {
                System.out.println("[INFO] Comercio no encontrado para eliminar");
            }
            tx.commit();
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }
}
