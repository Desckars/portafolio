#ifndef CTRL_H
#define CTRL_H
#include "ICtrl.h"
#include "Curso.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "Inscripcion.h"
//algo
#include "Idiomas.h"
#include "DataCurso2.h"
#include "DataLeccion.h"
#include "DataCurso3.h"
#include "DataCursoE.h"
#include "DataCursoP.h"
#include "DataCurso.h"
#include "DataUsuario.h"
#include "DTFecha.h"
#include "Usuario.h"
#include "Lecciones.h"
#include <string>
#include <set>
#include <iostream>
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"
using namespace std;

class Ctrl: public ICtrl{
    private:
        Ctrl();
        static Ctrl* instance;
        IDictionary* Cursos;
        IDictionary* Profesores;
        IDictionary* estudiantes;
        IDictionary* idiomas; 

    public:
        
        static ICtrl* getInstance();
        virtual ~Ctrl();
        IDictionary* getCursos();
        IDictionary* getProfesores();
        IDictionary* getEstudiantes();
        IDictionary* getIdiomas();
        void clearSys();
        //CU: Alta de Curso
        set<std::string> ListarProfesores();
        Curso* IngresoCurso(std::string nickP , std::string nomCurso, std::string descCurso, DIFICULTAD difCurso);
        set<std::string> ListarIdiomas(Curso* cursoNuevo);
        void SeleccionarIdiomaC(std::string idioma, Curso* cursoNuevo);
        set<std::string> ListarCursosHabilitados();
        void SeleccionarPreviatura(std::string nCurso, Curso* cursoNuevo);
        

        //CU: Alta de Usuario
        void IngresoE(DTFecha* fecNac, std::string Nick , std::string Contrasenia , std::string Nom , std::string Desc , std::string Pais);
        Profesor* IngresoP(std::string Nick , std::string Contrasenia, std::string Nom, std::string Desc, std::string Instituto);
        set<std::string> LisIdioma();
        void SelecIdioma(std::string idioma, Profesor* profesorNuevo);

        //CU: Agregar Ejercicio
        set<std::string> listarLecciones(std::string nCurso);
        Lecciones* SeleccionarLeccion(std::string nCurso,std::string nomLec);
        set<std::string> ListarCursosNoHabilitados();
        bool ExisteLec(std::string nCurso,std::string nomLec);

        //Agregar Leccion
        Lecciones* ingresarLeccion(string NomTema, string Objetivo, Curso* c);//OK
        Curso* SeleccionarCursoNoHabilitado(std::string nCurso);//OK
        void CrearEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Curso* cursoNH, Lecciones* leccionNH);//OK
        
        //CU: Eliminar Curso
        set<std::string> ListCurso();
        void EliminarCurso(std::string NomCurso);
        
        //CU: Habilitar Curso
        void HabilitarCurso(std::string nCurso);

        //CU: Alta Idioma
        void IngresaIdioma(std::string stringIdioma);

        //CU: Consultar Curso
        DataCurso2* listarInfoCurso(std::string nomCurso);

        
        //CU: Inscribirse Curso
        set<DataCurso3*> ListarCursosDisponibles(std::string Nickname,Estudiante* &E);
        void SeleccionarCurso(std::string nomCurso,Estudiante* E);

        //CU: Consultar Estadisticas
        set<std::string> ListEstudiantes();
        set<DataCursoE*> ListCursosE(std::string Nick);
        //Se usa ListarProfesores de CU Alta Curso
        set<DataCursoP*> ListCursosP(std::string Nick);
        set<std::string> ListCursos();
        DataCurso* verInfoCurso(std::string NomCurso);

        //CU: Realizar Ejericio
        //ListCursosE de CU Consultar Estadistica
        Estudiante* SeleccionarEst(std::string Unick);
        set<std::string> ListarEjercicios(std::string nCurso, Estudiante* e);
        set<std::string> PlantearProblema(std::string nomEjercicio, std::string nCurso, Estudiante* e);
        bool IngresarSolucion(std::string solucionDeUsuario,std::string nomEjercicio, std::string nCurso, Estudiante* e);


        //CU: Consultar Idioma
       set<std::string> muestroIdioma();//Muestrea TODOS los Idiomas exsistentes

       //CU: Consultar Usuario
       set<std::string> ListNickUsuarios();
       DataUsuario* DatosUser(std::string nick);

       
       
       
       
       
        void UnlimitedVoid();
};

#endif