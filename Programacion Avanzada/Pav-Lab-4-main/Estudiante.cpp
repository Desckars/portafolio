#include "Estudiante.h"
#include "Inscripcion.h"
#include "Curso.h"

Estudiante::Estudiante(string nicknameE, string descripcionE, string nombreE, string contraseniaE, DTFecha* fecNacE, std::string PaisE){
    this->nickname=nicknameE;
    this->descripcion=descripcionE;
    this->nombre=nombreE;
    this->contrasenia=contraseniaE;
    this->fecNac=fecNacE;
    this->Pais=PaisE;
    this->Inscripciones=new OrderedDictionary();
    this->UltimaLeccion=nullptr;
    this->EjerciciosAprov=new List();
};

Estudiante::Estudiante(){};

Estudiante::~Estudiante(){};

DTFecha* Estudiante::getfecNac(){
    return this->fecNac;
};

std::string Estudiante::getPais(){
    return this->Pais;
};

IDictionary* Estudiante::getInscripciones(){
    return this->Inscripciones;
};

Lecciones* Estudiante::getUltimaLeccion(){
    return this->UltimaLeccion;
};

ICollection* Estudiante::getEjerciciosAprov(){
    return this->EjerciciosAprov;
};


//CU: Eliminar Curso
void Estudiante::olvidarInscripcion(Inscripcion* insc){
    //consigo key de la inscripcion
    IKey* keyInsc = new String((insc->getcurso())->getNomCurso().c_str());
    //la remuevo de la coleccion
    this->Inscripciones->remove(keyInsc);
};



//cargar datos
void Estudiante::aniadirInscripcion(Inscripcion* insc){
    //consigo key de la inscripcion
    std::string nomCurso= ((insc->getcurso())->getNomCurso());
    OrderedKey* keyInsc = new String(nomCurso.c_str());
    //la aniado a la coleccion
    this->Inscripciones->add(keyInsc, (ICollectible*)insc);

};

//CU: Inscribirse a Curso
bool Estudiante::haCursado(std::string nomCurso){//Verificar con Thiago
    //consigo todos las inscripciones en el Estuidante y consigo un iterador en base a eso
    IIterator* itI=(this->Inscripciones)->getIterator();
    while(itI->hasCurrent()){//Punto 1
        Inscripcion* I=(Inscripcion*) itI->getCurrent();
        //Si es verdadero quiere decir que el estudiante si estuvo inscripto a ese curso
        if(I->verificarInscripcion(nomCurso)==true){
            return true;
        }
        itI->next();
    }
    return false;
};
void Estudiante::agregarInscripcionEstudiante(Inscripcion* I){
    std::string nomC=I->getcurso()->getNomCurso();//Consigo el nombre del curso que sera la Key
    IKey* IKC= new String(nomC.c_str());
    (this->Inscripciones)->add(IKC,(ICollectible*)I);//Curso agrega la coleccion a I
};
bool Estudiante::estanDisponibles(set<std::string> Previas){
    IIterator* itI=(this->Inscripciones)->getIterator();
    while(itI->hasCurrent()){//Punto 1
        Inscripcion* I= (Inscripcion*)(itI->getCurrent());
        for(std::set<std::string>::iterator it = Previas.begin(); it != Previas.end(); ++it){
            if(I->getcurso()->getNomCurso() == *it){//Esto es para preguntar si la previa en donde estoy y el nombre de la previa del Set son iguales asi pregunto si esta aprobado
                if(I->getaprovado()==false){//Si el curso donde estoy parado no esta aprovado directamente devuelvo false;
                    return false;
                }
               break;//Salir del bucle for, ya que encontramos el curso en Previas
            }
        }
        itI->next();    
    }
    return true;
};

//CU: Consultar Estadistica
set<DataCursoE*>Estudiante::cursosEstudiante(){
    IIterator* iti = this->Inscripciones->getIterator();
    set<DataCursoE*> DTCE;
    while(iti->hasCurrent()){
        float PCurso = ((Inscripcion*)iti->getCurrent())->getPromedio();
        string NCurso =(((Inscripcion*)iti->getCurrent())->getcurso())->getNomCurso();
        DTCE.insert(new DataCursoE(NCurso,PCurso));
    }
    delete iti;
    return DTCE;
}

//CU:Realizar Ejercicio
//Inscripcion*Estudiante::EncontrarInscripcion(std::string nCurso){
//    return (Inscripcion*)this->Inscripciones->find(new String(nCurso));
//};
set<std::string>Estudiante::PlantearProblemaE(std::string nomEjercicio, std::string nCurso){
    return ((Inscripcion*)this->Inscripciones->find(new String(nCurso.c_str())))->PlantearProblemaI(nomEjercicio);
};

bool Estudiante::IngresarSolucionE(std::string solucionDeUsuario,std::string nomEjercicio, std::string nCurso){
    return ((Inscripcion*)this->Inscripciones->find(new String(nCurso.c_str())))->IngresarSolucionI(solucionDeUsuario,nomEjercicio);
};
