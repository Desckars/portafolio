#include <iostream>
#include <string>
#include <sstream>
#include "ICtrl.h"
#include "Factory.h"
#include "DataCursoE.h"
#include "DataCursoP.h"
#include "DataCurso.h"


using namespace std;

int main(int argc, char *argv[]){

    Factory* fabric = new Factory();
	ICtrl* ctrl = fabric->getICtrl();

    int op;
    do{
		ctrl->clearSys();
        std::cout<<"Bienvenido al sistema [REDACTED]"<<endl;
        std::cout<<"0- Cargar Datos"<<endl;
        std::cout<<"1- Ingresar Usuario"<<endl;
        std::cout<<"2- Ingresar Idioma"<<endl;
        std::cout<<"3- Ingresar Curso"<<endl;
        std::cout<<"4- Ingresar Leccion"<<endl;
        std::cout<<"5- Ingresar Ejercicio"<<endl;
        std::cout<<"6- Habilitar Curso"<<endl;
        std::cout<<"7- Inscribirse a Curso"<<endl;
        std::cout<<"8- Realizar Ejercicio"<<endl;
        std::cout<<"9- Consultar Idioma"<<endl;
        std::cout<<"10- Consultar Estadisticas"<<endl;
        std::cout<<"11- Consultar Usuario"<<endl;
        std::cout<<"12- Consultar Curso"<<endl;
        std::cout<<"13- Eliminar Curso"<<endl;
        std::cout<<"14- Salir"<<endl;
		
		std::cin>>op;
        if(op<0 || op>14){
            std::cout<<"Error, ingrese una opcion valida"<<endl;
            op=69;//por las dudas
            std::cout<<"Presione enter para continuar..."<<endl;
            getchar();
        }
		getchar();
		
        switch(op){
            case 0:{
                std::cout<<"Cargando datos, espere..."<<endl;
                ctrl->UnlimitedVoid();
                 std::cout << "⠀⠀⠀⠀⠀⠀                ⢳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠈⠷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⣔⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠙⢧⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢀⣶⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠚⠉⠀⠙⠦⡀⠀⠀⠀⠀⣠⠴⠋⠁⠀⠀⠀⠀⠀⠀⠀⠙⢄⠀⠀⠀⠀⠀⠀⢀⡤⠊⢸⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠃⠀⠀⠀⠀⠀⠀⠉⠒⠤⠔⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⡀⠀⠀⣠⠔⠋⠀⠀⡾⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⢰⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠏⠀⠀⠀⠠⠤⠤⢄⡀⣀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠒⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠋\n"
                 "⠀⠀⠀⠀⠀⠀⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠎⠁⠀⢠⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀\n"
                 "⡀⠀⠀⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⢰⠃⠙⠲⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠖⢒⡆⠀⠀⠀⠀⠀⢠⠞⠁⠀⠀⠀⠀\n"
                 "⠙⢏⠉⠓⠒⠦⢤⡸⡆⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠀⠀⠀⠀⠀⢰⠃⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠈⠳⣄⠀⠀⠀⠈⠙⠢⡀⠀⠀⠀⠀⠀⠾⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢟⣀⣀⣀⣀⡀⠀⠀\n"
                 "⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠟⠋⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣤⡤⢤⠤⠦⠴⠶⣤⠤⠤⣤⣤⣀⣀⠀⠀⢀⡀⠀⠀⠀⠀⠀⣠⠞⠉⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠠⡈⢳⡄⠀⣀⣠⡤⠤⣤⠴⡶⢚⡮⢝⣩⠟⠁⢊⠁⠊⢁⠐⣠⠄⠊⡡⠔⠊⠁⠀⠊⢉⡩⠟⠻⣦⣤⣀⡀⢀⠾⠁⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠈⠁⠙⢾⢽⢏⢀⢔⡷⢋⡴⣮⠔⣫⢖⣣⣒⣥⠤⢶⡗⠚⣻⠏⠋⢙⡛⠂⢀⡤⠒⢁⣠⠀⢠⢄⣩⠼⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⣵⢟⣵⣏⡔⡫⣺⡵⢷⢾⡯⠟⣩⣴⡯⣵⡶⠛⣉⠭⠉⢉⡵⠞⠋⡁⠔⢋⠄⢜⣮⡯⢓⠽⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣡⣻⢖⣵⣫⠞⣡⣾⠗⣩⠴⠋⣡⠔⢋⣡⠴⠉⣁⡴⠚⢉⡴⢞⣡⡶⠋⡡⠾⠛⣡⡶⠟⠿⣯⣄⡀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢟⣵⡿⢚⣴⠾⢋⣤⣞⣡⡶⠭⣷⠞⠛⠛⠛⠛⠛⠛⠛⠛⠓⠚⠒⠒⠒⠦⠤⠤⣥⣄⣀⢸⣧⠀⠹⣆⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡾⣋⣴⠿⠗⠚⠋⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⢸⠀⠀⣿⠄⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣿⣿⡶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠚⢻⡿⠀⢠⡟⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠁⠀⠉⣀⡴⠟⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡯⠟⣻⠃⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⠛⠛⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⢗⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡟⠁⠀⢠⡏⠀⠀⠀⠀⠀⠀⠀⣀⣴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠪⣟⣦⣤⡄⠀⠀⠀⠀⠀⠻⠂⠠⠟⠀⠀⠀⠀⣀⣠⣴⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠚⠯⠭⢷⢶⣶⠶⠶⠶⠶⠒⠒⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                 << std::endl;
                std::cout<<"Datos default cargados, presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 1:{
                //variables
                std::string tipoUsu;
                DTFecha* fecNac;
                std::string fecha;
                int dia, mes, anio;
                std::string nickUsu;
                std::string passUsu;
                std::string nomUsu;
                std::string descUsu;
                std::string paisEst;
                std::string institutoProf;
                set<std::string> listaIdiomas;
                std::string idiomaProf;
                bool esta;


                std::cout<<"Que tipo de usuario desea ingresar?"<<endl;
                std::cout<<"Estudiante|Profesor"<<endl;
                std::getline(std::cin,tipoUsu);
                if((tipoUsu.compare("Estudiante")==0)||(tipoUsu.compare("estudiante")==0)){
                    std::cout<<"Ingrese el nombre del Estudiante: "<<endl;
                    std::getline(std::cin,nomUsu);

                    std::cout<<"Ingrese la fecha de nacimiento del Estudiante "<<endl;
                    std::cout<<"DD/MM/YYYY"<<endl;
                    std::getline(std::cin,fecha);
                    //kilombo para guardar la fecha
                    std::stringstream ss(fecha);
                    std::string token;
                    std::getline(ss, token, '/');
                    dia = std::stoi(token);
                    std::getline(ss, token, '/');
                    mes = std::stoi(token);
                    std::getline(ss, token, '/');
                    anio = std::stoi(token);
                    fecNac = new DTFecha(dia, mes, anio);

                    do{
                        std::cout<<"Ingrese el nick del Estudiante: "<<endl;
                        std::getline(std::cin,nickUsu);
                        IKey* keyEst = new String(nickUsu.c_str());
                        esta =(ctrl->getEstudiantes())->member(keyEst);
                        if(esta==true){
                            std::cout<<"Error, nickname ya esta en uso"<<endl;
                            std::cout<<"Vuelva a intentar"<<endl;
                            getchar();
                        };
                    } while(esta==true);

                    std::cout<<"Ingrese la contrasenia del Estudiante:"<<endl;
                    std::getline(std::cin,passUsu);

                    std::cout<<"Ingrese una descripcion para el Estudiante:"<<endl;
                    std::getline(std::cin,descUsu);
                    
                    std::cout<<"Ingrese el pais del Estudiante:"<<endl;
                    std::getline(std::cin,paisEst);
                    
                    ctrl->IngresoE(fecNac,nickUsu,passUsu,nomUsu,descUsu,paisEst);
                    std::cout<<"Estudiante creado"<<endl;
                    std::cout<<"Volviendo al menu principal, presione enter para continuar"<<endl;
                    getchar();
                }
                if((tipoUsu.compare("Profesor")==0)||(tipoUsu.compare("profesor")==0)){
                    
                    std::cout<<"Ingrese el nombre del Profesor: "<<endl;
                    std::getline(std::cin,nomUsu);

                    do{
                        std::cout<<"Ingrese el nick del Profesor: "<<endl;
                        std::getline(std::cin,nickUsu);
                        IKey* keyProf = new String(nickUsu.c_str());
                        esta =(ctrl->getProfesores())->member(keyProf);
                        if(esta==true){
                            std::cout<<"Error, nickname ya esta en uso"<<endl;
                            std::cout<<"Vuelva a intentar"<<endl;
                            getchar();
                        };
                    } while(esta==true);

                    std::cout<<"Ingrese la contrasenia del Profesor:"<<endl;
                    std::getline(std::cin,passUsu);

                    std::cout<<"Ingrese una descripcion para el Profesor:"<<endl;
                    std::getline(std::cin,descUsu);

                    std::cout<<"Ingrese el instituto del Profesor:"<<endl;
                    std::getline(std::cin,institutoProf);

                    Profesor* profNuevo = ctrl->IngresoP(nickUsu,passUsu,nomUsu,descUsu,institutoProf);

                    std::cout<<"Estos son los Idiomas disponibles para el Profesor"<<endl;
                    listaIdiomas=ctrl->LisIdioma();
                    for(const auto& idi:listaIdiomas){
                        std::cout<<idi<<endl;
                    }

                    do{
                        std::cout<<"Seleccione un Idioma:"<<endl;
                        std::getline(std::cin,idiomaProf);
                        IKey* keyIdioma = new String(idiomaProf.c_str());
                        esta =ctrl->getIdiomas()->member(keyIdioma);
                        if(esta!=true){
                            std::cout<<"Error, no existe un Idioma con ese nombre" <<endl;
                            std::cout<<"Vuelva a intentar"<<endl;
                            getchar();
                        };
                    }while(esta!=true);
                    ctrl->SelecIdioma(idiomaProf,profNuevo);
                    std::cout<<"Profesor creado"<<endl;
                    std::cout<<"Volviendo al menu principal, presione enter para continuar"<<endl;
                    getchar();
                }
                break;
            }
            case 2:{
                std::string nomIdioma; 
                bool esta;
                do{
                std::cout<<"Ingrese el nuevo Idioma"<<endl;
                cin>>nomIdioma;
                IKey* IKI=new String(nomIdioma.c_str());
                esta= ctrl->getIdiomas()->member(IKI);
                if(esta==true){
                    std::cout<<"Error, el Idioma ingresado ya existe"<<endl;
                    std::cout<<"Vuelva a Intentarlo"<<endl;
                    getchar();
                }
                }while(esta==true);
                ctrl->IngresaIdioma(nomIdioma);
                std::cout<<"Idioma ingresado correctamente"<<endl;
                std::cout<<"Precione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 3:{
                //variables
                set<std::string> listaProfesores;
                std::string nickProf;
                std::string nomCurso;
                std::string descCurso;
                DIFICULTAD difCurso;
                int difC;
                set<std::string> listaIdiomas;
                std::string idiomaCurso;
                set<std::string> listaCursosHabilitados;
                std::string cursoPrevia;
                std::string temaLeccion;
                std::string objetivoLeccion;
                std::string nomEj;
                std::string tipoEj;
                std::string descEj;
                std::string fraseEj;
                std::string solEj;
                bool esta;
                char opcion;
                char quiere;
                char masEjer;
                char masLec;
                

                std::cout<<"Estos son los profesores disponibles:"<<endl<<endl;
                listaProfesores=ctrl->ListarProfesores();
                for(const auto& prof:listaProfesores){
                    std::cout<<prof<<endl;
                }
                
                do{
                std::cout<<"Ingrese el nickname del Profesor"<<endl;
                std::getline(std::cin,nickProf);
                IKey* keyProf = new String(nickProf.c_str());
                esta =ctrl->getProfesores()->member(keyProf);
                if(esta!=true){
                    std::cout<<"Error, ingrese un nickname valido"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                };
                } while(esta!=true);

                do{
                std::cout<<"Ingrese el nombre del Curso a crear"<<endl;
                std::getline(std::cin,nomCurso);
                IKey* keyCurso = new String(nomCurso.c_str());
                esta =ctrl->getCursos()->member(keyCurso);
                if(esta==true){
                    std::cout<<"Error, ya existe un Curso con ese nombre"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                };
                }while(esta==true);

                std::cout<<"Ingrese la descripcion del Curso a crear"<<endl;
                std::getline(std::cin,descCurso);

                do{
                std::cout<<"Ingrese la dificultad del Curso a crear"<<endl;
                std::cout<<"(0-principiante,1-medio,2-avanzado)"<<endl;
                cin>>difC;
                if(difC<0||difC>2){
                difCurso = static_cast<DIFICULTAD>(difC);
                }else{
                    std::cout<<"Error, dificultad invalida"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                }
                }while(difC<0||difC>2);
                Curso* cursoNuevo = ctrl->IngresoCurso(nickProf,nomCurso,descCurso,difCurso);

                std::cout<<"Estos son los Idiomas disponibles para el Curso"<<endl;
                listaIdiomas=ctrl->ListarIdiomas(cursoNuevo);
                for(const auto& idi:listaIdiomas){
                    std::cout<<idi<<endl;
                }

                do{
                    std::cout<<"Seleccione un Idioma para el Curso"<<endl;
                    std::getline(std::cin,idiomaCurso);
                    IKey* keyIdioma = new String(idiomaCurso.c_str());
                    esta =ctrl->getIdiomas()->member(keyIdioma);
                    if(esta!=true){
                        std::cout<<"Error, no existe un Idioma con ese nombre" <<endl;
                        std::cout<<"Vuelva a intentar"<<endl;
                        getchar();
                    };
                }while(esta!=true);
                ctrl->SeleccionarIdiomaC(idiomaCurso,cursoNuevo);

                std::cout<<"Desea agregar previaturas a este Curso?   Y|N";
                cin>>opcion;
                if(opcion=='Y'||opcion=='y'){
                    std::cout<<"Estos son los Cursos que se encuentran disponibles:"<<endl;
                    listaCursosHabilitados=ctrl->ListarCursosHabilitados();
                for(const auto& ch:listaCursosHabilitados){
                    std::cout<<ch<<endl;
                }
                do{
                    std::cout<<"Seleccione un Curso:"<<endl;
                    std::getline(std::cin,cursoPrevia);
                    ctrl->SeleccionarPreviatura(cursoPrevia,cursoNuevo);
                    std::cout<<"Desea agregar otra?   Y|N"<<endl;
                    cin>>quiere;
                }while(quiere=='Y'||quiere=='y');
                }
                std::cout<<"Desea agregar una Leccion a este Curso?   Y|N";
                cin>>opcion;
                if(opcion=='Y'||opcion=='y'){
                    do{
                        std::cout<<"Ingrese un tema para la Leccion"<<endl;
                        std::getline(std::cin,temaLeccion);
                        std::cout<<"Ingrese un objetivo para la Leccion"<<endl;
                        std::getline(std::cin,objetivoLeccion);
                        Lecciones* leccionNueva = cursoNuevo->CrearLeccion(temaLeccion,objetivoLeccion);
                        std::cout<<"Desea agregar un Ejercicio para esta Leccion?   Y|N"<<endl;
                        cin>>quiere;
                        if(opcion=='Y'||opcion=='y'){
                            do{
                                std::cout<<"Ingrese el nombre del Ejercicio"<<endl;
                                std::getline(std::cin,nomEj);

                                std::cout<<"Ingrese el tipo del Ejercicio"<<endl;
                                std::cout<<"(Traducir|Completar)  MAYUS IMPORTANTE"<<endl;
                                std::getline(std::cin,tipoEj);
                                do{
                                if(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0){
                                    std::cout<<"Error, tipo invalido"<<endl;
                                    std::cout<<"Vuelva a intentar"<<endl;
                                    getchar();
                                };
                                }while(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0);

                                std::cout<<"Ingresar una descripcion:"<<endl;
                                std::getline(std::cin,descEj);
                                
                                std::cout<<"Ingrese el problema a solucionar:"<<endl;
                                std::cout<<"(En caso de ser de Completar, utilice --- en las secciones a completar)"<<endl;
                                std::getline(std::cin,fraseEj);
                            
                                std::cout<<"Ingrese la solucion"<<endl;
                                std::cout<<"(En caso de ser de Completar, separe las palabras con ---)"<<endl;
                                std::getline(std::cin,solEj);
                                leccionNueva->CrearEjer(nomEj,tipoEj,descEj,fraseEj,solEj);
                                std::cout<<"Desea agregar otro Ejercicio a esta Leccion?  Y|N"<<endl;
                                cin>>masEjer;
                            }while(masEjer=='Y'||masEjer=='y');
                        }
                        std::cout<<"Desea agregar otra Leccion a este Curso?   Y|N"<<endl;
                        cin>>masLec;
                    }while(masLec=='Y'||masLec=='y');
                }
                std::cout<<"Alta de Curso terminada, volviendo a menu principal"<<endl;
                std::cout<<"Presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 4:{
                set<std::string> cursoNH= ctrl->ListarCursosNoHabilitados();
                std::cout << "Cursos no Habilitados"<< endl;
                for (const auto& curso : cursoNH) {
                    std::cout << curso <<endl;
                }
                std::string nomCurso;
                bool esta;
                do{
                    std::cout << "Selecione un Curso"<< endl;
                    cin>>nomCurso;
                    esta=false;
                    for (const auto& curso : cursoNH){ 
                        if (curso == nomCurso){
                                esta=true;
                                break;
                        }
                    }
                    if(esta!=true){
                        std::cout<<"Error, el Nombre del Curso ingresado no es correcto"<<endl;
                        std::cout<<"Vuelva a Intentarlo"<<endl;
                        getchar();
                    }
                }while(esta!=true);
                Curso* C=ctrl->SeleccionarCursoNoHabilitado(nomCurso);
                std::string nomTema;
                std::cout<<"Ingrese el Nombre del tema de la Leccion"<<endl;
                cin>>nomTema;
                std::string objetivo;
                std::cout<<"Ingrese el Objetivo de la Leccion"<<endl;
                cin>>objetivo;
                Lecciones* L= ctrl->ingresarLeccion(nomTema,objetivo,C);
                std::string nomEj;
                std::string tipoEj;
                std::string descEj;
                std::string fraseEj;
                std::string solEj;
                char opcion;
                char masEjer;                
                        std::cout<<"Desea agregar un Ejercicio para esta Leccion?   Y|N"<<endl;
                        cin>>opcion;
                        if(opcion=='Y'||opcion=='y'){
                            do{
                                std::cout<<"Ingrese el nombre del Ejercicio"<<endl;
                                std::getline(std::cin,nomEj);
                                do{
                                    std::cout<<"Ingrese el tipo del Ejercicio"<<endl;
                                    std::cout<<"(Traducir|Completar)  MAYUS IMPORTANTE"<<endl;
                                    std::getline(std::cin,tipoEj);
                                    
                                    if(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0){
                                        std::cout<<"Error, tipo invalido"<<endl;
                                        std::cout<<"Vuelva a intentar"<<endl;
                                        getchar();
                                    };
                                }while(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0);

                                std::cout<<"Ingresar una descripcion:"<<endl;
                                std::getline(std::cin,descEj);
                                
                                std::cout<<"Ingrese el problema a solucionar:"<<endl;
                                std::cout<<"(En caso de ser de Completar, utilice --- en las secciones a completar)"<<endl;
                                std::getline(std::cin,fraseEj);
                            
                                std::cout<<"Ingrese la solucion"<<endl;
                                std::cout<<"(En caso de ser de Completar, separe las palabras con ---)"<<endl;
                                std::getline(std::cin,solEj);
                                ctrl->CrearEjercicio(nomEj,tipoEj,descEj,fraseEj,solEj,C,L);
                                std::cout<<"Desea agregar otro Ejercicio a esta Leccion?  Y|N"<<endl;
                                cin>>masEjer;
                            }while(masEjer=='Y'||masEjer=='y');
                        }
                        

                break;
            }
            case 5:{
                std::string nomEj;
                std::string tipoEj;
                std::string descEj;
                std::string fraseEj;
                std::string solEj;
                std::string nCurso;
                std::string nomLec;
                cout<<"Cursos No Habilitados: "<<endl;
                set<std::string>CursosNH = ctrl->ListarCursosNoHabilitados();
                for(std::string c : CursosNH){
                    cout<<c<<endl;
                }
                cout<<"Ingrese el Curso seleccionado: "<<endl<<"> ";
                getline(std::cin,nCurso);
                if(ctrl->getCursos()->member(new String(nCurso.c_str()))){
                    set<std::string> Lecs = ctrl->listarLecciones(nCurso);
                    for(std::string lec : Lecs){
                        cout<<lec<<endl;
                    }
                    cout<<"Ingrese nombre/tema de leccion"<<endl,
                    getline(std::cin,nomLec);
                    if(((Curso*)ctrl->getCursos()->find(new String(nCurso.c_str())))->ExisteLecC(nomLec)){
                        Lecciones* l = ctrl->SeleccionarLeccion(nCurso,nomLec);

                        std::cout<<"Ingrese el nombre del Ejercicio"<<endl;
                        std::getline(std::cin,nomEj);

                        std::cout<<"Ingrese el tipo del Ejercicio"<<endl;
                        std::cout<<"(Traducir|Completar)  MAYUS IMPORTANTE"<<endl;
                        std::getline(std::cin,tipoEj);
                        do{
                        if(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0){
                            std::cout<<"Error, tipo invalido"<<endl;
                            std::cout<<"Vuelva a intentar"<<endl;
                            getchar();
                        };
                        }while(tipoEj.compare("Traducir")!=0||tipoEj.compare("Completar")!=0);

                        std::cout<<"Ingresar una descripcion:"<<endl;
                        std::getline(std::cin,descEj);
                        
                        std::cout<<"Ingrese el problema a solucionar:"<<endl;
                        std::cout<<"(En caso de ser de Completar, utilice --- en las secciones a completar)"<<endl;
                        std::getline(std::cin,fraseEj);
                    
                        std::cout<<"Ingrese la solucion"<<endl;
                        std::cout<<"(En caso de ser de Completar, separe las palabras con ---)"<<endl;
                        std::getline(std::cin,solEj);
                        l->CrearEjer(nomEj,tipoEj,descEj,fraseEj,solEj);
                    }
                }
                else{
                    cout<<"Datos Ingresados no validos"<<endl;
                    getchar();
                }
                break;
            }
            case 6:{
                //variables
                set<std::string> listCNH;
                std::string nomCurso;
                bool esta;
                char hab;

                std::cout<<"Estos son los Cursos no habilitados del Sistema:"<<endl;
                listCNH=ctrl->ListarCursosNoHabilitados();
                for(const auto& curs:listCNH){
                    std::cout<<curs<<endl;
                }
                do{
                    std::cout<<"Seleccione el Curso que desea habilitar: ";
                    std::getline(std::cin,nomCurso);
                    IKey* keyCurso = new String(nomCurso.c_str());
                    esta =ctrl->getCursos()->member(keyCurso);
                    if(esta!=true){
                        std::cout<<"Error, no existe un Curso con ese nombre"<<endl;
                        std::cout<<"Vuelva a intentar"<<endl;
                        getchar();
                    };
                }while(esta!=true);
                std::cout<<"Seguro que desea habilitar este Curso?   Y|N"<<endl;
                cin>>hab;
                if(hab=='Y'||hab=='y'){
                ctrl->HabilitarCurso(nomCurso);
                std::cout<<"El Curso ha sido habilitado"<<endl;
                std::cout<<"Presione enter para continuar"<<endl;
                getchar();
                }
                break;
            }
            case 7:{
                string nick;
                bool esta;
                do{
                std::cout<<"Ingrese el Nickname del Estudiante"<<endl;
                cin>>nick;
                IKey* IKN=new String(nick.c_str());
                esta= ctrl->getEstudiantes()->member(IKN);
                if(esta!=true){
                    std::cout<<"Error, el Nickname ingresado no existe"<<endl;
                    std::cout<<"Vuelva a Intentarlo"<<endl;
                    getchar();
                }
                }while(esta!=true);
                Estudiante* E=nullptr;
                set<DataCurso3*> DT= ctrl->ListarCursosDisponibles(nick,E);
                std::cout << "Cursos disponibles:"<<endl;
                for (const auto& curso : DT) {
                   std::cout << "Nombre del Curso: " << curso->getNomCurso() << ", Dificultad: " << curso->getDificultad()<<",Descripcion"<<curso->getDesCurso()<<",Cantidad de Lecciones"<<curso->getLecciones()<<",Cantidad de Ejercicios"<<curso->getEjercicios() <<endl;
                }
                string nomCurso;
                do{
                std::cout<<"Ingrese el Nombre del Curso al cual e desea inscribir: "<<endl;
                cin>>nomCurso;
                esta=false;
                for (const auto& curso : DT){ 
                   if (curso->getNomCurso() == nomCurso){
                        esta=true;
                        break;
                   }
                }
                if(esta!=true){
                    std::cout<<"Error, el Nombre del Curso ingresado no existe"<<endl;
                    std::cout<<"Vuelva a Intentarlo"<<endl;
                    getchar();
                }
                }while(esta!=true);
                ctrl->SeleccionarCurso(nomCurso,E);
                std::cout<<"Estudian Inscripto correctamente"<<endl;
                std::cout<<"Precione enter para continuar"<<endl;
                getchar();
                
                break;
            }
            case 8:{
                cout<<"Ingrese nick del Estudiante"<<endl<<"> ";
                std::string nick;
                std::string nCurso;
                std::string nomEjer;
                std::string solUsuario;
                getline(std::cin,nick);
                if(ctrl->getEstudiantes()->member(new String(nick.c_str()))){
                    set<DataCursoE*>Csos = ctrl->ListCursosE(nick);
                    for (DataCursoE* DTCE : Csos) {
                        cout<<"Curso: "<<DTCE->getNomCursoP()<<endl;
                        cout<<"(%)Avance: "<<DTCE->getPAvance();
                    }
                    cout<<"Ingrese nombre del Curso: "<<endl<<"> ";
                    getline(std::cin,nCurso);
                    if(ctrl->getCursos()->member(new String(nCurso.c_str()))){
                        set<std::string>Ejercicios = ctrl->ListarEjercicios(nCurso,(Estudiante*)ctrl->getEstudiantes()->find(new String(nick.c_str())));
                        for(const std::string& ejer : Ejercicios){
                            cout<<ejer<<endl;
                        }
                        cout<<"Ingrese nombre del Ejercicio: "<<endl<<"> ";
                        getline(std::cin,nomEjer);
                        ctrl->clearSys();
                        set<std::string>Problema = ctrl->PlantearProblema(nomEjer,nCurso,(Estudiante*)ctrl->getEstudiantes()->find(new String(nick.c_str())));
                        if(Problema.empty()==false){
                            for(const std::string& probE : Problema){
                                cout<<probE<<endl;
                            }
                            cout<<endl<<"Ingrese solucion: "<<endl<<"> ";
                            getline(std::cin,solUsuario);
                            if(ctrl->IngresarSolucion(solUsuario,nomEjer,nCurso,(Estudiante*)ctrl->getEstudiantes()->find(new String(nick.c_str())))){
                                cout<<"La solucion es CORRECTA!"<<endl;
                            }
                            else{
                                cout<<"La solucion es INCORRECTA!"<<endl;
                            }
                        }
                    }
                }
                else{
                    ctrl->clearSys();
                    cout<<"Opcion no valida"<<endl;
                    getchar();
                }
                break;
            }
            case 9:{
                set<std::string> Idiomas= ctrl->muestroIdioma();
                std::cout << "Idiomas: "<< endl;
                for (const auto& idioma : Idiomas) {
                    std::cout << idioma <<endl;
                }
                std::cout<<"Precione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 10:{
                char opt;
                string nick;
                cout<<"Que estadistica desea?:"<<endl;
                cout<<"1- Estudiantea"<<endl;
                cout<<"2- Profesores"<<endl;
                cout<<"3- Cursos"<<endl;
                cin>>opt;
                getchar();
                ctrl->clearSys();
                switch(opt){
                    case '1':{
                        cout<<"Estudiantes: "<<endl;
                        set<std::string>estu=ctrl->ListEstudiantes();
                        for (const std::string& palabra : estu) {
                            cout<<palabra<<endl;
                        }
                        cout<<"Selecione un estudiante: "<<endl;
                        getline(std::cin,nick);
                        ctrl->clearSys();
                        set<DataCursoE*>CursosE=ctrl->ListCursosE(nick);
                        for (DataCursoE* CE : CursosE) {
                            cout<<"Curso: "<<CE->getNomCursoP()<<endl;
                            cout<<"(%)Avance: "<<CE->getPAvance();
                        }
                        break;
                    }
                    case '2':{
                        cout<<"Profesores: "<<endl;
                        set<std::string>Profs=ctrl->ListarProfesores();
                        for (const std::string& palabra : Profs) {
                            cout<<palabra<<endl;
                        };
                        cout<<"Selecione un Profesor: "<<endl;
                        getline(std::cin,nick);
                        ctrl->clearSys();
                        set<DataCursoP*>CursosP=ctrl->ListCursosP(nick);
                        for (DataCursoP* CP : CursosP) {
                            cout<<"Curso: "<<CP->getNomCurso()<<endl;
                            cout<<"(%)Promedio de avance: "<<CP->getProm();
                        };
                        break;
                    }
                    case '3':{
                        cout<<"Cursos: "<<endl;
                        set<std::string>Curs=ctrl->ListCurso();
                        for (const std::string& palabra : Curs) {
                            cout<<palabra<<endl;
                        };
                        cout<<"Selecione un Curso: "<<endl;
                        getline(std::cin,nick);
                        ctrl->clearSys();
                        DataCurso* CI=ctrl->verInfoCurso(nick);
                            cout<<"Curso: "<<CI->getNomCurso()<<endl;
                            cout<<"Descripcion: "<<CI->getDesCurso()<<endl;
                            cout<<"habilitado?: "<<CI->getHabilitado();
                            cout<<"Dificultad: ";
                            switch(CI->getDificultad()){
                                case 0:{
                                    cout<<"principiante"<<endl;
                                    break;
                                }
                                case 1:{
                                    cout<<"medio"<<endl;
                                    break;
                                }
                                default:{
                                    cout<<"avanzado"<<endl;
                                }
                            };
                            cout<<"(%)Promedio de avance Total: "<<CI->getPromediT();
                        break;
                    }
                    default:{
                        cout<<"Opcion no valida"<<endl;
                        getchar();
                    }
                }
                break;
            }
            case 11:{
                std::string nickUsu;
                set<std::string> listaEstudiantes;
                set<std::string> listaProfesores;
                bool esta=true;

                std::cout<<"Estos son los Usuarios guardados en el Sistema:"<<endl;
                if(!(ctrl->getEstudiantes()->isEmpty())){
                listaEstudiantes=ctrl->ListEstudiantes();
                for(const auto& usu:listaEstudiantes){
                    std::cout<<usu<<endl;
                }
                }

                if(!(ctrl->getProfesores()->isEmpty())){
                listaProfesores=ctrl->ListarProfesores();
                for(const auto& usu:listaProfesores){
                    std::cout<<usu<<endl;
                }
                }
                
                do{
                    std::cout<<"Seleccione un Usuario para consultar informacion:"<<endl;
                    std::getline(std::cin,nickUsu);
                    IKey* keyUsu = new String(nickUsu.c_str());
                    esta=ctrl->getEstudiantes()->member(keyUsu);
                    if (esta != true ){  
                        std::cout<<"No es estudiante"<<endl;
                        getchar();
                        esta=ctrl->getProfesores()->member(keyUsu);
                        if(esta != true){
                            std::cout << "Error, no existe un Usuario con ese nombre" <<endl;
                            std::cout << "Vuelva a intentar" <<endl;
                            getchar();
                        }
                    } 
                }while(esta!=true);

                DataUsuario* dataUsu = ctrl->DatosUser(nickUsu);
                
                std::cout<<"Nombre: "<<dataUsu->getnombre()<<endl;
                std::cout<<"Descripcion: "<<dataUsu->getdescripcion()<<endl;
                std::cout<<"Nickname: "<<dataUsu->getnickname()<<endl;
                std::cout<<"Contrasenia: "<<dataUsu->getcontrasenia()<<endl;
                if(dataUsu->getEstudiante()!=NULL){
                    std::cout<<"Fecha de Nacimiento: "<<dataUsu->getEstudiante()->getFecNac()->getdia()<<"/"<<dataUsu->getEstudiante()->getFecNac()->getmes()<<"/"<<dataUsu->getEstudiante()->getFecNac()->getanio()<<endl;
                    std::cout<<"Pais: "<<dataUsu->getEstudiante()->getPais();
                }
                if(dataUsu->getProfesor()!=NULL){
                    std::cout<<"Instituto: "<<dataUsu->getProfesor()->getinstituto();
                    IIterator* it=dataUsu->getProfesor()->getnomIdioma()->getIterator();
                    std::cout<<"Lista de Idiomas: "<<endl;
                    while(it->hasCurrent()){
                        std::cout<<((Idiomas*)it->getCurrent())->getNomIdioma()<<endl;
                        it->next();
                    }
                }

                std::cout<<endl<<endl<<"Operacion completada"<<endl;
                std::cout<<"Presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 12:{
                std::string nomCurso;
                set<std::string> listaCursos;
                bool esta;


                std::cout<<"Estos son los Cursos guardados en el Sistema:"<<endl;
                listaCursos=ctrl->ListCurso();
                for(const auto& curs:listaCursos){
                    std::cout<<curs<<endl;
                }
                do{
                    std::cout<<"Seleccione un Curso para consultar informacion:"<<endl;
                    std::getline(std::cin,nomCurso);
                    IKey* keyCurso = new String(nomCurso.c_str());
                    esta=ctrl->getCursos()->member(keyCurso);
                    if(esta!=true){
                        std::cout<<"Error, no existe un Curso con ese nombre"<<endl;
                        std::cout<<"Vuelva a intentar"<<endl;
                        getchar();
                    }
                }while(esta!=true);

                DataCurso2* dataCurso = ctrl->listarInfoCurso(nomCurso);
                std::cout<<"Nombre: "<<dataCurso->getNomCurso()<<endl;
                std::cout<<"Dificultad: ";
                switch(dataCurso->getDificultad()){
                    case 0:{
                        cout<<"principiante"<<endl;
                        break;
                        }
                    case 1:{
                            cout<<"medio"<<endl;
                            break;
                        }
                    default:{
                            cout<<"avanzado"<<endl;
                        }
                }
                std::cout<<"Descripcion: "<<dataCurso->getDesCurso()<<endl;
                std::cout<<"Idioma: "<<dataCurso->getNomIdioma()<<endl;
                std::cout<<"Profesor: "<<dataCurso->getNomProf()<<endl;
                std::cout<<"Habilitado: ";
                if(dataCurso->getHabilitado()){
                    std::cout<<"Si"<<endl;
                } else{
                    std::cout<<"No"<<endl;
                }
                std::cout<<"Lista de Lecciones:"<<endl;
                set<DataLeccion*> dataLec=(dataCurso->getLeccion());
                for (DataLeccion* lec: dataLec) {
                    std::cout <<"Tema: "<< lec->gettema() << std::endl;
                    std::cout <<"Objetivo: "<< lec->getobjetivo() << std::endl;
                    std::cout<<"Ejercicios de Completar de esta Leccion: "<<endl;
                    set<DataEjeCompletar*> dataComp = lec->getDataEjeComp();
                        for(DataEjeCompletar* comp: dataComp){
                            std::cout<<"Nombre: "<<comp->getNomEjercicio()<<endl;
                            std::cout<<"Descripcion: "<<comp->getDescripcion()<<endl;
                            std::cout<<"Problema: "<<comp->getFraseC()<<endl;
                            std::cout<<"Solucion: ";
                            set<std::string> faltantes=comp->getFaltante();
                            for(std::string falta:faltantes){
                                std::cout<<falta<<" ";
                            }
                            std::cout<<endl<<endl;
                        }
                    std::cout<<"Ejercicios de Traduccion de esta Leccion: "<<endl;
                    set<DataEjeTraduccion*> dataTrad = lec->getDataEjeTrad();
                        for(DataEjeTraduccion* trad: dataTrad){
                         std::cout<<"Nombre: "<<trad->getNomEjercicio()<<endl;
                         std::cout<<"Descripcion: "<<trad->getDescripcion()<<endl;
                         std::cout<<"Problema: "<<trad->getFraseT()<<endl;
                         std::cout<<"Solucion: "<<trad->getTraduccion()<<endl<<endl;   
                        }
                    }
                std::cout<<"Lista de Inscripciones: "<<endl;
                set<DataInscripciones2*> dataInsc=(dataCurso->getInscrip());
                for(DataInscripciones2* insc: dataInsc){
                    std::cout<<"Fecha Inscripcion: "<<insc->getfechaInsc()->getdia()<<"/"<<insc->getfechaInsc()->getmes()<<"/"<<insc->getfechaInsc()->getanio()<<endl;
                    std::cout<<"Nombre Estudiante"<<insc->getnomEstu()<<endl<<endl;
                }
                std::cout<<"Operacion completada"<<endl;
                std::cout<<"Presione enter para continuar"<<endl;
                getchar();
                break;
            }
            case 13:{
                //variables
                set<std::string> listaCursos;
                std::string nomCurso;
                bool esta;
                char kil;

                std::cout<<"Estos son los Cursos del Sistema:"<<endl;
                listaCursos=ctrl->ListCurso();
                for(const auto& curs:listaCursos){
                    std::cout<<curs<<endl;
                }
                do{
                std::cout<<"Seleccione el Curso que desea eliminar: ";
                std::getline(std::cin,nomCurso);
                IKey* keyCurso = new String(nomCurso.c_str());
                esta =ctrl->getCursos()->member(keyCurso);
                if(esta!=true){
                    std::cout<<"Error, no existe un Curso con ese nombre"<<endl;
                    std::cout<<"Vuelva a intentar"<<endl;
                    getchar();
                };
                }while(esta!=true);
                
                std::cout<<"Seguro que desea eliminar este Curso?   Y|N"<<endl;
                cin>>kil;
                if(kil=='Y'||kil=='y'){
                ctrl->EliminarCurso(nomCurso);
                std::cout<<"El Curso ha sido eliminado"<<endl;
                std::cout<<"Presione enter para continuar"<<endl;
                getchar();
                }
                break;
            }
            case 14:{
                break;
            }
        };
    }while(op!=14);
    return 0;
}