#ifndef DIFICULTAD_H
#define DIFICULTAD_H

enum DIFICULTAD{
	principiante,medio,avanzado
};

#endif
#ifndef CURSO_H
#define CURSO_H
#include "Lecciones.h"
#include "Idiomas.h"
class DataCurso;
class DataCurso3;
class Profesor;
#include "DataLeccion.h"
#include "DataInscripciones2.h"
#include "Inscripcion.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include <string>
#include <set>
using namespace std;
//class Profesor;
class Curso : public ICollectible{
	private:
		std::string nomCurso;
		std::string desCurso;
		DIFICULTAD dificultad;
		bool habilitado;
		Idiomas* Idioma;
		Profesor* profesor;
		ICollection* MisPrevias;
		ICollection* SoyPreviaDe;
		ICollection* lecciones;
		IDictionary* Inscripciones; //nickname de Estudiante es IKey
	public:
		//constructores y getters
		Curso(){};
		Curso(std::string nomCursoC, std::string desCursoC, DIFICULTAD dificultadC, bool habilitadoC, Idiomas* IdiomaC, Profesor* profesorC);
		virtual ~Curso();
		std::string getNomCurso();
		std::string getDesCurso();
		DIFICULTAD getDificultad();
		bool getHabilitado();
		Idiomas* getIdioma();
		Profesor* getProfesor();
		ICollection* getMisPrevias();
		ICollection* getSoyPreviaDe();
		ICollection* getLecciones();
		IDictionary* getInscripciones();
		
		//CU: Alta de Curso
		void asignarIdiomaACurso(Idiomas* I);
		void esPrevia (Curso* CursoPrevia);
		void miPrevia (Curso* CursoNuevo);

		//CU: Eliminar Curso
		void DeleteALLforCurso();
		void desligarDePrevia(Curso* cursoBorrar);

		//CU: Agregar Ejercico
		set<std::string> conseguirLecciones();
		bool ExisteLecC(std::string nomLec);

		//CU: Habilitar Curso
		void habilitar();

		//Agregar Leccion
		Lecciones* CrearLeccion(string NomTema, string Objetivo);//OK
		void AgregarEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Lecciones* leccionNH);//OK

		//CU: Consultar Curso
		set<DataLeccion*> conseguirDataLeccion();
		set<DataInscripciones2*> conseguirDataInsc2();
		
		//cargar datos
		void aniadirInscripcionCurso(Inscripcion* insc);
		//CU: Inscribirse Curse
		set<std::string> DamePrevias();
		DataCurso3* getDataCurso3();
		void agregarInscripcionCurso(Inscripcion* I);//Falta arreglar, PL link inscripcion, ver diagrama
		//CU: Consultar Estadisticas
		float getPromedioT();
		DataCurso* getDataCurso();
		Lecciones* GetLeccion(std::string nomLec);
};

#endif


