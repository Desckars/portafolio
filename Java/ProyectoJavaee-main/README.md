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
- Servidor Java EE (WildFly, Payara, GlassFish, etc.)

## Ejemplo de ejecución

Compila el proyecto desde la raíz:

```sh
mvn clean install
```

Despliega el archivo WAR generado en tu servidor Java EE.

## Créditos

Desarrollado como parte del Proyecto JavaEE - Taller de Programación.

---

Para más detalles sobre endpoints y ejemplos de uso, consulta la documentación de la API REST en el módulo.
