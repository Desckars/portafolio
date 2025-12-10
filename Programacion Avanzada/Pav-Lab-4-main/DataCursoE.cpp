#include "DataCursoE.h"


DataCursoE::DataCursoE(std::string NomCursoPDT, float PAvanceDT){
    this->NomCursoP=NomCursoPDT;
    this->PAvance=PAvanceDT;
};

DataCursoE::~DataCursoE(){};

std::string DataCursoE::getNomCursoP(){
    return this->NomCursoP;
};

float DataCursoE::getPAvance(){
    return this->PAvance;
};