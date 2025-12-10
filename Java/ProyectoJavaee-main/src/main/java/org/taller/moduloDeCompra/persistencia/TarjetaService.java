package org.taller.moduloDeCompra.persistencia;

import org.taller.moduloDeCompra.dominio.DataTarjeta;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityTransaction;
import jakarta.persistence.PersistenceContext;
import jakarta.transaction.Transactional;

@ApplicationScoped
public class TarjetaService {
    @PersistenceContext
    private EntityManager em;

    @Transactional
    public DataTarjeta guardarSiNoExiste(DataTarjeta tarjeta) {
        if (em == null) {
            System.out.println("[ERROR] EntityManager es NULL");
            throw new IllegalStateException("EntityManager no fue inyectado correctamente.");
        }

        
    DataTarjeta existente = em.find(DataTarjeta.class, tarjeta.getNro());
        if (existente == null) {
            EntityTransaction tx = em.getTransaction();
            try {
                tx.begin();
                em.persist(tarjeta);
                //em.flush();
                tx.commit();
                System.out.println("[INFO] Tarjeta nueva persistida");
                return tarjeta;
            } catch (Exception e) {
                if (tx.isActive()) tx.rollback();
                throw e;
            }
        } else {
            System.out.println("[INFO] Tarjeta ya existe, no se persiste");
            return existente;
        }
    }
}
