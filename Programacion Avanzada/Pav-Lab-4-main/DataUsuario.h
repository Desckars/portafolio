#ifndef DATAUSUARIO_H
#define DATAUSUARIO_H
#include <string>
#include "DataProfesor.h"
#include "DataEst.h"
using namespace std;

class DataUsuario {
	private:
		string nickname;
		string descripcion;
		string nombre;
		string contrasenia;
		DataProfesor* Profesores;
		DataEst* Estudiante;
	public:
		DataUsuario(std::string nicknameDT, std::string descripcionDT, std::string nombreDT, std::string contraseniaDT, DataProfesor* ProfesorDT, DataEst* EstudianteDT);
		virtual ~DataUsuario();
		DataUsuario();
		std::string getnickname();
		std::string getdescripcion();
		std::string getnombre();
		std::string getcontrasenia();
		DataProfesor* getProfesor();
		DataEst* getEstudiante(); 
};

#endif