
#ifndef USUARIO_H
#define USUARIO_H
#include "ICollection/interfaces/ICollectible.h"
#include <string>
#include <set>
using namespace std;

class Usuario : public ICollectible{
	protected:
		string nickname;
		string descripcion;
		string nombre;
		string contrasenia;
	public:
	//getters (constructores son innecesarios ya que trabajamos directamente con Profesor y Estudiante)
	std::string getNickname();
	std::string getDescripcion();
	std::string getNombre();
	std::string getContrasenia();
	//

	
};

#endif