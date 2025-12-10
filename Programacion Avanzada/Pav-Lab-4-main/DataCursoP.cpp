#include "DataCursoP.h"


DataCursoP::DataCursoP(std::string NomCursoPDT, float PromDT){
    this->NomCursoP=NomCursoPDT;
    this->Prom=PromDT;
};

DataCursoP::~DataCursoP(){};

std::string DataCursoP::getNomCurso(){
    return this->NomCursoP;
};

float DataCursoP::getProm(){
    return this->Prom;
};