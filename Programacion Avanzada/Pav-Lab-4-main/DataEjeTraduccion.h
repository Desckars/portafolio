
#ifndef DATAEJETRADUCCION_H
#define DATAEJETRADUCCION_H
#include <string>
using namespace std;

class DataEjeTraduccion {
	private:
		std::string nomEjercicio;
		std::string descripcion;
		std::string fraseT;
		std::string traduccion;
	public:
		DataEjeTraduccion(){};
		DataEjeTraduccion(std::string nomEjercicioT, std::string descripcionT, std::string fraseTT, std::string traduccionT);
		virtual ~DataEjeTraduccion();
		std::string getNomEjercicio();
		string getDescripcion();
		string getFraseT();
		string getTraduccion();
};

#endif