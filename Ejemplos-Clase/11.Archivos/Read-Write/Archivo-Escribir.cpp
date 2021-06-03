#include<iostream>
#include<fstream>
using namespace std;

void escribir();

int main(){
    escribir();
}

void escribir(){
    ofstream datos;  //Output File STREAM   creacion de objeto "datos"
    string nomArchivo,frase;
    cout<<"Dame el nombre del archivo: ";
    getline(cin,nomArchivo);
    datos.open(nomArchivo.c_str(),ios::out); //Crea archivo de acuerdo al nombre

    datos.open("prueba.txt",ios::out);  //Abriendo Archivo (si existe, lo reemplaza, si no lo crea)
    /*datos.open("prueba.txt",ios::app);  //Abriendo Archivo en modo a�adir*/
    if(datos.fail()){ //SI es true, es un error
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    datos<<"francisco robles";

    /*cout<<"Dame la frase a guardar: ";
    getline(cin,frase);
    datos<<frase;*/

    datos.close();  //Cerrar el archivo
}
