
#ifndef DATAINSCRIPCIONES2_H
#define DATAINSCRIPCIONES2_H
#include <string>
#include "DTFecha.h"
using namespace std;

class DataInscripciones2 {
	private:
		string nomEstu;
		DTFecha* fechaInsc;
	public:
	DataInscripciones2(std::string nomEstuDT, DTFecha* fechaInscDT);
	DataInscripciones2();
	virtual ~DataInscripciones2();
	std::string getnomEstu();
	DTFecha* getfechaInsc();
};

#endif