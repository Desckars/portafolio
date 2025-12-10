package org.taller.moduloDeTransferencia.dominio.repositorio;

import org.taller.moduloDeTransferencia.dominio.CuentaBancoComercio;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.persistence.EntityManager;
import jakarta.persistence.NoResultException;
import jakarta.persistence.PersistenceContext;
import jakarta.transaction.Transactional;

@ApplicationScoped
public class cuentaRepo {

    @PersistenceContext
    private EntityManager em;

    @Transactional
    public void guardar(CuentaBancoComercio cuenta) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando persistir cuenta...");
        }

        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            em.persist(cuenta);
            tx.commit();
            System.out.println("[INFO] Persist ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }
    public CuentaBancoComercio buscarPorRut(String rut) {
         try {
            return em.createQuery("SELECT c FROM CuentaBancoComercio c WHERE c.rutComercio = :rut", CuentaBancoComercio.class)
                    .setParameter("rut", rut)
                    .getSingleResult();
        } catch (NoResultException e) {
            return null;
        }
    }   
    @Transactional
    public void Actualizar(CuentaBancoComercio cuenta) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        } else {
            System.out.println("[INFO] EntityManager OK, intentando actualizar cuenta...");
        }

        jakarta.persistence.EntityTransaction tx = em.getTransaction();
        try {
            tx.begin();
            em.merge(cuenta);
            tx.commit();
            System.out.println("[INFO] Merge ejecutado y commit realizado");
        } catch (Exception e) {
            if (tx.isActive()) tx.rollback();
            throw e;
        }
    }
}

    