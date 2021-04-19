/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #9: Funciones String
*/
#include <iostream>
#include <string>
using namespace std;

int MAX_LENGTH = 30;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #9: Funciones String\n" << endl;
}

int main(){

    char nombre[MAX_LENGTH];
    char apellido[MAX_LENGTH];
    char aux[MAX_LENGTH];

    mostrarTitulo();
    cout << "Ingresa un nombre: ";
    cin >> nombre;
    cout << "Ingresa un apellido: ";
    cin >> apellido;
    cout << "Ingresa otro apellido: ";
    cin >> aux;

    cout << "\n--strlen: LONGITUD DE CADENAS--\n";
    cout << "(" << strlen(nombre) << ") " << nombre << endl;
    cout << "(" << strlen(apellido) << ") " << apellido << endl;
    cout << "(" << strlen(aux) << ") " << aux << endl;
    cout << "\n--strcat: CONCATENACION DE STRINGS--\n";
    cout << nombre << " + " << apellido << " = " << strcat(nombre, apellido);
    cout << "\n\n--strcmp: COMPARAR 2 STRINGS--\n";
    cout << "'" << apellido << "' es igual a '" << aux << "' ? R= ";
    strcmp(apellido,aux)==0 ? cout << "Son iguales" : cout << "NO son iguales";
    cout << "\n\n--strcpy: COMPIAR CONTENIDO DE UNA CADENA A OTRA--\n";
    cout << "Valores antes | 'apellido': " << apellido << " | 'auxiliar': " << aux << endl;
    strcpy(apellido, aux);
    cout << "Valores despues | 'apellido': " << apellido << " | 'auxiliar': " << aux << endl;
}