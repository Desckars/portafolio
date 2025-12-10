#include "DataEjeTraduccion.h"


DataEjeTraduccion::DataEjeTraduccion(std::string nomEjercicioT, std::string descripcionT, std::string fraseTT, std::string traduccionT){
    this->nomEjercicio=nomEjercicioT;
    this->descripcion=descripcionT;
    this->fraseT=fraseTT;
    this->traduccion=traduccionT;
};

DataEjeTraduccion::~DataEjeTraduccion(){
};
std::string DataEjeTraduccion::getNomEjercicio(){
    return this->nomEjercicio;
};
string DataEjeTraduccion::getDescripcion(){
    return this->descripcion;
};
string DataEjeTraduccion::getFraseT(){
    return this->fraseT;
};
string DataEjeTraduccion::getTraduccion(){
    return this->traduccion;
};