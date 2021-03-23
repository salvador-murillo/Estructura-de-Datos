/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #5: Par-Impar por medio de Punteros
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #5: Par-Impar por medio de Punteros\n" << endl;
}

int main() {
    int salir=1;
    int num=0;
    int *ap_num = &num;
    do{
        mostrarTitulo();
        cout << "\nIngresa un numero: "; cin >> *ap_num;
        *ap_num % 2 == 0 
            ? cout << "Numero PAR" << endl
            : cout << "Numero IMPAR" << endl;
        cout << "Direccion de Numero: " << &num << endl;
        cout << "Direccion de Numero (ap_num): " << ap_num << endl;
        cout << "\nIngresar otro numero? 1-SI 2-NO: "; cin >>salir;
    }while(salir==1);
}