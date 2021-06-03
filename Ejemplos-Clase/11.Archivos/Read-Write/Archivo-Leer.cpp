#include<iostream>
#include<fstream>
using namespace std;

void leer();

int main(){
    leer();
}

void leer(){
    ifstream consulta;
    string texto;

    consulta.open("prueba.txt",ios::in); //Abrir en modo lectura

    if(consulta.fail()){
        cout<<"Error al abrir archivo";
    }

    while(!consulta.eof()){ //mientras no sea final de archivo
        getline(consulta,texto); //En lugar de CIN usamos el archivo consulta
        cout<<texto<<endl;
    }
}

