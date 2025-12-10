#ifndef FACTORY_H
#define FACTORY_H
#include "ICtrl.h"

class Factory{
    private:
    public:
        Factory();
        virtual ~Factory();
        ICtrl* getICtrl();
};

#endif // FACTORY_H