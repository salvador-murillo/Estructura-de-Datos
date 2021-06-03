/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Test: Para depuracion de fragmentos de codigo
*/
#include <iostream>
#include <unistd.h>
using namespace std;

int aNormal(int a){
  int b=5;
  a=b;
  return a+b;
}

int aDireccion(int &a){
  int b=40;
  a=b;
  return a+b;
}

int aPuntero(int *a){
  int b=80;
  *a=b;
  return *a+b;
}
int main(){
  int A=10;
  cout << "Resultado de aNormal(A): " << aNormal(A) << "    Valor de A: " << A << endl;
  cout << "Resultado de aDireccion(A): " << aDireccion(A) << " Valor de A: " << A << endl;
  cout << "Resultado de aPuntero(A): " << aPuntero(&A) << "   Valor de A: " << A << endl;
}