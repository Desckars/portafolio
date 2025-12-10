
#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "DTFecha.h"
#include "Lecciones.h"
class Curso;
#include "Estudiante.h"
/*
class Estudiante;

*/
class Inscripcion : public ICollectible {
	private:
		DTFecha* fechaInscr;
		bool aprovado;
		Estudiante* estudiante;
		Curso* curso;
		Lecciones* UltimaLec;
		IDictionary* EjerCompletados;

	public:
		Inscripcion(DTFecha* fechaInscrI, bool aprovadoI, Estudiante* estudianteI, Curso* cursoI);
		Inscripcion();
		virtual~Inscripcion();
		
		// Setter para UltimaLec
    	void asignarUltimaLec(Lecciones* leccion);
		
		//getters
		DTFecha* getfechaInscr();
		bool getaprovado();
		Estudiante* getestudiante();
		Curso* getcurso();
		
		//CU: Eliminar Curso
		void desligarEstudiante();

		//CU: Consultar Curso
		std::string devolverNomEstudiante();

		//cargar datos
		void aprobadoAutomatico(deTraducir* DT, deCompletar* DC);
		void aprobarInsc();

		//CU: Inscribirse Curso
		bool verificarInscripcion(std::string NomCurso);

		//CU: Consultar Estadisticas
		float getPromedio();

		//CU:Realizar Ejercicio
		set<std::string>conseguirEjerPendientes();
		set<std::string>PlantearProblemaI(std::string nomEjercicio);
		bool IngresarSolucionI(std::string solucionDeUsuario,std::string nomEjercicio);
};

#endif
