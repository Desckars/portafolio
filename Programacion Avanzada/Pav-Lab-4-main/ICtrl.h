#ifndef ICTRL_H
#define ICTRL_H

#include "Curso.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "Idiomas.h"
#include "DataCurso2.h"
#include "DataLeccion.h"
#include "DataCurso3.h"
#include "DataCursoE.h"
#include "DataCursoP.h"
#include "DataCurso.h"
#include "Inscripcion.h"
#include "DataUsuario.h"
#include "Usuario.h"
#include "Lecciones.h"
#include <string>
#include <set>
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"
using namespace std;

class ICtrl{
    private:
    public:
        virtual IDictionary* getCursos() = 0;
        virtual IDictionary* getProfesores() = 0;
        virtual IDictionary* getEstudiantes() = 0;
        virtual IDictionary* getIdiomas() = 0;
        virtual void clearSys() = 0;
        //CU: Alta de Curso
        virtual set<std::string> ListarProfesores() = 0;
        virtual Curso* IngresoCurso(std::string nickP , std::string nomCurso, std::string descCurso, DIFICULTAD difCurso) = 0;
        virtual set<std::string> ListarIdiomas(Curso* cursoNuevo) = 0;
        virtual void SeleccionarIdiomaC(std::string idioma, Curso* cursoNuevo) = 0;
        virtual set<std::string> ListarCursosHabilitados() = 0;
        virtual void SeleccionarPreviatura(std::string nCurso, Curso* cursoNuevo) = 0;
        

        //CU: Alta de Usuario
        virtual void IngresoE(DTFecha* fecNac, std::string Nick , std::string Contrasenia , std::string Nom , std::string Desc , std::string Pais) = 0;
        virtual Profesor* IngresoP(std::string Nick , std::string Contrasenia, std::string Nom, std::string Desc, std::string Instituto) = 0;
        virtual set<std::string> LisIdioma() = 0;
        virtual void SelecIdioma(std::string idioma, Profesor* profesorNuevo) = 0;

        //CU: Agregar Ejercicio
        virtual set<std::string> listarLecciones(std::string nCurso) = 0; 

        //Agregar Leccion
        virtual Lecciones* ingresarLeccion(string NomTema, string Objetivo, Curso* c) = 0;//OK
        virtual Curso* SeleccionarCursoNoHabilitado(std::string nCurso) = 0;//OK
        virtual void CrearEjercicio(std::string NomEj, std::string tipo,std::string desc,std::string frase,std::string solucion, Curso* cursoNH, Lecciones* leccionNH) = 0;//OK
        
        //CU: Eliminar Curso
        virtual set<std::string> ListCurso() = 0;
        virtual void EliminarCurso(std::string NomCurso) = 0;
        
        //CU: Agregar Ejercicio
        virtual set<std::string> ListarCursosNoHabilitados() = 0;
        virtual Lecciones* SeleccionarLeccion(std::string nCurso,std::string nomLec) = 0;
        virtual bool ExisteLec(std::string nCurso,std::string nomLec) = 0;

        //CU: Habilitar Curso
        virtual void HabilitarCurso(std::string nCurso) = 0;

        //CU: Alta Idioma
        virtual void IngresaIdioma(std::string stringIdioma) = 0;

        //CU: Consultar Curso
        virtual DataCurso2* listarInfoCurso(std::string nomCurso) = 0;

        
        //CU: Inscribirse Curso
        virtual set<DataCurso3*> ListarCursosDisponibles(std::string Nickname,Estudiante* &E) = 0;
        virtual void SeleccionarCurso(std::string nomCurso,Estudiante* E) = 0;

        //CU: Consultar Estadisticas
        virtual set<std::string> ListEstudiantes() = 0;
        virtual set<DataCursoE*> ListCursosE(std::string Nick) = 0;
        //Se usa ListarProfesores de CU Alta Curso
        virtual set<DataCursoP*> ListCursosP(std::string Nick) = 0;
        virtual set<std::string> ListCursos() = 0;
        virtual DataCurso* verInfoCurso(std::string NomCurso) = 0;

        //CU: Realizar Ejericio
        //ListCursosE de CU Consultar Estadistica
        virtual Estudiante* SeleccionarEst(std::string Unick) = 0;
        virtual set<std::string> ListarEjercicios(std::string nCurso, Estudiante* e) = 0;
        virtual set<std::string> PlantearProblema(std::string nomEjercicio, std::string nCurso, Estudiante* e) = 0;
        virtual bool IngresarSolucion(std::string solucionDeUsuario,std::string nomEjercicio, std::string nCurso, Estudiante* e) = 0;


        //CU: Consultar Idioma
       virtual set<std::string> muestroIdioma() = 0;//Muestrea TODOS los Idiomas exsistentes

       //CU: Consultar Usuario
       virtual set<std::string> ListNickUsuarios() = 0;
       virtual DataUsuario* DatosUser(std::string nick) = 0;

       
       
       
       
       
        virtual void UnlimitedVoid() = 0;

};

#endif