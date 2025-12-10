
#ifndef DATAEST_H
#define DATAEST_H
#include <string>
#include "DTFecha.h"
using namespace std;

class DataEst {
	private:
		DTFecha* fecNac;
		std::string pais;
	public:
		DataEst(){};
		DataEst(DTFecha* fecNacE, std::string paisE);
		virtual ~DataEst();
		DTFecha* getFecNac();
		std::string getPais();
};

#endif