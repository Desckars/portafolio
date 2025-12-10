
#ifndef IDIOMAS_H
#define IDIOMAS_H
#include <string>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Idiomas : public ICollectible {
	private:
		std::string nomIdioma;
	public:
		Idiomas(std::string NomIdiomaI);
		Idiomas();
		virtual ~Idiomas();
		std::string getNomIdioma();
};

#endif