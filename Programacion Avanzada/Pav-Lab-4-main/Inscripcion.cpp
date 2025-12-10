#include "Inscripcion.h"
#include "Curso.h"
#include <sstream> 
#include <vector>

Inscripcion::Inscripcion(DTFecha* fechaInscrI, bool aprovadoI, Estudiante* estudianteI, Curso* cursoI){
    this->fechaInscr=fechaInscrI;
    this->aprovado=aprovadoI;
    this->estudiante=estudianteI;
    this->curso=cursoI;
    this->UltimaLec = nullptr;
	this->EjerCompletados = new OrderedDictionary();
};
// Implementación del setter para UltimaLec
void Inscripcion::asignarUltimaLec(Lecciones* leccion) {
    UltimaLec = leccion;
};
Inscripcion::Inscripcion(){};

Inscripcion::~Inscripcion(){};

DTFecha* Inscripcion::getfechaInscr(){
    return this->fechaInscr;
};

bool Inscripcion::getaprovado(){
    return this->aprovado;
};

Estudiante* Inscripcion::getestudiante(){
    return this->estudiante;
};

Curso* Inscripcion::getcurso(){
    return this->curso;
};

void Inscripcion::desligarEstudiante(){
    //llamo a esta funcion para que el estudiante quite la inscripcion de su diccionario
    this->estudiante->olvidarInscripcion(this);
    //dejo el puntero al estudiante en NULL
    this->estudiante=nullptr;
};

//CU: Consultar Curso
std::string Inscripcion::devolverNomEstudiante(){
    return (this->estudiante)->getNombre();
};


//cargar datos
void Inscripcion::aprobadoAutomatico(deTraducir* DT, deCompletar* DC){
    if(DT!=nullptr){
        IKey* keyDT = new String((DT->getnomEjercicio()).c_str());
        this->EjerCompletados->add(keyDT,(ICollectible*)DT);
    } else{
        IKey* keyDC = new String((DC->getnomEjercicio()).c_str());
        this->EjerCompletados->add(keyDC,(ICollectible*)DC);
    }
};

void Inscripcion::aprobarInsc(){
    this->aprovado=true;
};
//CU: Inscribirse Curso
bool Inscripcion::verificarInscripcion(std::string NomCurso){
    if(this->curso->getNomCurso() == NomCurso){
        return true;
    }
    return false;
};

//CU: Consultar Estadistica
float Inscripcion::getPromedio(){
    int ejerCurso = 0;
    IIterator* itc =(this->curso->getLecciones())->getIterator();
    while(itc->hasCurrent()){
        ejerCurso += ((Lecciones*)itc->getCurrent())->getdeCompletar()->getSize();
        ejerCurso += ((Lecciones*)itc->getCurrent())->getdeTraducir()->getSize();
        itc->next();
    }
    delete itc;
    return ((this->EjerCompletados->getSize())/ejerCurso)*100;
}

//CU:Realizar Ejercicio
set<std::string> Inscripcion::conseguirEjerPendientes(){
    set<std::string> EjerPendientes;
    IIterator* ite = (this->UltimaLec->getdeCompletar())->getIterator();
    while(ite->hasCurrent()){
        if((this->EjerCompletados->find(new String(((Ejercicio*)ite->getCurrent())->getnomEjercicio().c_str())))!=NULL){
            EjerPendientes.insert(((Ejercicio*)ite->getCurrent())->getnomEjercicio());
        }
        ite->next();
    }
    ite = (this->UltimaLec->getdeTraducir())->getIterator();
    while(ite->hasCurrent()){
        if((this->EjerCompletados->find(new String(((Ejercicio*)ite->getCurrent())->getnomEjercicio().c_str())))!=NULL){
            EjerPendientes.insert(((Ejercicio*)ite->getCurrent())->getnomEjercicio());
        }
        ite->next();
    }
    delete ite;
    return EjerPendientes;
};

set<std::string> Inscripcion::PlantearProblemaI(std::string nomEjercicio){
    deCompletar* DC = NULL;
    DC =  (deCompletar*)this->UltimaLec->getdeCompletar()->find(new String(nomEjercicio.c_str()));
    set<std::string>sol;
    if(DC != NULL){
        sol.insert(DC->getfraseC());
        sol.insert(DC->getdescripcion());
    }
    else{
        deTraducir* DT = (deTraducir*)this->UltimaLec->getdeTraducir()->find(new String(nomEjercicio.c_str()));
        sol.insert(DT->getfraseT());
        sol.insert(DT->getdescripcion());
    }
    return sol;
};

bool Inscripcion::IngresarSolucionI(std::string solucionDeUsuario,std::string nomEjercicio){
    deCompletar* DC = NULL;
    DC = (deCompletar*)this->UltimaLec->getdeCompletar()->find(new String(nomEjercicio.c_str()));
    if(DC != NULL){
        std::stringstream ss(solucionDeUsuario);// Crea un stringstream inicializado con la cadena solucion
        std::vector<std::string> tokens;// Vector para almacenar los tokens
        std::string delimiter = "---";// Delimitador para dividir la cadena
        size_t pos = 0;  // Posición del delimitador
        std::string token; // Variable para almacenar cada token
         // Extraer tokens de la cadena solucion usando el delimitador "---"
        while ((pos = solucionDeUsuario.find(delimiter)) != std::string::npos) {
            token = solucionDeUsuario.substr(0, pos);// Extrae el token desde el inicio hasta pos
            tokens.push_back(token);// Añade el token al vector tokens
            solucionDeUsuario.erase(0, pos + delimiter.length());// Borra el token y el delimitador de solucion
        }
        // Añadir el último token
        tokens.push_back(solucionDeUsuario);

        std::set<std::string> Solc;// Conjunto para almacenar las soluciones únicas
        // Insertar todos los tokens en el conjunto Solc para garantizar que sean únicos
        for (const auto& Seg : tokens) {
            Solc.insert(Seg);
        }
        if(Solc == DC->getfaltante()){
            this->EjerCompletados->add(new String(DC->getnomEjercicio().c_str()),(ICollectible*)DC);
            return true;
        }
    }
    else{
        deTraducir* DT =(deTraducir*)this->UltimaLec->getdeTraducir()->find(new String(nomEjercicio.c_str()));
        if(DT->gettraduccion() == solucionDeUsuario){
            this->EjerCompletados->add(new String(DT->getnomEjercicio().c_str()),(ICollectible*)DT);
            return true;
        }
    }
    return false;
};
