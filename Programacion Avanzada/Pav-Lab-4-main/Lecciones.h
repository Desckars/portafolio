
#ifndef LECCIONES_H
#define LECCIONES_H
#include <string>
#include "deCompletar.h"
#include "deTraducir.h"
#include "DataEjeCompletar.h"
#include "DataEjeTraduccion.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
using namespace std;

class Lecciones : public ICollectible{
	private:
		std::string tema;
		std::string objetivo;
		IDictionary* DeCompletar;
		IDictionary* DeTraducir;
	public:
		Lecciones(std::string temaI, std::string objetivoI);
		Lecciones();
		virtual~Lecciones();
		std::string getTema();
		std::string getObjetivo();
		IDictionary* getdeCompletar();
		IDictionary* getdeTraducir();

		//Agregar Leccion
		void CrearEjer(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion);//OK
		//CU: Eliminar Curso
		void DeleteAllEjercicios();

		//CU: Consultar Curso
		set<DataEjeCompletar*> conseguirDataEjeComp();
		set<DataEjeTraduccion*> conseguirDataEjeTrad();

		//cargar datos
		deTraducir* conseguirDT(IKey* keyDT);
		deCompletar* conseguirDC(IKey* keyDC);
		//CU: Inscribirse Curso
		int sumarEjercicio();
};

#endif