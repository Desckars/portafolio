#include "Curso.h"
#include "Profesor.h"
#include "DataCurso.h"
#include "DataCurso3.h"
#include <cstring>

//constructor y getters
Curso::Curso(std::string nomCursoC, std::string desCursoC, DIFICULTAD dificultadC, bool habilitadoC, Idiomas* IdiomaC, Profesor* profesorC){
    this->nomCurso=nomCursoC;
    this->desCurso=desCursoC;
    this->dificultad=dificultadC;
    this->habilitado=habilitadoC;
    this->Idioma=IdiomaC;
    this->profesor=profesorC;
    this->MisPrevias= new List();
	this->SoyPreviaDe= new List();
	this->lecciones= new List();
	this->Inscripciones = new OrderedDictionary();
};

Curso::~Curso(){

};

std::string Curso::getNomCurso(){
    return this->nomCurso;
};

std::string Curso::getDesCurso(){
    return this->desCurso;
};

DIFICULTAD Curso::getDificultad(){
    return this->dificultad;
};

bool Curso::getHabilitado(){
    return this->habilitado;
};

Idiomas* Curso::getIdioma(){
    return this->Idioma;
};

Profesor* Curso::getProfesor(){
    return this->profesor;
};

ICollection* Curso::getMisPrevias(){
    return this->MisPrevias;
};

ICollection* Curso::getSoyPreviaDe(){
    return this->SoyPreviaDe;
};

ICollection* Curso::getLecciones(){
    return this->lecciones;
};
IDictionary* Curso::getInscripciones(){
    return this->Inscripciones;
};

//CU: Alta de Curso
void Curso::asignarIdiomaACurso(Idiomas* I){
    this->Idioma=I;
};

void Curso::esPrevia (Curso* CursoPrevia){
    (this->MisPrevias)->add((ICollectible*)CursoPrevia);
};

void Curso::miPrevia (Curso* CursoNuevo){
    (this->SoyPreviaDe)->add((ICollectible*)CursoNuevo);
};


//CU: Eliminar Curso
void Curso::desligarDePrevia(Curso* cursoBorrar){
    //remuevo el curso que quiero borrar de las previas de este curso (que es posterior al que quiero borrar)
    (this->MisPrevias)->remove((ICollectible*)cursoBorrar);
};

void Curso::DeleteALLforCurso(){

    //itero entre las lecciones y borro todos sus ejercicios
    IIterator* itLecciones=(this->lecciones)->getIterator();
    while(itLecciones->hasCurrent()){
        (((Lecciones*)itLecciones->getCurrent())->DeleteAllEjercicios());
        itLecciones->next();
    }
    
    //itero entre todos los estudiantes diciendoles que olviden sus inscripciones a este curso
    //y luego borro la inscripcion
    IIterator* itInscripciones=(this->Inscripciones)->getIterator();
    while(itInscripciones->hasCurrent()){
        (((Inscripcion*)itInscripciones->getCurrent())->desligarEstudiante());
        (((Inscripcion*)itInscripciones->getCurrent())->~Inscripcion());
        itInscripciones->next();
    }
    
    //le digo al profesor que se olvide del curso
    (this->profesor)->desligarProfesor(this);
    
    //itero entre las posteriores y les digo que olviden a este curso como previa
    IIterator* itSoyPrevia=(this->SoyPreviaDe)->getIterator();
    while(itSoyPrevia->hasCurrent()){
        (((Curso*)itSoyPrevia->getCurrent())->desligarDePrevia(this));
        itSoyPrevia->next();
    }

    //itero entre las previas de este curso y les digo que lo olviden como posterior 
    IIterator* itMisPrevias=(this->MisPrevias)->getIterator();
    while(itMisPrevias->hasCurrent()){
        ((((Curso*)itMisPrevias->getCurrent())->SoyPreviaDe)->remove((ICollectible*)this));
        itMisPrevias->next();
    }

    //borro todos los iteradores recien creados
    delete itLecciones;
    delete itInscripciones;
    delete itSoyPrevia;
    delete itMisPrevias;
};


//CU Agregar Ejercicio

set<std::string> Curso::conseguirLecciones(){
    set<std::string> leccionesCurso;
    ICollection* listaLecciones=this->getLecciones();
    IIterator* it=listaLecciones->getIterator();
    while(it->hasCurrent()){
        leccionesCurso.insert(((Lecciones*)it->getCurrent())->getTema());
        it->next();
    };
    return leccionesCurso;
};

Lecciones* Curso::GetLeccion(std::string nomLec){
    IIterator* it=this->lecciones->getIterator();
    while(it->hasCurrent()){
        if(((Lecciones*)it->getCurrent())->getTema() == nomLec){
            return (Lecciones*)it->getCurrent();
        }
        it->next();
    };
    return NULL;
}

bool Curso::ExisteLecC(std::string nomLec){
    IIterator* it=this->lecciones->getIterator();
    while(it->hasCurrent()){
        if(((Lecciones*)it->getCurrent())->getTema() == nomLec){
            return true;
        }
        it->next();
    };
    return false;
}

//CU: Habilitar Curso

void Curso::habilitar(){
    this->habilitado=true;
};
//Agregar Leccion
Lecciones* Curso::CrearLeccion(string NomTema, string Objetivo){
    //Creamos la leccion
   Lecciones* leccion=new Lecciones( NomTema, Objetivo);//MIRARARARARRARAR
   //La leccion creada se agrega a la coleccion
    this->lecciones->add((ICollectible*) leccion);
    return leccion;
};//OK
void Curso::AgregarEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Lecciones* leccionNH){
    leccionNH->CrearEjer(NomEj,tipo,desc,frase,solucion);
};//OK

set<DataLeccion*> Curso::conseguirDataLeccion(){
    set<DataLeccion*> setRetornar;
    set<DataEjeCompletar*> setDTC;
    set<DataEjeTraduccion*> setDTT;
    std::string temaLec;
    std::string objetivoLec;
    IIterator* it=this->lecciones->getIterator();
    while(it->hasCurrent()){
        temaLec=((Lecciones*)it->getCurrent())->getTema();
        objetivoLec=((Lecciones*)it->getCurrent())->getObjetivo();
        setDTC = ((Lecciones*)it->getCurrent())->conseguirDataEjeComp();
        setDTT = ((Lecciones*)it->getCurrent())->conseguirDataEjeTrad();
        DataLeccion* datLec = new DataLeccion(temaLec,objetivoLec, setDTC, setDTT);
        setRetornar.insert(datLec);
        it->next();
    }
    delete it;
    return setRetornar;
};

set<DataInscripciones2*> Curso::conseguirDataInsc2(){
    set<DataInscripciones2*> setRetornar;
    std::string nomEstu;
    DTFecha* fechaInsc;
    IIterator* it =this->Inscripciones->getIterator();
    while (it->hasCurrent()){
        nomEstu=((Inscripcion*)it->getCurrent())->devolverNomEstudiante();
        fechaInsc=((Inscripcion*)it->getCurrent())->getfechaInscr();
        DataInscripciones2* dataIncs = new DataInscripciones2(nomEstu,fechaInsc);
        setRetornar.insert(dataIncs);
        it->next();
    }
    delete it;
    return setRetornar;
};

//cargar datos
void Curso::aniadirInscripcionCurso(Inscripcion* insc){
    //consigo key de la inscripcion
    std::string nickEst = (insc->getestudiante())->getNickname();
    OrderedKey* keyInsc = new String(nickEst.c_str());
    //la aniado a la coleccion
    this->Inscripciones->add(keyInsc, (ICollectible*)insc);

};
//CU: Inscribirse Curse
set<std::string> Curso::DamePrevias(){
    set<std::string> Previas;
    IIterator* itMP=(this->MisPrevias)->getIterator();
    while(itMP->hasCurrent()){
        //Inserto en el set Previas los nombres de los cursos en la coleccion de MisPrevias
        Previas.insert(((Curso*)itMP->getCurrent())->getNomCurso());
        itMP->next();
    }
    return Previas;
};
DataCurso3* Curso::getDataCurso3(){
    IIterator* itLec=(this->lecciones)->getIterator();
    int cantL=0;
    int cantE=0;
    while(itLec->hasCurrent()){
        Lecciones* L=(Lecciones*) itLec->getCurrent();
        cantL=cantL+1;
        cantE=cantE+L->sumarEjercicio(); //Le tendria que pasar un puntero a la laccion de la que estoy hablando?
        itLec->next();
    }
    
    return new DataCurso3(this->nomCurso, this->dificultad, this->desCurso, cantL, cantE);
};
void Curso::agregarInscripcionCurso(Inscripcion* I){
    std::string nomE=I->getestudiante()->getNickname();
    IKey* IKE= new String(nomE.c_str());
    (this->Inscripciones)->add(IKE,(ICollectible*)I);//Curso agrega la coleccion a I

    IIterator* itL=this->lecciones->getIterator();
    Lecciones* PL=(Lecciones*)itL->getCurrent();//PL es la primera Leccion
    I->asignarUltimaLec(PL);
    delete itL;
    delete PL;
};

//CU:Consultar Estadisticas
float Curso::getPromedioT(){
    float percIns = 0;
    IIterator* iti =this->Inscripciones->getIterator();
    while(iti->hasCurrent()){
        percIns += ((Inscripcion*)iti->getCurrent())->getPromedio();
        iti->next();
    }
    delete iti;
    return percIns/(this->Inscripciones->getSize());
};

DataCurso* Curso::getDataCurso(){
    return new DataCurso(this->nomCurso,this->dificultad,this->desCurso,this->habilitado,this->getPromedioT());
};
