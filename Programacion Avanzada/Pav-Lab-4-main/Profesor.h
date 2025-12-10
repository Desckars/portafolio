
#ifndef PROFESOR_H
#define PROFESOR_H
#include "ICollection/interfaces/ICollection.h"
#include "Usuario.h"
#include "Curso.h"
#include "DataCursoP.h"

class Profesor : public Usuario{
	private:
		std::string instituto;
		ICollection* idiomas;
		ICollection* cursos; //IDictionary?
	public:
	Profesor(std::string nicknameP, std::string descripcionP, std::string nombreP, std::string contraseniaP, std::string institutoP);
	Profesor();
	virtual ~Profesor();
	std::string getinstituto();
	ICollection* getIdiomas();
	ICollection* getCursos();//IDictionary?

	//CU: Alta de Usuario
	void aniadirIdioma(Idiomas* idioma);

	//CU: Alta de Curso
	void asignarCursoAProfesor(Curso* cursoNuevo);
	set<std::string> buscarIdioma(Profesor* prof);

	//CU: Eliminar Curso
	void desligarProfesor(Curso* cursoBorrar);
	//CU: Consultar Estadistica
	set<DataCursoP*>cursosProfesor();
	
};

#endif