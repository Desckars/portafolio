#include"Profesor.h"
#include "Idiomas.h"


Profesor::Profesor(std::string nicknameP, std::string descripcionP, std::string nombreP, std::string contraseniaP, std::string institutoP){
    this->nickname=nicknameP;
    this->descripcion=descripcionP;
    this->nombre=nombreP;
    this->contrasenia=contraseniaP;
    this->instituto=institutoP;
    this->idiomas= new List();
    this->cursos=new List();
};

Profesor::Profesor(){};

Profesor::~Profesor(){};

string Profesor::getinstituto(){
    return this->instituto;
};

ICollection* Profesor::getIdiomas(){
    return this->idiomas;
};

ICollection* Profesor::getCursos(){
    return this->cursos;
};

//CU: Alta de Usuario
void Profesor::aniadirIdioma(Idiomas* idioma){
    (this->idiomas)->add((ICollectible*)idioma);
};


//CU: Alta de Curso
void Profesor::asignarCursoAProfesor(Curso* cursoNuevo){
    (this->cursos)->add((ICollectible*)cursoNuevo); //Si queda en ICollection
    
    //IKey* KeyCurso = new String((cursoNuevo->getNomCurso()).c_str()); //si lo cambio a IDictionary
    //this->Cursos.add(KeyCurso,cursoNuevo);
};

set<std::string> Profesor::buscarIdioma(Profesor* prof){
    set<std::string> idiomas; 
    IIterator* it=(prof->getIdiomas())->getIterator();
    while (it->hasCurrent()){
        idiomas.insert(((Idiomas*)it->getCurrent())->getNomIdioma());
        it->next();
    }
    return idiomas;
};

//CU: Eliminar Curso
void Profesor::desligarProfesor(Curso* cursoBorrar){
    (this->cursos)->remove((ICollectible*)cursoBorrar);
};
//CU: Consultar Estadistica
set<DataCursoP*>Profesor::cursosProfesor(){
    IIterator* itc = this->cursos->getIterator();
    set<DataCursoP*> DCP;
    while(itc->hasCurrent()){
        float prom = ((Curso*)itc->getCurrent())->getPromedioT();
        string ncurso =((Curso*)itc->getCurrent())->getNomCurso();
        DCP.insert(new DataCursoP(ncurso,prom));
    }
    delete itc;
    return DCP;
}
