/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #9: Aritmetica de Apuntadores, Arreglo de double
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #7: Aritmetica de Apuntadores Arreglo de Double\n" << endl;
}

int main() {
    mostrarTitulo();
    double precios[] = {1111111111,2222222222,3333333333,4444444444,5555555555};
    
    cout << "\tPARTE 1: Usando Variable" << endl;
    cout << "Direccion inicial del arreglo        : " << &precios << endl;
    for (int i = 0; i < 5; i++){
        cout << "Valor Pos #" << i << ": " << precios[i] << " | Direccion Pos #" << i << ": " << &precios[i] << endl;
    }

    double* dir_precios = precios;
    cout << "\n\tPARTE 2: Usando Apuntador" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Valor Pos #" << i << ": " << *(dir_precios+i) << " | Direccion Pos #" << i << ": " << dir_precios+i << endl;
    }
    
    cout << "\n\tPARTE 3: Usando Apuntador con contador" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Valor Pos #" << i << ": " << *(dir_precios) << " | Direccion Pos #" << i << ": " << dir_precios << endl;
        dir_precios+=1;
    }

}