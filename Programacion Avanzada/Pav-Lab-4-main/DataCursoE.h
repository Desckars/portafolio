
#ifndef DATACURSOSE_H
#define DATACURSOSE_H
#include <string>
using namespace std;
//
class DataCursoE {
	private:
		std::string NomCursoP;
		float PAvance;
	public:
		DataCursoE(){};
		DataCursoE(std::string NomCursoPDT, float PAvanceDT);
		virtual ~DataCursoE();
		std::string getNomCursoP();
		float getPAvance(); //porcentaje
};

#endif