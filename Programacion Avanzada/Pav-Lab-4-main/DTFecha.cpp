#include "DTFecha.h"

DTFecha::DTFecha(){};

DTFecha::DTFecha(int diaDT, int mesDT, int anioDT){
    this->dia=diaDT;
    this->mes=mesDT;
    this->anio=anioDT;
};
DTFecha::~DTFecha(){};

int DTFecha::getdia(){
    return this->dia;
};

int DTFecha::getmes(){
    return this->mes;
};

int DTFecha::getanio(){
    return this->anio;
};
DTFecha*  DTFecha::obtenerFechaActual() {
    time_t ahora = time(0); // Obtener la hora actual
    tm *tiempoLocal = localtime(&ahora); // Convertir a tiempo local

    int dia = tiempoLocal->tm_mday;
    int mes = tiempoLocal->tm_mon + 1; // tm_mon devuelve los meses desde 0 a 11
    int anio = tiempoLocal->tm_year + 1900; // tm_year devuelve años desde 1900

    DTFecha* fecha = new DTFecha(dia,mes,anio);
    return fecha;
}