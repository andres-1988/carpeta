#include <iostream>
#include <cstring>
#include<cstdio>
#include<cstdlib>


using namespace std;



class Materia{
    private:///propiedades van en la parte privada de la clase
        ///Encapsulamiento
        int nroMateria;
        char nombreMateria[40];
        int cantAlumnos;
        int cantDocentes;
    public:///desarrollo de los métodos. Funciones de la clase
        Materia(int nM=0, const char *nombre="nada", int ca=0, int cd=0){
            nroMateria=nM;
            strcpy(nombreMateria,nombre);
            cantAlumnos=ca;
            cantDocentes=cd;
        }
        ~Materia(){
      //      cout<<"SE MURIO EL OBJETO. VIVA EL OBJETO!!!"<<endl;
        }
        void Cargar(){
            int nro;
            cout<<"NUMERO DE MATERIA: ";
            cin>>nro;
            setNroMateria(nro);
            cout<<"NOMBRE DE MATERIA: ";
            cin.ignore();
            cin.getline(nombreMateria,35);
            cout<<"CANTIDAD DE ALUMNOS: ";
            cin>>this->cantAlumnos;
            cout<<"CANTIDAD DE DOCENTES: ";
            cin>>cantDocentes;
        }
        void Mostrar();
        ///sets() para asignar valor a cada propiedad
        void setNroMateria(int nm){if(nm>=0)nroMateria=nm;}
        void setNombreMateria(const char *nm){strcpy(nombreMateria,nm);}

        ///gets() para que desde fuera de la clase se conozca el valor de cada propiedad.
        int getNroMateria(){return nroMateria;}
        char *getNombreMateria(){return nombreMateria;}

};

#include "funciones.h"

void Materia::Mostrar(){
            cout<<"NUMERO DE MATERIA: ";
            cout<<this->nroMateria<<endl;
            cout<<"NOMBRE DE MATERIA: ";
            cout<<nombreMateria<<endl;
            cout<<"CANTIDAD DE ALUMNOS: ";
            cout<<cantAlumnos<<endl;
            cout<<"CANTIDAD DE DOCENTES: ";
            cout<<cantDocentes<<endl<<endl;
        }





int main(){
    int opc;
    while(true){
        system("cls");
        cout << "1. CARGAR DATOS MATERIAS" << endl;
        cout << "2. MOSTRAR DATOS MATERIAS" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "----------------" << endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarMateria();
                    break;
            case 2: mostrarMaterias();
                    break;
            case 0: return 0;
                    break;
            default:cout<<"OPCION INCORRECTA. INGRESE NUEVAMENTE"<<endl;
                  break;

        }
        system("pause");
    }
    return 0;
}
