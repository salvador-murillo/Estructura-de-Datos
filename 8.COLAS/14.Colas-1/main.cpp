/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #14: Ejercicio Colas 1
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #13: Pilas Ejercicio #1\n" << endl;
}

void pressEnter(){
   cout << "\nPresione enter para continuar...";
   cin.ignore();
}

struct nodo{
   int num;
   nodo *nextNodo;
};


int main() {
   cout << "TEST 14: COLAS" << endl;
} 