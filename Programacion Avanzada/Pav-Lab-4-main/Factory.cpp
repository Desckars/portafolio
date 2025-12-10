#include "Factory.h"
#include "Ctrl.h"
#include "ICtrl.h"

Factory::Factory(){};

Factory::~Factory(){};

ICtrl* Factory::getICtrl(){
    return Ctrl::getInstance();
};

