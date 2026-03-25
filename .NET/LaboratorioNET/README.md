Diseñado y testeado en Windows
1. Introducción

La región se ha consolidado como un destacado centro para la realización de eventos deportivos de convocatoria masiva. A eventos tradicionales como la "Clásica Carrera 10K de San Fernando" del 6 de enero, se han sumado competencias de gran envergadura como el Ironman 70.3 y la Maratón de Punta del Este, esta última con cerca de 5,000 participantes en su última edición.

Esta creciente demanda de eventos requiere soluciones tecnológicas robustas que optimicen la gestión, mejoren sustancialmente la experiencia de los atletas y simplifiquen las tareas operativas de los organizadores. La presente propuesta tiene como objetivo desarrollar un sistema integral para abordar estos desafíos.

2. Objetivo del Proyecto

El objetivo principal del taller es analizar, diseñar e implementar una aplicación web bajo la plataforma .NET, denominada SportEvent Manager, para la gestión integral de carreras deportivas.

3. Fundamentación de la Propuesta

Esta propuesta se caracteriza por su enfoque general y abierto, simulando las condiciones iniciales de un proyecto de software en el ámbito profesional. 
A diferencia  del taller Java, donde el desarrollo de la solución estaba predeterminado (dividido en instancias concretas), en esta oportunidad, se presenta un listado inicial de necesidades surgidas de una hipotética entrevista preliminar con el cliente.

Cada equipo de desarrollo deberá asumir la responsabilidad de:
Realizar un análisis y priorización de los requerimientos (visualizar la solución completa).
Definir una planificación iterativa e incremental.
Tomar decisiones técnicas y arquitectónicas fundamentadas.
Entregar una versión funcional (Prueba de Concepto) que demuestre la viabilidad del proyecto.

Este enfoque fomenta la autonomía, la gestión de proyecto y la capacidad de adaptación, habilidades críticas en el desarrollo de software real.

4. Principales Requisitos Funcionales

*La siguiente es una lista de requerimientos a ser tomados en cuenta. Es un punto de partida para orientar la solución final. 

*El sistema deberá contemplar, como punto de partida, las siguientes funcionalidades:
Gestión Multi-eventos: Capacidad para crear y administrar diferentes carreras con configuraciones independientes.

*Inscripción Online: permitir a los corredores inscribirse (via web) en los eventos disponibles.
Administración de Corredores: Gestionar el proceso de asignación y retiro de números de dorsal o kits de competencia. 

*Toma de Tiempos: Registrar y consultar tiempos parciales (en puntos de control específicos) y el tiempo final de cada participante.

*Seguimiento en Tiempo Real: permitir el seguimiento aproximado de la posición de un corredor durante el transcurso de la carrera.

*Configuración de Puntos de Control: permitir la definición y configuración de los puntos de la ruta donde se capturan los tiempos mediante la lectura de chips RFID u otra tecnología.

*Automación de la Meta: Implementar una funcionalidad que, al detectar el cruce de la meta, muestre automáticamente el nombre del corredor en un display o interfaz pública.
----------------------------------------------------------------------------------------------------------

Tecnologia: ASP.NET Core Blazor
Base de datos: MongoDB
Nombre de la Base de Datos: TallerNET
Detalles de conexcion:
    "ConnectionString": "mongodb://localhost:27017",
Comandos para la ejecucion: dotnet run

Para probar la simulacion hay que entrar como "admin"(no hay forma de entrar como admin, solo creando un corredor y desde la base de datos cambiar el rol a "admin"), darle a la opcion de "simular carrera" y le das a "buscar", ahi apareceran las carreras, seleccionamos una, reseteamos carrera en caso de que ya alla ocurrido, y al simular veremos progreso en modo de tiempo y porcentaje.