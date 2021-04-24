/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #8: Aritmetica de Apuntadores, Arreglo de enteros
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #6: Aritmetica de Apuntadores Arreglo de Enteros\n" << endl;
}

int main() {
    mostrarTitulo();
    int sueldos[] = {1000,2000,3000,4000,5000};
    
    cout << "\tPARTE 1: Usando Variable" << endl;
    cout << "Direccion inicial del arreglo        : " << &sueldos << endl;
    for (int i = 0; i < 5; i++){
        cout << "Valor Pos #" << i << ": " << sueldos[i] << " | Direccion Pos #" << i << ": " << &sueldos[i] << endl;
    }

    int* dir_sueldos = sueldos;
    cout << "\n\tPARTE 2: Usando Apuntador" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Valor Pos #" << i << ": " << *(dir_sueldos+i) << " | Direccion Pos #" << i << ": " << dir_sueldos+i << endl;
    }
    
    cout << "\n\tPARTE 3: Usando Apuntador con contador" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Valor Pos #" << i << ": " << *(dir_sueldos) << " | Direccion Pos #" << i << ": " << dir_sueldos << endl;
        dir_sueldos+=1;
    }

}