
#ifndef DATAEJECOMPLETAR_H
#define DATAEJECOMPLETAR_H
#include <string>
#include <set>
#include "ICollection/interfaces/ICollection.h"
using namespace std;

class DataEjeCompletar {
	private:
		std::string nomEjercicio;
		std::string descripcion;
		std::string fraseC;
		set<std::string> faltante;
	public:
		DataEjeCompletar(){};
		DataEjeCompletar(std::string nomEjercicioC, std::string descripcionC, std::string fraseCC, set<std::string> faltanteC);
		virtual ~DataEjeCompletar();
		std::string getNomEjercicio();
		std::string getDescripcion();
		std::string getFraseC();
		set<std::string> getFaltante();
};

#endif