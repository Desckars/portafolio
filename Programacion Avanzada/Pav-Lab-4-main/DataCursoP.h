
#ifndef DATACURSOP_H
#define DATACURSOP_H
#include <string>
using namespace std;

class DataCursoP {
	private:
		std::string NomCursoP;
		float Prom;
	public:
		DataCursoP(){};
		DataCursoP(std::string NomCursoPDT, float PromDT);
		virtual ~DataCursoP();
		std::string getNomCurso();
		float getProm();
};

#endif