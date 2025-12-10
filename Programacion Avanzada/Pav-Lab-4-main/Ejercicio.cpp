#include "Ejercicio.h"
Ejercicio::Ejercicio(std::string nomEjercicioI, std::string descripcionI){
    this->descripcion=descripcionI;
    this->nomEjercicio=nomEjercicioI;
};

Ejercicio::Ejercicio(){};

Ejercicio::~Ejercicio(){};

string Ejercicio::getnomEjercicio(){
    return this->nomEjercicio;
};
string Ejercicio::getdescripcion(){
    return this->descripcion;
};