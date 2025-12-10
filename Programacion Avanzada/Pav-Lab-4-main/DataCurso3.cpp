#include "DataCurso3.h"

DataCurso3::DataCurso3(std::string nomCursoDT3, DIFICULTAD dificultadDT3, std::string desCursoDT3, int leccionesDT3, int ejerciciosDT3){
    this->nomCurso=nomCursoDT3;
    this->dificultad=dificultadDT3;
    this->desCurso=desCursoDT3;
    this->lecciones=leccionesDT3; 
    this->ejercicios=ejerciciosDT3;
};

DataCurso3::~DataCurso3(){};

std::string DataCurso3::getNomCurso(){
    return this->nomCurso;
};

DIFICULTAD DataCurso3::getDificultad(){
    return this->dificultad;
};

std::string DataCurso3::getDesCurso(){
    return this->desCurso;
};

int DataCurso3::getLecciones(){
    return this->lecciones;
};

int DataCurso3::getEjercicios(){
    return this->ejercicios;
};