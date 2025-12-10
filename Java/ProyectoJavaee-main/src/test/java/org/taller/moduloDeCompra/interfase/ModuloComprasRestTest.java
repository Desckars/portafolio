package org.taller.moduloDeCompra.interfase;

import static io.restassured.RestAssured.given;
import static org.hamcrest.Matchers.equalTo;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

import io.restassured.RestAssured;
import io.restassured.http.ContentType;

@Disabled
public class ModuloComprasRestTest {

    
    @Test
    public void testProcesarPago() {
        RestAssured.baseURI = "http://localhost:8080/ProyectoJavaee/api/compras";

        String requestBody = """
        {
          "id": 1,
          "importe": 1000.0,
          "fecha": { "dia": 21, "mes": 5, "anio": 2025 },
          "desc": "Pago de producto",
          "tarjeta": {
              "nro": "1234567890123456",
              "marca": "VISA"
          }
        }
        """;

        given()
            .contentType(ContentType.JSON)
            .body(requestBody)
        .when()
            .post("/procesar-pago")
        .then()
            .statusCode(200)
            .body("estado", equalTo("Pago procesado"));
    }
}