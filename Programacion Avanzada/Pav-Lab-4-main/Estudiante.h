
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "DTFecha.h"
#include "Usuario.h"
#include "Lecciones.h"
#include "DataCursoE.h"
class Curso;
class Inscripcion;
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/String.h"
#include "ICollection/Integer.h"

//class Inscripcion;

class Estudiante : public Usuario {
    private:
        DTFecha* fecNac;
        std::string Pais;
        IDictionary* Inscripciones; //la clave es el nomCurso
        Lecciones* UltimaLeccion;
        ICollection* EjerciciosAprov;
    public:
        Estudiante(std::string nicknameE, std::string descripcionE, std::string nombreE, std::string contraseniaE, DTFecha* fecNacE, std::string PaisE);
        Estudiante();
        virtual ~Estudiante();
        DTFecha* getfecNac();
        std::string getPais();
        IDictionary* getInscripciones();
        Lecciones* getUltimaLeccion();
        ICollection* getEjerciciosAprov();

        //CU: Eliminar Curso
        void olvidarInscripcion(Inscripcion* insc);


        //cargar datos
        void aniadirInscripcion(Inscripcion* insc);
        //CU: Inscribirse a Curso
        bool haCursado(std::string nomCurso);
        bool estanDisponibles(set<std::string> Previas);
        void agregarInscripcionEstudiante(Inscripcion* I);
        //CU: Consultar Estadisticas
        set<DataCursoE*>cursosEstudiante();

        //CU:Realizar Ejercicio
        //Inscripcion*EncontrarInscripcion(std::string nCurso);
        set<std::string>PlantearProblemaE(std::string nomEjercicio, std::string nCurso);
        bool IngresarSolucionE(std::string solucionDeUsuario,std::string nomEjercicio, std::string nCurso);
};

#endif