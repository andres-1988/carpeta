///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Fecha{ ///Agregar los sets y gets.
    private:
        int dia,mes, anio;
    public:
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};


class Persona{///clase base: agregar telefono y mail. Agregar tambien los set y get correspondientes
protected:///mantiene el encapsulamiento, pero permite que las clases derivadas accedan
    int DNI;
    char nombre[30];
    char apellido[30];
    Fecha fechaNac; ///int diaNac, mesNac, anioNac;
    char telefono[20];
    char mail[40];
public:
    void Cargar();
    void Mostrar();
    ///sets()
    void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *apellido){strcpy(this->apellido,apellido);}
    void setFechaNac(Fecha f){fechaNac=f;}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setMail(const char *m){strcpy(mail,m);}
    void setMesNac(int m){fechaNac.setMes(m);}
    ///gets()
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return this->apellido;}
    Fecha getFechaNac(){return fechaNac;}
    const char *getTelefono(){return telefono;}
    const char *getMail(){return mail;}
};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"DNI: ";
    cin>>this->DNI;
    cout<<"FECHA DE NACIMIENTO"<<endl;
    fechaNac.Cargar();
    cout<<"TELEFONO: ";
    cin>>telefono;
    cout<<"MAIL: ";
    cin>>mail;
}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DNI: ";
    cout<<this->DNI<<endl;
    cout<<"FECHA DE NACIMIENTO"<<endl;
    fechaNac.Mostrar();
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"MAIL: ";
    cout<<mail<<endl;
}

class Alumno: public Persona{ //Agregar carrera y titulo secundario
    private:
        int legajo;
        char carrera[30];
        char titulo[30];
    public:
        void Cargar();
        void Mostrar();
        void setLegajo(int l){legajo=l;}
        void setCarrera(const char *c){strcpy(carrera,c);}
        void setTitulo(const char *t){strcpy(titulo,t);}
        int getLegajo(){return legajo;}
        const char *getCarrera(){return carrera;}
        const char *getTitulo(){return titulo;}
};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"CARRERA: ";
    cin.ignore();
    cin.getline(carrera,29);
    cout<<"TITULO SECUNDARIO: ";
    cin.getline(titulo,29);
}

void Alumno::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO: ";
    cout<<legajo<<endl;
    cout<<"CARRERA: ";
    cout<<carrera<<endl;
    cout<<"TITULO SECUNDARIO: ";
    cout<<titulo<<endl;
}

class Docente: public Persona{
    private:
        int legajo;
        char cargo[30];
        Fecha fechaIng; ///int diaIng, mesIng, anioIng;
    public:
        void Cargar();
        void Mostrar();
        void setLegajo(int l){legajo=l;}
        void setCargo(const char *c){strcpy(cargo,c);}
        void setFechaIng(Fecha f){fechaIng=f;}
        int getLegajo(){return legajo;}
        const char *getCargo(){return cargo;}
        Fecha getFechaIng(){return fechaIng;}
};

void Docente::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"CARGO: ";
    cin.ignore();
    cin.getline(cargo,29);
    cout<<"FECHA DE INGRESO: "<<endl;
    fechaIng.Cargar();
}

void Docente::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO: ";
    cout<<legajo<<endl;
    cout<<"CARGO: ";
    cout<<cargo<<endl;
    cout<<"FECHA DE INGRESO: ";
    fechaIng.Mostrar();
}

///AGREGAR TAMBIEN LAS CLASES DERIVADAS FALTANTES.

int main(){
    Docente obj;
    Fecha aux;
    obj.Cargar();
    obj.Mostrar();
    cout<<endl<<endl;
    cout<<"Fecha nacimiento: ";
    aux.Cargar();
    obj.setFechaNac(aux);
    obj.getFechaNac().Mostrar();
    obj.setMesNac(8);
    cout<<endl;
    cout<<"Fecha nacimiento: ";
    obj.getFechaNac().Mostrar();
	system("pause");
	return 0;
}
