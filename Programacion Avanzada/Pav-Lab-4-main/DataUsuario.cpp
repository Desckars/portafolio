#include "DataUsuario.h"
#include "DataEst.h"
#include "DataProfesor.h"

DataUsuario::DataUsuario(std::string nicknameDT, std::string descripcionDT, std::string nombreDT, std::string contraseniaDT, DataProfesor* ProfesorDT, DataEst* EstudianteDT){
    this->nickname=nicknameDT;
    this->descripcion=descripcionDT;
    this->nombre=nombreDT;
    this->contrasenia=contraseniaDT;
    this->Estudiante=EstudianteDT;
    this->Profesores=ProfesorDT;
};

DataUsuario::~DataUsuario(){};

string DataUsuario::getnickname(){
    return this->nickname;
};

string DataUsuario::getdescripcion(){
    return this->descripcion;
};

string DataUsuario::getnombre(){
    return this->nombre;
};

string DataUsuario::getcontrasenia(){
    return this->contrasenia;
};

DataProfesor* DataUsuario::getProfesor(){
    return this->Profesores;
};

DataEst* DataUsuario::getEstudiante(){
    return this->Estudiante;
};