#include "DataCurso2.h"

DataCurso2::DataCurso2(std::string nomCursoDT, DIFICULTAD dificultadDT, std::string desCursoDT,std::string nomIdiomaDT, std::string nomProfDT, bool habilitadoDT, set<DataLeccion*> LeccionDT, set<DataInscripciones2*> InscripDT){
    this->nomCurso=nomCursoDT;
	this->dificultad=dificultadDT;
	this->desCurso=desCursoDT;
	this->nomIdioma=nomIdiomaDT;
	this->nomProf=nomProfDT;
	this->habilitado=habilitadoDT;
	this->Leccion=LeccionDT;
	this->Inscrip=InscripDT;
}

DataCurso2::~DataCurso2(){};

string DataCurso2::getNomCurso(){
    return this->nomCurso;
};

DIFICULTAD DataCurso2::getDificultad(){
    return this->dificultad;

};

string DataCurso2::getDesCurso(){
    return this->desCurso;    
};

std::string DataCurso2::getNomIdioma(){
    return this->nomIdioma;
};

std::string DataCurso2::getNomProf(){
    return this->nomProf;
};

bool DataCurso2::getHabilitado(){
    return this->habilitado;
};

set<DataLeccion*> DataCurso2::getLeccion(){
	return this->Leccion;
};
set<DataInscripciones2*> DataCurso2::getInscrip(){
	return this->Inscrip;
};
