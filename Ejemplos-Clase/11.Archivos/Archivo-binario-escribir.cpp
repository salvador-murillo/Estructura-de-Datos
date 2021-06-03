#include<iostream>
#include<fstream>
using namespace std;

void escribir();
void leer();

int main(){
    // escribir();
    leer();
}

void escribir(){
    int a=20;
    float x=1.25f;

    //Crea archivo "Binary.bin" con datos de a y x, si existe lo remplaza
    fstream datos("Binary.bin",ios::binary|ios::out|ios::app);
    datos.write((char *)&a, sizeof(int));
    datos.write((char *)&x, sizeof(float));
    datos.close();
}

void leer(){
    int a=0;
    float x=0;

    //Verifica si existe el archivo, si esta lo lee y guarda el valor en las variables
    ifstream consulta("Binary.bin",ios::binary);
    consulta.read((char *)&a, sizeof(int));
    consulta.read((char *)&x, sizeof(float));
    cout<<"Valor entero: "<< a << endl;
    cout<<"Valor float: "<< x << endl;
    consulta.close();
}

