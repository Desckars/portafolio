

#ifndef DATACURSO2_H
#define DATACURSO2_H
#include <string>
#include "DataEjeTraduccion.h"
#include "DataEjeCompletar.h"
#include "DataInscripciones2.h"
#include "Curso.h"
#include "DataLeccion.h"
using namespace std;

class DataCurso2 {
	private:
		std::string nomCurso;
		DIFICULTAD dificultad;
		std::string desCurso;
		std::string nomIdioma;
		std::string nomProf;
		bool habilitado;
		set<DataLeccion*> Leccion;
		set<DataInscripciones2*> Inscrip;
	public:
		DataCurso2(){};
		DataCurso2(std::string nomCursoDT, DIFICULTAD dificultadDT, std::string desCursoDT,std::string nomIdiomaDT, std::string nomProfDT, bool habilitadoDT, set<DataLeccion*> LeccionDT, set<DataInscripciones2*> InscripDT);
		virtual ~DataCurso2();
		std::string getNomCurso();
		DIFICULTAD getDificultad();
		std::string getDesCurso();
		std::string getNomIdioma();
		std::string getNomProf();
		bool getHabilitado();
		set<DataLeccion*> getLeccion();
		set<DataInscripciones2*> getInscrip();
};


#endif