#include "DataCurso.h"

DataCurso::DataCurso(std::string nomCursoDT, DIFICULTAD dificultadDT, std::string desCursoDT, bool habilitadoDT, float promedioTDT){
    this->nomCurso=nomCursoDT;
    this->dificultad=dificultadDT;
    this->desCurso=desCursoDT;
    this->habilitado=habilitadoDT;
    this->promedioT=promedioTDT;
};

DataCurso::~DataCurso(){};

string DataCurso::getNomCurso(){
    return this->nomCurso;
};

DIFICULTAD DataCurso::getDificultad(){
    return this->dificultad;

};

string DataCurso::getDesCurso(){
    return this->desCurso;    
};

bool DataCurso::getHabilitado(){
    return this->habilitado;
};

float DataCurso::getPromediT(){
    return this->promedioT;
};

