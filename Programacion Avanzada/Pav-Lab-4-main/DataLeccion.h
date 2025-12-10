
#ifndef DATALECCION_H
#define DATALECCION_H
#include <string>
#include <set>
#include "DataEjeCompletar.h"
#include "DataEjeTraduccion.h"
using namespace std;

class DataLeccion {
	private:
		string tema;
		string objetivo;
		set<DataEjeCompletar*> DataEjeComp;
		set<DataEjeTraduccion*> DataEjeTrad;

	public:
		DataLeccion(std::string temaDT, std::string objetivoDT, set<DataEjeCompletar*> DataEjeCompDT, set<DataEjeTraduccion*> DataEjeTradDT);
		DataLeccion();
		virtual ~DataLeccion();
		std::string gettema();
		std::string getobjetivo();
		set<DataEjeCompletar*> getDataEjeComp();
		set<DataEjeTraduccion*> getDataEjeTrad();
};

#endif