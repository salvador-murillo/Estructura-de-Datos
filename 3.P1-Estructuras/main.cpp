/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #1: Estructuras
*/
#include <iostream>
using namespace std;

typedef struct biblioteca{
    char titulo[20];
    char editorial[15];
    int anioPublicacion;
    char autor[20];
    char ciudadPublicacion[20];
    char isbn[13];
    float precio;
};

int main() {
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #1: Estructura\n" << endl;

    biblioteca libro1;
    cout << "\nREGISTRO DE LIBRO\n";
    cout << "\nTitulo: "; cin >> libro1.titulo;
    cout << "\nEditorial: "; cin >> libro1.editorial;
    cout << "\nAnio Publicacion: "; cin >> libro1.anioPublicacion;
    cout << "\nAutor: "; cin >> libro1.autor;
    cout << "\nCiudad Publicacion: "; cin >> libro1.ciudadPublicacion;
    cout << "\nISBN: "; cin >> libro1.isbn;
    cout << "\nPrecio: $"; cin >> libro1.precio;

    cout << "\nLibro:\n";
    cout << "TITULO: " << libro1.titulo << endl;
    cout << "EDITORIAL: " << libro1.editorial << endl;
    cout << "ANIO: " << libro1.anioPublicacion << endl;
    cout << "AUTOR: " << libro1.autor << endl;
    cout << "CIUDAD: " << libro1.ciudadPublicacion << endl;
    cout << "ISBN: " << libro1.isbn << endl;
    cout << "PRECIO: " << libro1.precio << endl;
    
}