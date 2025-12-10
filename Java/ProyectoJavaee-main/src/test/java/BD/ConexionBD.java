package BD;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Connection;

public class ConexionBD {
    public Connection obtenerConexion() throws SQLException {
        String url = "jdbc:mysql://localhost:3306/TallerJava";
        String user = "root";
        String password = "";
        return DriverManager.getConnection(url, user, password);
    }
}
