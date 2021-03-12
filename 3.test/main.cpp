/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #Numero: Descripcion
*/
#include <iostream>
using namespace std;

void mostrarARR(int a[],int tam){
    for(int i=0;i<tam;i++){
        cout<< a[i] << " " ;
    }
}

int main() {
  cout << "\033[2J\033[0;0H";
  cout << "ESTOY EN CARPETA 3.test" << endl;

  
  int arrA1[5]={ 0, 1, 2, 3, 4};
  int arrB1[5]={ 10, 20, 30, 40, 50};
  char hola;
  cin >> hola;
  cout << "\nPALABRA DADA: " << hola << endl;
  cout << "\nArreglo A1: "; mostrarARR(arrA1, 5);
  cout << "\nArreglo B1: "; mostrarARR(arrB1, 5);
}