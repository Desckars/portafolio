package BD;
//Este código es para crear las tablas en la base de datos usando JPA y EclipseLink.
//Actualmente esto no sirve ya que el archivo beans.xml se encarga de crear las tablas
//pero lo dejo por si en un futuro se quiere usar este código para crear las tablas manualmente.
//import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;

public class TestCrearTablas {
     public static void main(String[] args) {
        // Crea el EntityManagerFactory con la unidad de persistencia
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("miUnidadPersistencia");

        // Cierra el factory (esto es suficiente para que EclipseLink cree las tablas)
        emf.close();

        System.out.println("✅ Tablas creadas en la base de datos (si no hubo errores).");
    }
}
