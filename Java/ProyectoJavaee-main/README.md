(Proyecto ejecutado en Linux)
# Módulo de Comercio - Proyecto JavaEE

Este módulo es parte de un sistema distribuido para la gestión de comercios y puntos de venta (POS). Proporciona una API REST para administrar comercios, registrar y gestionar POS, realizar cambios de contraseña y registrar reclamos. (dentro)

## Funcionalidades principales

- Alta y modificación de comercios
- Registro y gestión de puntos de venta (POS)
- Gestión del estado de los POS
- Cambios de contraseña de usuarios
- Registro y consulta de reclamos

## Estructura

- **Dominio**: Clases principales como `Comercio`, `POS`, `ReclamoComercio`, `DatosComercio`
- **Aplicación**: Lógica de negocio y servicios (`InterfaceModuloComercio`)
- **Infraestructura**: Persistencia y comunicación con otros módulos
- **API REST**: Expuesta mediante Jakarta RESTful Web Services

## Uso

1. Despliega el módulo en un servidor Java EE compatible.
2. Accede a los endpoints REST para gestionar comercios y POS.
3. Utiliza los DTOs para enviar y recibir datos de forma desacoplada.

## Requisitos

- Java 8+
- Maven
- Servidor Java EE (WildFly)
- Docker
# Programas
Wildfly: Utilizado para levantar distintos servicios a la vez("BanoClienteMock", "EtiquetadoAPI" y "ServicioMedioPagoMock) utilizando los .war de los diversos proyectos.
Tener en "wildfly-***/standalone/deployments/" los siguientes archivos:
"BanoClienteMock.war"
"EtiquetadoAPI.war"
"ServicioMedioPagoMock.war"
"mysql-connector-**.jar"
(Los archivos anteriores estan la carpeta documentacion antes del proyecto raiz)


## Ejemplo de ejecución

Compila el proyecto desde la raíz:
mvn clean install

Ejecutar wildfly:
DESDE "wildfly.**/bin" ejecutar en terminal standalone.sh

Ejecutar Docker:
sudo docker start monitoreo

## Créditos

Desarrollado como parte del Proyecto JavaEE - Taller de Programación.

---
