package org.taller.moduloDeComercio.repositorio;

import java.util.HashMap;
import java.util.Map;

import org.taller.moduloDeComercio.dominio.POS;

import jakarta.persistence.*;

import jakarta.transaction.Transactional;
import jakarta.enterprise.context.ApplicationScoped;

@ApplicationScoped
public class RepositorioPOS {
    private Map<Integer, POS> posMap = new HashMap<>();

    @PersistenceContext
    private EntityManager em;

    @Transactional
    public void guardar(POS pos) {
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
            em.persist(pos);
            tx.commit();
            System.out.println("[INFO] Persist ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }
    
    @Transactional
    public void actualizar(POS pos) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando actualizar comercio...");
        }

        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            em.merge(pos);
            tx.commit();
            System.out.println("[INFO] Comercio actualizado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }
    
    @Transactional
    public POS buscarPorIdYComercio(int idPos, String rutComercio) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando buscar POS...");
        }

        try {
            return em.createQuery(
                "SELECT p FROM POS p WHERE p.idPOS = :idPos AND p.comercio.rutComercio = :rutComercio", POS.class)
                .setParameter("idPos", idPos)
                .setParameter("rutComercio", rutComercio)
                .getSingleResult();
        } catch (jakarta.persistence.NoResultException e) {
            System.out.println("[INFO] POS no encontrado para idPOS=" + idPos + " y rutComercio=" + rutComercio);
            return null;
        } catch (Exception e) {
            System.out.println("[ERROR] Error buscando POS: " + e.getMessage());
            throw e;
        }
    }

    public POS obtener(int id) {
        return posMap.get(id);
    }

    public void eliminar(int id) {
        posMap.remove(id);
    }

    public boolean existe(int id) {
        return posMap.containsKey(id);
    }

    public Map<Integer, POS> obtenerTodos() {
        return posMap;
    }
}
