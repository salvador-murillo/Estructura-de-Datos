#include<iostream>
#include<fstream>
using namespace std;
void escribir();
void leer();

struct alumno{
    int cod;
    char nomb[30];
    float altura;
}a1={1,"Paco",1.87},a2={2,"Pedro",1.59};

int main(){
    // escribir();
    leer();
}

void escribir(){
    ofstream guardar("alumno.dat",ios::binary|ios::app);
    guardar.write((char *)&a1,sizeof(alumno));
    guardar.write((char *)&a2,sizeof(alumno));
}

void leer(){
    ifstream consulta("alumno.dat",ios::binary);
    consulta.read((char *)&a1, sizeof(alumno));
    consulta.read((char *)&a2, sizeof(alumno));

    cout<<"C�digo: "<<a1.cod<<"\nNombre: "<<a1.nomb<<"\nAltura: "<<a1.altura << endl;
    cout<<"C�digo: "<<a2.cod<<"\nNombre: "<<a2.nomb<<"\nAltura: "<<a2.altura;

}

