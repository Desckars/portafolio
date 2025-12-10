#include"DataProfesor.h"

DataProfesor::DataProfesor(std::string institutoDT, ICollection* nomIdiomaDT){
    this->instituto=institutoDT;
    this->nomIdioma=nomIdiomaDT;
};

DataProfesor::DataProfesor(){};

DataProfesor::~DataProfesor(){};

string DataProfesor::getinstituto(){
    return this->instituto;
};

ICollection* DataProfesor::getnomIdioma(){
    return this->nomIdioma;
};