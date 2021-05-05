/*
CUCEA | Estructura de Datos | Salvador Murillo Arias

*/
#include <iostream>
using namespace std;

struct numeros
{
    int dato[10];
};


int main(){
    cout << "\033[2J\033[0;0H";
    numeros primeraOleada; //Dato primeraOleada de tipo numeros
    numeros *segundaOleada = &primeraOleada; // Apuntador segundaOleada a primeraOleada de tipo numeros

    cout << "Direccion de primeraOleada: " << &primeraOleada << endl;
    cout << "Tamanio de primeraOleada: " << sizeof(primeraOleada) << endl;
    cout << "Direccion de primeraOleada por segunda: " << segundaOleada << endl;
    cout << "Direccion de segundaOleada: " << &segundaOleada << endl;
    cout << "Tamanio de puntero segundaOleada: " << sizeof(segundaOleada) << endl;

    
    //Por medio de primeraOleada
    for (int i = 0; i < 10; i++)
    {   
        primeraOleada.dato[i]=i+1; // Ingresar datos
        cout << "Valor: " << primeraOleada.dato[i] << endl; // Mostrar datos
        cout << "Direccion: " << &primeraOleada.dato[i] << endl; // Mostrar direccion
    }
  
    //Por medio de segundaOleada
    for (int i = 0, j=10; i < 10; i++,j--)
    {   
        segundaOleada->dato[i]=j; // Invertir datos
        cout << "Valor: " << segundaOleada->dato[i] << endl; // Mostrar datos
        cout << "Direccion: " << &segundaOleada->dato[i] << endl; // Mostrar direccion
    }     
}