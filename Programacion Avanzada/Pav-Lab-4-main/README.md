# Sistema de Gestión de Cursos de Idiomas

Este proyecto es una aplicación en C++ para la gestión de cursos de idiomas. Permite administrar usuarios (estudiantes y profesores), cursos, lecciones, ejercicios, inscripciones y estadísticas.

## Funcionalidades

- Alta y gestión de usuarios (estudiantes y profesores)
- Administración de idiomas
- Creación y gestión de cursos y lecciones
- Ejercicios de completar y traducir
- Inscripción de estudiantes en cursos
- Realización y corrección automática de ejercicios
- Consulta de estadísticas y avance
- Eliminación y habilitación de cursos

## Estructura del proyecto

- `main.cpp`: Punto de entrada de la aplicación
- Clases principales: `Curso`, `Lecciones`, `Inscripcion`, `Estudiante`, `Profesor`, `Ctrl`
- Clases de transferencia de datos: `DataCurso`, `DataLeccion`, etc.
- Implementaciones de colecciones: Carpeta `ICollection/`
- `makefile`: Script para compilar el proyecto

## Requisitos

- Compilador C++ (recomendado: g++)
- Sistema operativo compatible (Windows, Linux, etc.)

## Compilación y ejecución

1. Abre una terminal en la carpeta raíz del proyecto.
2. Compila el proyecto con:

   ```sh
   make
   ```

3. Ejecuta la aplicación con:

   - En Linux/Mac:
     ```sh
     ./programa
     ```
   - En Windows:
     ```sh
     programa.exe
     ```

## Uso

Al iniciar, se mostrará un menú interactivo en consola. Sigue las instrucciones para crear usuarios, cursos, inscribirte, realizar ejercicios y consultar información.

## Créditos

Desarrollado por Brun, Cedrés, Da Costa, Molina, Nuñez.

---

Si tienes problemas de compilación, asegúrate de tener instalado `g++` y estar en la carpeta correcta. Para limpiar y recompilar:

```sh
make clean
make
```
