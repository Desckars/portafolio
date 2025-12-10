
#ifndef DATACURSO3_H
#define DATACURSO3_H
#include <string>
#include "Curso.h"
using namespace std;

class DataCurso3 {
	private:
		std::string nomCurso;
		DIFICULTAD dificultad;
		std::string desCurso;
		int lecciones;
		int ejercicios;
	public:
		DataCurso3(){};
		DataCurso3(std::string nomCursoDT3, DIFICULTAD dificultadDT3, std::string desCursoDT3, int leccionesDT3, int ejerciciosDT3);
		virtual ~DataCurso3();
		std::string getNomCurso();
		DIFICULTAD getDificultad();
		std::string getDesCurso();
		int getLecciones();
		int getEjercicios();
};

#endif