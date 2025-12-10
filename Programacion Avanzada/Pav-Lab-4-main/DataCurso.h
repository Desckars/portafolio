
#ifndef DATACURSO_H
#define DATACURSO_H
#include <string>
#include "Curso.h"
using namespace std;

class DataCurso {
	private:
		std::string nomCurso;
		DIFICULTAD dificultad;
		std::string desCurso;
		bool habilitado;
		float promedioT;
	public:
		DataCurso(){};
		DataCurso (std::string nomCursoDT, DIFICULTAD dificultadDT, std::string desCursoDT, bool habilitadoDT, float promedioTDT);
        virtual ~DataCurso();
		std::string getNomCurso();
		DIFICULTAD getDificultad();
		std::string getDesCurso();
		bool getHabilitado();
		float getPromediT();
};


#endif