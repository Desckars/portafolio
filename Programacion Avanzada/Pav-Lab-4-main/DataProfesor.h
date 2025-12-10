
#ifndef DATAPROFESOR_H
#define DATAPROFESOR_H
#include <string>
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"
using namespace std;

class DataProfesor {
	private:
		string instituto;
		ICollection* nomIdioma;
	public:
		DataProfesor(std::string institutoDT, ICollection* nomIdiomaDT);
		DataProfesor();
		virtual ~DataProfesor();
		std::string getinstituto();
		ICollection* getnomIdioma();
};

#endif