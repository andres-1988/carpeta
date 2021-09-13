#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///prototipos
void cargarMateria();

void mostrarMaterias();
bool grabarEnDisco(Materia);

///
void cargarMateria(){
    Materia reg;
    reg.Cargar();
    if(grabarEnDisco(reg)==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
}

void mostrarMaterias(){
    FILE *pMateria;
    Materia obj; ///52 bytes
    int i, valorDevuelto;
    pMateria=fopen("materias.dat", "rb");

    if(pMateria==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    for(i=0;i<3;i++){
        valorDevuelto=fread(&obj,sizeof obj,1, pMateria);
        cout<<"VALOR DEVUELTO POR fread: "
        obj.Mostrar();
    }

    fclose(pMateria);
}

bool grabarEnDisco(Materia obj){
    FILE *pMateria;
    pMateria=fopen("materias.dat", "ab");
    if(pMateria==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fwrite(&obj,sizeof (Materia),1, pMateria);
    fclose(pMateria);
    return true;
}



#endif // FUNCIONES_H_INCLUDED
