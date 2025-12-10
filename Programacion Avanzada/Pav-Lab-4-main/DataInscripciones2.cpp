#include"DataInscripciones2.h"

DataInscripciones2::DataInscripciones2(std::string nomEstuDT, DTFecha* fechaInscDT){
    this->nomEstu=nomEstuDT;
    this->fechaInsc=fechaInscDT;
};

DataInscripciones2::DataInscripciones2(){};

DataInscripciones2::~DataInscripciones2(){};

string DataInscripciones2::getnomEstu(){
    return this->nomEstu;
};

DTFecha* DataInscripciones2::getfechaInsc(){
    return this->fechaInsc;
};