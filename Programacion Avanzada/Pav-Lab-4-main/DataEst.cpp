#include "DataEst.h"


DataEst::DataEst(DTFecha* fecNacE, std::string paisE){
    this->fecNac=fecNacE;
    this->pais=paisE;
};

DataEst::~DataEst(){
};

DTFecha* DataEst::getFecNac(){
    return this->fecNac;
};
std::string DataEst::getPais(){
    return this->pais;
};