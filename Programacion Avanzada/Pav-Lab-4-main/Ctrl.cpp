#include "Ctrl.h"

 
using namespace std;

Ctrl* Ctrl::instance = nullptr;

ICtrl* Ctrl::getInstance() {
    if (!instance) {
	    instance = new Ctrl();
    }
    return instance;
};

Ctrl::Ctrl() {
    this->Profesores=new OrderedDictionary();
    this->Cursos=new OrderedDictionary();
    this->estudiantes=new OrderedDictionary();
    this->idiomas=new OrderedDictionary();
};

Ctrl::~Ctrl() {};
IDictionary* Ctrl::getProfesores(){
    return this->Profesores;
};
IDictionary* Ctrl::getCursos(){
    return this->Cursos;
};

IDictionary* Ctrl::getEstudiantes(){
    return this->estudiantes;
};
IDictionary* Ctrl::getIdiomas(){
    return this->idiomas;
};

void Ctrl::clearSys(){
    system("cls");
}

//Agregar Leccion
Lecciones* Ctrl::ingresarLeccion(string NomTema, string Objetivo, Curso* c){
    //c es una instancia de Curso 
    return c->CrearLeccion(NomTema, Objetivo);

};

Curso* Ctrl::SeleccionarCursoNoHabilitado(string nCurso){
    IKey* IKC=new String(nCurso.c_str());
    return (Curso*)this->Cursos->find(IKC);
};//OK
void Ctrl::CrearEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Curso* cursoNH, Lecciones* leccionNH){
    cursoNH->AgregarEjercicio(NomEj,tipo,desc,frase,solucion,leccionNH);
};//OK

//CU: Alta de Curso
set<std::string> Ctrl::ListarProfesores(){
    //lista de strings
    set<std::string> Profesores;
    //consigo los profesores del ctrl
    IDictionary* profesoresCtrl=this->getProfesores();
    //consigo un iterador
    IIterator* it=profesoresCtrl->getIterator();

    //itero
    while(it->hasCurrent()){
        //casteo el iterador a profesor por cada instancia y guardo el nickname en la lista
        Profesores.insert(((Profesor*)it->getCurrent())->getNickname());
        it->next();
    };
    //saco la basura
    delete it;
    delete profesoresCtrl;
    //retorno la lista
    return Profesores;
};

Curso* Ctrl::IngresoCurso(std::string nickP , std::string nomCurso, std::string descCurso, DIFICULTAD difCurso){
    //consigo los profesores
    IDictionary* profesoresCtrl=this->getProfesores();
    //hago una IKey
    IKey* KeyProf = new String(nickP.c_str());
    //busco el profesor especifico
    Profesor * prof = (Profesor*)(profesoresCtrl->find(KeyProf));
    //creo un curso nuevo con los datos ingresados y el profesor encontrado, no tengo idioma asi que es NULL
    Curso* cursoNuevo = new Curso(nomCurso, descCurso, difCurso, false, NULL, prof);
    //llamo esta funcion para agregar el curso a la coleccion de cursos del profesor
    prof->asignarCursoAProfesor(cursoNuevo);
    //retorno el curso creado para usarlo en otras operaciones
    return cursoNuevo;
};

set<std::string> Ctrl::ListarIdiomas(Curso* cursoNuevo){
    set<std::string> IdiomasProf;
    Profesor* prof= (cursoNuevo->getProfesor());
    IdiomasProf=prof->buscarIdioma(prof);
    return IdiomasProf;
};

void Ctrl::SeleccionarIdiomaC(std::string idioma, Curso* cursoNuevo){
    IKey* KeyIdioma = new String(idioma.c_str());
    Idiomas* I= (Idiomas*)((this->idiomas)->find(KeyIdioma));
    cursoNuevo->asignarIdiomaACurso(I);
};

set<std::string> Ctrl::ListarCursosHabilitados(){
    //creo una lista de strings para retornar
    set<std::string> CursosH;
    //consigo todos los Cursos en el Ctrl y consigo un iterador en base a eso
    IIterator* it=(this->Cursos)->getIterator();
    
    //itero dentro del diccionario
    while(it->hasCurrent()){; 
        //casteo el iterador a Curso y pregunto si esta habilitado
        bool estaHabilitado=((Curso*)it->getCurrent())->getHabilitado();
        //si no esta habilitado, lo agrego a la lista
        if(estaHabilitado){
            CursosH.insert(((Curso*)it->getCurrent())->getNomCurso());
        };
        it->next();
    };
    //borro el iterador
    delete it;
    //retorno la lista
    return CursosH;
};

void Ctrl::SeleccionarPreviatura(std::string nCurso, Curso* cursoNuevo){
    //Creo una key del curso que quiero seleccionar como previa
    IKey* KeyCurso = new String(nCurso.c_str());
    //Busco el curso que quiero seleccionar como previa
    Curso* CursoPrevia = (Curso*)((this->Cursos)->find(KeyCurso));
    //Asigno el curso previo como previa del curso nuevo
    cursoNuevo->esPrevia(CursoPrevia);
    //Asigno el curso nuevo como posterior del curso previo
    CursoPrevia->miPrevia(cursoNuevo);
};

//CU: Alta de Usuario
void Ctrl::IngresoE(DTFecha* fecNac, std::string Nick , std::string Contrasenia , std::string Nom , std::string Desc , std::string Pais){
    //creo una key para identificar al estudiante
    IKey* KeyEstudiante = new String(Nick.c_str());
    //creo una instancia de estudiante
    Estudiante* estudianteNuevo = new Estudiante(Nick,Desc,Nom,Contrasenia,fecNac,Pais);
    //la agrego a la coleccion del controlador
    (this->estudiantes)->add(KeyEstudiante,(ICollectible*)estudianteNuevo);
};


Profesor* Ctrl::IngresoP(std::string Nick , std::string Contrasenia, std::string Nom, std::string Desc, std::string Instituto){
    //creo una key para identificar al profesor
    IKey* KeyProfesor = new String(Nick.c_str());
    //creo una instancia de profesor
    Profesor* profesorNuevo = new Profesor(Nick,Desc,Nom,Contrasenia,Instituto);
    //la agrego a la coleccion del controlador
    (this->Profesores)->add(KeyProfesor,(ICollectible*)profesorNuevo);
    //retorno el puntero para usar despues
    return profesorNuevo;
};

set<std::string> Ctrl::LisIdioma(){
    //creo una lista
    set<std::string> idiomasCtrl;
    //consigo un iterador para los idiomas
    IIterator* it=(this->idiomas)->getIterator();
    //itero
    while(it->hasCurrent()){
        //por cada idioma inserto su nombre en la lista
        idiomasCtrl.insert(((Idiomas*)it->getCurrent())->getNomIdioma());
        //siguiente en la iteracion
        it->next();
    }
    //borro el iterador
    delete it;
    //retorno la lista
    return idiomasCtrl;
};

void Ctrl::SelecIdioma(std::string idioma, Profesor* profesorNuevo){
    //hago una key para el idioma
    IKey* KeyIdioma = new String(idioma.c_str());
    //busco el idioma en el diccionario del controlador
    Idiomas* idiom = (Idiomas*)(this->idiomas)->find(KeyIdioma);
    //uso esta funcion para agregar el puntero del idioma al profesorNuevo
    profesorNuevo->aniadirIdioma(idiom);
};



//CU: Eliminar Curso
set<std::string> Ctrl::ListCurso(){
    //creo una lista
    set<std::string> cursosCtrl;
    //consigo un iterador para los cursos
    IIterator* it=(this->Cursos)->getIterator();
    //itero
    while(it->hasCurrent()){
        //por cada curso inserto su nombre en la lista
        cursosCtrl.insert(((Curso*)it->getCurrent())->getNomCurso());
        //siguiente en la iteracion
        it->next();
    }
    //borro el iterador
    delete it;
    //retorno la lista
    return cursosCtrl;
};

void Ctrl::EliminarCurso(std::string NomCurso){
    //hago una key para el idioma
    IKey* KeyCurso = new String(NomCurso.c_str());
    //busco el idioma en el diccionario del controlador
    Curso* curso = (Curso*)(this->Cursos)->find(KeyCurso);
    //esta operacion desliga/borra todo lo relacionado al curso
    curso->DeleteALLforCurso();

    //destruyo el curso
    curso->~Curso();
};

//CU: Agregar Ejercicio
set<std::string> Ctrl::ListarCursosNoHabilitados(){
    //creo una lista de strings para retornar
    set<std::string> CursosNH;
    //consigo todos los Cursos en el Ctrl y consigo un iterador en base a eso
    IIterator* it=(this->Cursos)->getIterator();
    
    //itero dentro del diccionario
    while(it->hasCurrent()){; 
        //casteo el iterador a Curso y pregunto si esta habilitado
        bool estaHabilitado=((Curso*)it->getCurrent())->getHabilitado();
        //si no esta habilitado, lo agrego a la lista
        if(!estaHabilitado){
            CursosNH.insert(((Curso*)it->getCurrent())->getNomCurso());
        };
        it->next();
    };
    //borro el iterador
    delete it;
    //retorno la lista
    return CursosNH;
};

Lecciones* Ctrl::SeleccionarLeccion(std::string nCurso,std::string nomLec){
    Curso* c = (Curso*)this->Cursos->find(new String(nCurso.c_str()));
    return c->GetLeccion(nomLec);
}

bool Ctrl::ExisteLec(std::string nCurso,std::string nomLec){
    return ((Curso*)this->Cursos->find(new String(nCurso.c_str())))->ExisteLecC(nomLec);
}

set<std::string> Ctrl::listarLecciones(std::string nCurso){
    //creo una lista para retornar
    set<std::string> Lecciones;
    //guardo el diccionario de los cursos del ctrl
    IDictionary* Cursos=this->getCursos();
    //declaro su IKey
    IKey* KeyCurso=new String(nCurso.c_str());
    //busco el curso mediante la IKey 
    Curso* curso=(Curso*)(Cursos->find(KeyCurso));
    //llamo a conseguirLecciones() y guardo su resultado en Lecciones
    Lecciones=curso->conseguirLecciones();

    //borro lo que no es necesario
    delete curso;
    delete Cursos;

    //retorno la lista
    return Lecciones;
}; 

//CU: Habilitar Curso
void Ctrl::HabilitarCurso(std::string nCurso){
    //guardo el diccionario de los cursos del ctrl
    IDictionary* Cursos=this->getCursos();
    //declaro su IKey
    IKey* KeyCurso=new String(nCurso.c_str());
    //busco el curso mediante la IKey 
    Curso* curso=(Curso*)(Cursos->find(KeyCurso));
    //llamo a habilitar
    curso->habilitar();
    //borro lo que sobra
    delete Cursos;
    delete curso;
};


//CU: Alta de Idioma
void Ctrl::IngresaIdioma(std::string stringIdioma){
    //creo una instancia de idioma
    Idiomas* idiom = new Idiomas(stringIdioma);
    //creo una key en base a lo que ingresa
    IKey* KeyIdioma = new String(stringIdioma.c_str());
    //agrego el idioma casteado como ICollectible junto a su key
    (this->idiomas)->add(KeyIdioma,(ICollectible*)idiom);
};



//CU: Consultar Curso
DataCurso2* Ctrl::listarInfoCurso(std::string nomCurso){
    IKey* keyCurso= new String(nomCurso.c_str());
    Curso* cursoDT=(Curso*)((this->Cursos)->find(keyCurso));
    
    std::string nombreC=cursoDT->getNomCurso();
    DIFICULTAD difC=cursoDT->getDificultad();
    std::string descC=cursoDT->getDesCurso();
    
    Idiomas* idi=cursoDT->getIdioma();
    std::string idiomaC=idi->getNomIdioma();

    Profesor* prof = cursoDT->getProfesor();
    std::string profC=prof->getNombre();

    bool habilitadoC=cursoDT->getHabilitado();

    set<DataLeccion*> dataLec;
    dataLec.clear();
    //DataLeccion incluye sets de los datatypes de cada ejercicio de la leccion tambien 
    if(cursoDT->getLecciones()!=NULL){
        set<DataLeccion*> dataLec = cursoDT->conseguirDataLeccion();
    }

    set<DataInscripciones2*> dataInsc;
    dataInsc.clear();
    if(cursoDT->getInscripciones()!=NULL){
        set<DataInscripciones2*> dataInsc = cursoDT->conseguirDataInsc2();
    }  
    

    DataCurso2* dataRetornar= new DataCurso2(nombreC,difC,descC,idiomaC,profC,habilitadoC,dataLec,dataInsc);
    return dataRetornar;
};

//CU: Inscribirse Curso
set<DataCurso3*> Ctrl::ListarCursosDisponibles(std::string Nickname,Estudiante* &E ){
    std::set<DataCurso3*> dataCursos;//Data que retornaremos
    //Creamos la llave para Estudiante
    IKey* IKE = new String(Nickname.c_str());
    IDictionary* Estudian= this->getEstudiantes();
    //Estud tiene la instancia del estudiante con Nickname
    Estudiante* Estud=(Estudiante*)(Estudian->find(IKE));//Punto 1
    E=Estud;
    //consigo todos los Cursos en el Ctrl y consigo un iterador en base a eso
    IIterator* itC=(this->Cursos)->getIterator();
    while(itC->hasCurrent()){//Punto 2
        Curso* C= (Curso*)itC->getCurrent();
        std::string nomCurso=C->getNomCurso();//Punto 3 Del DC
        bool curzado=Estud->haCursado(nomCurso);//Punto 4
        if(!curzado){
            set<std::string> Previas=C->DamePrevias();//Punto 5
           bool Disponibles=Estud->estanDisponibles(Previas);//Punto 6
            if(Disponibles){
                 // Obtener el DataCurso3 del curso actual
                DataCurso3* dataCurso = C->getDataCurso3(); // Asumiendo que getDataCurso3 devuelve un puntero a DataCurso3
                 // Insertar el DataCurso3 en el conjunto
                dataCursos.insert(dataCurso); // Insertar el objeto apuntado por dataCurso en el conjunto
                 // Liberar la memoria del objeto dataCurso si es necesario
                delete dataCurso;
            }
        }
        itC->next();
    }
   return dataCursos;

}
void Ctrl::SeleccionarCurso(std::string nomCurso,Estudiante* E){
    IKey* IKC=new String(nomCurso.c_str());
    IDictionary* cursos=this->getCursos();
    Curso* C=(Curso*)(cursos->find(IKC));
    DTFecha* Fecha= new DTFecha();
    Inscripcion* I=new Inscripcion(Fecha->obtenerFechaActual(),false,E,C);

    C->agregarInscripcionCurso(I);//Listo
    E->agregarInscripcionEstudiante(I);

};
//CU: Consultar Estadisticas
set<std::string>Ctrl::ListEstudiantes(){
    set<std::string> Est;
    IIterator* ite = this->estudiantes->getIterator();
    while(ite->hasCurrent()){
        Est.insert(((Estudiante*)ite->getCurrent())->getNickname());
        ite->next();
    }
    delete ite;
    return Est;
};

set<DataCursoE*>Ctrl::ListCursosE(std::string Nick){
    IKey* ike = new String(Nick.c_str());
    Estudiante* est = (Estudiante*)this->estudiantes->find(ike);
    set<DataCursoE*> listaCursos = est->cursosEstudiante();
    return listaCursos;
};

set<DataCursoP*>Ctrl::ListCursosP(std::string Nick){
    IKey* ikp = new String(Nick.c_str());
    Profesor* prof = (Profesor*)this->Profesores->find(ikp);
    return prof->cursosProfesor();
};

set<std::string>Ctrl::ListCursos(){
    set<std::string> Curs;
    IIterator* itc = this->Cursos->getIterator();
    while(itc->hasCurrent()){
        Curs.insert(((Curso*)itc->getCurrent())->getNomCurso());
        itc->next();
    }
    delete itc;
    return Curs;
};

DataCurso*Ctrl::verInfoCurso(std::string NomCurso){
    
    return ((Curso*)this->Cursos->find(new String(NomCurso.c_str())))->getDataCurso();
};

//CU: Realizar Ejercicio
Estudiante*Ctrl::SeleccionarEst(std::string Unick){
    return (Estudiante*)this->estudiantes->find(new String(Unick.c_str()));
};

set<std::string>Ctrl::ListarEjercicios(std::string nCurso, Estudiante* e){
    return((Inscripcion*)e->getInscripciones()->find(new String(nCurso.c_str())))->conseguirEjerPendientes();

};

set<std::string>Ctrl::PlantearProblema(std::string nomEjercicio, std::string nCurso, Estudiante* e){
    return e->PlantearProblemaE(nomEjercicio,nCurso);
};

bool Ctrl::IngresarSolucion(std::string solucionDeUsuario,std::string nomEjercicio, std::string nCurso, Estudiante* e){
    return e->IngresarSolucionE(solucionDeUsuario,nomEjercicio,nCurso);
};

//CU: Consultar Idioma
set<std::string> Ctrl::muestroIdioma(){
    set<std::string> nomIdomas;
    IIterator* itI=this->idiomas->getIterator();
    Idiomas* Idi;
    while(itI->hasCurrent()){
        Idi=(Idiomas*)itI->getCurrent();
        nomIdomas.insert(Idi->getNomIdioma());
        itI->next();
    }
    return nomIdomas;
};
//CU: Consultar Usuario
set<std::string> Ctrl::ListNickUsuarios(){//Consigo los nicks de todos los usuarios
    set<std::string> nickUser;//set que contendra los nick tanto de profesor como de estudiante
    IIterator* itE=this->estudiantes->getIterator();
    IIterator* itP=this->Profesores->getIterator();
    Estudiante* nickE;
    Profesor* nickP;
    while(itE->hasCurrent()){
        nickE=(Estudiante*)itE->getCurrent();
        nickUser.insert(nickE->getNickname());
        itE->next();
    }
    delete nickE;
    delete itE;
    while(itP->hasCurrent()){
        nickP=(Profesor*)itP->getCurrent();
        nickUser.insert(nickP->getNickname());
        itP->next();
    }
    delete nickP;
    delete itP;
    return nickUser;
};

DataUsuario* Ctrl::DatosUser(std::string nick){
    // Buscar el estudiantes
    IKey* IKE=new String(nick.c_str());
    Estudiante* E=(Estudiante*)(estudiantes->find(IKE));
    if(E!=nullptr){
        DataEst* dataE= new DataEst(E->getfecNac(),E->getPais());
        DataUsuario* newDataUser=new DataUsuario(E->getNickname(), E->getDescripcion(), E->getNombre(), E->getContrasenia(), nullptr, dataE);
        return newDataUser;
    }else{
        IKey* IKP=new String(nick.c_str());
        Profesor* P=(Profesor*)(Profesores->find(IKP));
         if(P!=nullptr){
            DataProfesor* dataP= new DataProfesor(P->getinstituto(), P->getIdiomas());
            DataUsuario* newDataUser=new DataUsuario(P->getNickname(), P->getDescripcion(), P->getNombre(), P->getContrasenia(), dataP, nullptr);
            return newDataUser;
         }
    }
    return nullptr;
};

//cargar datos
void Ctrl::UnlimitedVoid(){
    std::string nada;
    std::string nombreIdioma;
    std::cout<<"Cargando Idiomas..."<<endl;
    getchar();
    
    Idiomas* I1 = new Idiomas(nombreIdioma="Ingles");
    IKey* KeyI1 = new String(nombreIdioma.c_str());
    (this->idiomas)->add(KeyI1,(ICollectible*) I1);

    Idiomas* I2 = new Idiomas(nombreIdioma="Aleman");
    IKey* KeyI2 = new String(nombreIdioma.c_str());
    (this->idiomas)->add(KeyI2,(ICollectible*) I2);
    
    Idiomas* I3 = new Idiomas(nombreIdioma="Portugues");
    IKey* KeyI3 = new String(nombreIdioma.c_str());
    (this->idiomas)->add(KeyI3,(ICollectible*) I3);


    std::string nickUsuario;
    std::string nombreUsuario;
    std::string passUsuario;
    std::string descUsuario;
    std::string paisEstudiante;
    std::string institutoProfesor;

    std::cout<<"Cargando Estudiantes..."<<endl;
    getchar();

    Estudiante* U1 = new Estudiante(nickUsuario="jpidiom", descUsuario="Soy un apasionado del aprendizaje de idiomas.", nombreUsuario="Juan Perez", passUsuario="1234", new DTFecha(15,7,1995), paisEstudiante="Argentina");
    IKey* KeyU1 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU1,(ICollectible*)U1);

    Estudiante* U2 = new Estudiante(nickUsuario="marsilva", descUsuario="Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", nombreUsuario="Maria Silva", passUsuario="1234", new DTFecha(28,2,1998), paisEstudiante="Ecuador");
    IKey* KeyU2 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU2,(ICollectible*)U2);

    Estudiante* U3 = new Estudiante(nickUsuario="pero12", descUsuario="Soy un entusiasta del aprendizaje de idiomas.", nombreUsuario="Pedro Rodriguez ", passUsuario="1234", new DTFecha(10,11,1994), paisEstudiante="Peru");
    IKey* KeyU3 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU3,(ICollectible*)U3);

    Estudiante* U4 = new Estudiante(nickUsuario="laugu", descUsuario="Estoy fascinada por la forma en que las palabras pueden unir a las personas", nombreUsuario="Laura Gutierrez", passUsuario="1234", new DTFecha(22,4,1997), paisEstudiante="Chile");
    IKey* KeyU4 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU4,(ICollectible*)U4);

    Estudiante* U5 = new Estudiante(nickUsuario="carlo22", descUsuario="Emocionado por adquirir fluidez en diferentes lenguas.", nombreUsuario="Carlos Lopez", passUsuario="1234", new DTFecha(03,9,1996), paisEstudiante="Uruguay");
    IKey* KeyU5 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU5,(ICollectible*)U5);

    Estudiante* U6 = new Estudiante(nickUsuario="anator", descUsuario="Disfruto de la belleza de las diferentes estructuras y sonidos.", nombreUsuario="Ana Torres", passUsuario="1234", new DTFecha(12,1,1999 ), paisEstudiante="Argentina");
    IKey* KeyU6 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU6,(ICollectible*)U6);

    Estudiante* U7 = new Estudiante(nickUsuario="luher24", descUsuario="Emocionada en la riqueza cultural que cada idioma ofrece", nombreUsuario="Lucia Hernandez", passUsuario="1234", new DTFecha(25,6,1993), paisEstudiante="Colombia");
    IKey* KeyU7 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU7,(ICollectible*)U7);

    Estudiante* U8 = new Estudiante(nickUsuario="dagon", descUsuario="Soy un apasionado del aprendizaje de idiomas.", nombreUsuario="David Gonzalez", passUsuario="1234", new DTFecha(15,7,1995), paisEstudiante="Argentina");
    IKey* KeyU8 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU8,(ICollectible*)U8);

    Estudiante* U9 = new Estudiante(nickUsuario="carmor", descUsuario="El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", nombreUsuario="Carmen Morales", passUsuario="1234", new DTFecha(17,3,1995), paisEstudiante="Chile");
    IKey* KeyU9 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU9,(ICollectible*)U9);

    Estudiante* U10 = new Estudiante(nickUsuario="jose24", descUsuario="Disfruto del proceso de descubrir nuevas formas de comunicarme", nombreUsuario="Jose Fernandez", passUsuario="1234", new DTFecha(2,8,1998 ), paisEstudiante="Bolivia");
    IKey* KeyU10 = new String(nickUsuario.c_str());
    (this->estudiantes)->add(KeyU10,(ICollectible*)U10);

    std::cout<<"Cargando Profesores..."<<endl;
    getchar();
    Profesor* U11 = new Profesor(nickUsuario="langMaster", descUsuario="Soy una profesora apasionada por los idiomas.", nombreUsuario="Marta Grecia", passUsuario="1234", institutoProfesor="Instituto de Idiomas Moderno");
    IKey* KeyU11 = new String(nickUsuario.c_str());
    (this->Profesores)->add(KeyU11,(ICollectible*)U11);
    U11->aniadirIdioma(I1);
    U11->aniadirIdioma(I3);
    
    Profesor* U12 = new Profesor(nickUsuario="linguaPro", descUsuario="Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", nombreUsuario="Carlos Petro", passUsuario="1234", institutoProfesor="Centro Global");
    IKey* KeyU12 = new String(nickUsuario.c_str());
    (this->Profesores)->add(KeyU12,(ICollectible*)U12);
    U12->aniadirIdioma(I1);
    U12->aniadirIdioma(I2);
    U12->aniadirIdioma(I3);

    Profesor* U13 = new Profesor(nickUsuario="talkExpert", descUsuario="Soy una profesora entusiasta del aprendizaje de idiomas", nombreUsuario="Laura Perez", passUsuario="1234", institutoProfesor="Instituto de Idiomas Vanguardia");
    IKey* KeyU13 = new String(nickUsuario.c_str());
    (this->Profesores)->add(KeyU13,(ICollectible*)U13);
    U13->aniadirIdioma(I2);

    Profesor* U14 = new Profesor(nickUsuario="lingoSensei", descUsuario="Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", nombreUsuario="Franco Lopez", passUsuario="1234", institutoProfesor="Centro de Idiomas");
    IKey* KeyU14 = new String(nickUsuario.c_str());
    (this->Profesores)->add(KeyU14,(ICollectible*)U14);
    U14->aniadirIdioma(I3);

    Profesor* U15 = new Profesor(nickUsuario="wordMaestro", descUsuario="Soy una profesora comprometida en desarrollo de habilidades idiomaticas", nombreUsuario="Ana Morales", passUsuario="1234", institutoProfesor="Instituto de Idiomas Progreso");
    IKey* KeyU15 = new String(nickUsuario.c_str());
    (this->Profesores)->add(KeyU15,(ICollectible*)U15);
    U15->aniadirIdioma(I1);

    std::string nombreCurso;
    std::string descCurso;
    
    std::cout<<"Cargando Cursos..."<<endl;
    getchar();

    Curso* C1 = new Curso(nombreCurso="Ingles para principiantes",descCurso="Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", principiante, true, I1, U11);
    IKey* KeyC1 = new String(nombreCurso.c_str());
    this->Cursos->add(KeyC1,(ICollectible*)C1);

    Curso* C2 = new Curso(nombreCurso="Curso de Ingles basico",descCurso="Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral", principiante, false, I1, U11);
    IKey* KeyC2 = new String(nombreCurso.c_str());
    this->Cursos->add(KeyC2,(ICollectible*)C2);

    Curso* C3 = new Curso(nombreCurso="Ingles intermedio: mejora tu nivel",descCurso="Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en lafluidez oral, lectura comprensiva y escritura.", medio, true, I1, U12);
    IKey* KeyC3 = new String(nombreCurso.c_str());
    this->Cursos->add(KeyC3,(ICollectible*)C3);

    Curso* C4 = new Curso(nombreCurso="Curso avanzado de ingles",descCurso="Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", avanzado, true, I1, U12);
    IKey* KeyC4 = new String(nombreCurso.c_str());
    this->Cursos->add(KeyC4,(ICollectible*)C4);

    Curso* C5 = new Curso(nombreCurso="Portugues intermedio",descCurso="Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva", medio, true, I3, U12);
    IKey* KeyC5 = new String(nombreCurso.c_str());
    this->Cursos->add(KeyC5,(ICollectible*)C5);

    Curso* C6 = new Curso(nombreCurso="Portugues avanzado",descCurso="Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", avanzado, false, I3, U14);
    IKey* KeyC6 = new String(nombreCurso.c_str());
    this->Cursos->add(KeyC6,(ICollectible*)C6);

    std::cout<<"Asignando Previas..."<<endl;
    getchar();

    //las previas y posteriores estan en privado, asi que uso esta funcion
    C3->esPrevia(C1); //C1 es previa de C3
    C1->miPrevia(C3); //C3 es posterior de C1

    C4->esPrevia(C1); //C1 es previa de C4
    C1->miPrevia(C4); //C4 es posterior de C1

    C4->esPrevia(C3); //C3 es previa de C4
    C3->miPrevia(C4); //C4 es posterior de C3

    C6->esPrevia(C5); //C5 es previa de C6
    C5->miPrevia(C6); //C6 es posterior de C5

    std::string temaLec;
    std::string objLec;

    std::cout<<"Cargando Lecciones..."<<endl;
    getchar();
    Lecciones* L1 = C1->CrearLeccion(temaLec="Saludos y Presentaciones", objLec="Aprender a saludar y despedirse");
   
    Lecciones* L2 = C1->CrearLeccion(temaLec="Artículos y Plurales", objLec="Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");

    Lecciones* L3 = C2->CrearLeccion(temaLec="Actividades Cotidianas ", objLec="Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
    
    Lecciones* L4 = C2->CrearLeccion(temaLec="Presente Simple", objLec="Aprender el uso del presente simple");
    nada=L4->getTema();

    Lecciones* L5 = C3->CrearLeccion(temaLec="Conversaciones cotidianas", objLec="Aprender a hacer preguntas y respuestas en situaciones comunes");

    Lecciones* L6 = C4->CrearLeccion(temaLec="Uso de modales avanzados", objLec="Explorar el uso de los modales complejos");
    
    Lecciones* L7 = C5->CrearLeccion(temaLec="Lectura y comprension de textos", objLec="Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");


    std::string nomEjer;
    std::string tipoEjer;
    std::string descEjer;
    std::string fraseEjer;
    std::string solEjer;
    
    std::cout<<"Cargando Ejercicios..."<<endl;
    getchar();

    L1->CrearEjer(nomEjer="E1",tipoEjer="Traducir",descEjer="Presentaciones", fraseEjer="Mucho gusto en conocerte", solEjer="Nice to meet you");
    IKey* keyE1 = new String(nomEjer.c_str());
    deTraducir* E1 = L1->conseguirDT(keyE1);

    L1->CrearEjer(nomEjer="E2",tipoEjer="Completar",descEjer="Presentaciones formales", fraseEjer="Please --- me to introduce ---", solEjer="allow --- myself");
    IKey* keyE2 = new String(nomEjer.c_str());
    deCompletar* E2 = L1->conseguirDC(keyE2);

    L2->CrearEjer(nomEjer="E3",tipoEjer="Traducir",descEjer="Plurales regulares", fraseEjer="I have two brothers and three sisters", solEjer="Tengo dos hermanos y tres hermanas");
    IKey* keyE3 = new String(nomEjer.c_str());
    deTraducir* E3 = L2->conseguirDT(keyE3);

    L2->CrearEjer(nomEjer="E4",tipoEjer="Completar",descEjer="Sustantivos contables en plural", fraseEjer="Can I have --- water, please?", solEjer="some");
    IKey* keyE4 = new String(nomEjer.c_str());
    deCompletar* E4 = L2->conseguirDC(keyE4);

    L3->CrearEjer(nomEjer="E5",tipoEjer="Completar",descEjer="Actividades diarias", fraseEjer="Wake ---", solEjer="Wake");
    IKey* keyE5 = new String(nomEjer.c_str());
    deCompletar* E5 = L3->conseguirDC(keyE5);
    nada=E5->getdescripcion();

    L5->CrearEjer(nomEjer="E6",tipoEjer="Completar",descEjer="Consultas de la hora", fraseEjer="Q: Do you --- the time?, A: Yes, it is half --- 4", solEjer="have --- past");
    IKey* keyE6 = new String(nomEjer.c_str());
    deCompletar* E6 = L5->conseguirDC(keyE6);

    L6->CrearEjer(nomEjer="E7",tipoEjer="Traducir",descEjer="Dar consejos o expresar obligacion", fraseEjer="You should visit that museum", solEjer="Deberias visitar ese museo");
    IKey* keyE7 = new String(nomEjer.c_str());
    deTraducir* E7 = L6->conseguirDT(keyE7);
    nada=E7->getdescripcion();

    L7->CrearEjer(nomEjer="E8",tipoEjer="Traducir",descEjer="Imperativo", fraseEjer="Fale comigo", solEjer="Habla conmigo");
    IKey* keyE8 = new String(nomEjer.c_str());
    deTraducir* E8 = L7->conseguirDT(keyE8);
    nada=E8->getdescripcion();

    std::cout<<"Cargando Inscripciones..."<<endl;
    getchar();

    Inscripcion* N1 = new Inscripcion(new DTFecha (1,1,2022), false, U1, C1);
    U1->agregarInscripcionEstudiante(N1);
    C1->agregarInscripcionCurso(N1);

    Inscripcion* N2 = new Inscripcion(new DTFecha (12,6,2022), false, U1, C3);
    U1->agregarInscripcionEstudiante(N2);
    C3->agregarInscripcionCurso(N2);

    Inscripcion* N3 = new Inscripcion(new DTFecha (2,3,2023), false, U1, C4);
    U1->agregarInscripcionEstudiante(N3);
    C4->agregarInscripcionCurso(N3);

    Inscripcion* N4 = new Inscripcion(new DTFecha (2,1,2022), false, U2, C1);
    U2->agregarInscripcionEstudiante(N4);
    C1->agregarInscripcionCurso(N4);

    Inscripcion* N5 = new Inscripcion(new DTFecha (2,1,2022), false, U3, C1);
    U3->agregarInscripcionEstudiante(N5);
    C1->agregarInscripcionCurso(N5);

    Inscripcion* N6 = new Inscripcion(new DTFecha (3,1,2023), false, U4, C1);
    U4->agregarInscripcionEstudiante(N6);
    C1->agregarInscripcionCurso(N6);

    Inscripcion* N7 = new Inscripcion(new DTFecha (3,1,2023), false, U4, C5);
    U4->agregarInscripcionEstudiante(N7);
    C5->agregarInscripcionCurso(N7);

    Inscripcion* N8 = new Inscripcion(new DTFecha (5,1,2023), false, U5, C5);
    U5->agregarInscripcionEstudiante(N8);
    C5->agregarInscripcionCurso(N8);

    //primer puntero significa deTraducir, segundo deCompletar
    N1->aprobadoAutomatico(E1,nullptr);
    N1->aprobadoAutomatico(nullptr,E2); 
    N1->aprobadoAutomatico(E3,nullptr);
    N1->aprobadoAutomatico(nullptr,E4);
    //n1->aprovado=true
    N1->aprobarInsc();
    
    N2->aprobadoAutomatico(nullptr,E6);
    //n2->aprovado=true
    N2->aprobarInsc();
    
    N4->aprobadoAutomatico(E1,nullptr);
    N4->aprobadoAutomatico(nullptr,E2);

    N5->aprobadoAutomatico(E1,nullptr);
    N5->aprobadoAutomatico(nullptr,E2);
    N5->aprobadoAutomatico(nullptr,E4);
};