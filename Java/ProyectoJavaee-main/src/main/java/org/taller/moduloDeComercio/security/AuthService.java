package org.taller.moduloDeComercio.security;

import org.mindrot.jbcrypt.BCrypt;
import org.taller.moduloDeComercio.dominio.Comercio;
import org.taller.moduloDeComercio.repositorio.RepositorioComercio;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.inject.Inject;

@ApplicationScoped
public class AuthService {

    @Inject
    private RepositorioComercio repo;

    //retorna true si existe un Comercio con ese rut y la contraseña coincide.
    public boolean authenticate(String rut, String plainPassword) {
        Comercio c = repo.obtenerPorRut(rut);
        if (c == null) {
            return false;
        }
        // c.getContraComercio() es el hash Bcrypt que se almacenó al crear el comercio
        return BCrypt.checkpw(plainPassword, c.getContraComercio());
    }
}
