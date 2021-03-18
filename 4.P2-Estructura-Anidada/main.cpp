/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #2: Estructura Anidada
*/
#include <iostream>
#include <string>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #2: Estructura Anidada\n" << endl;
}

typedef struct fecha{
    int  dia, mes, anio;
};

typedef struct datosAutor{
    string nombre;
    char apeP[15], apeM[15];
    fecha f_nacimiento;
};

typedef struct biblioteca{
    string nombreLibro;
    fecha f_publicacion;
    fecha f_ingreso;
    datosAutor autor;
    char isbn[16];
    float precio;
};

typedef biblioteca biblio;

int main() {
    mostrarTitulo();
    biblioteca libro1;
    
    //Captura de Datos
    cout << "\nREGISTRO DE LIBRO\n";
    cout << "\nTitulo: "; getline(cin, libro1.nombreLibro);
    cout << "\nFecha Publicacion: ";
    cout << "\nDia: "; cin >> libro1.f_publicacion.dia;
    cout << "Mes: "; cin >> libro1.f_publicacion.mes;
    cout << "Anio: "; cin >> libro1.f_publicacion.anio;
    cout << "\nFecha Ingreso a Biblioteca: ";
    cout << "\nDia: "; cin >> libro1.f_ingreso.dia;
    cout << "Mes: "; cin >> libro1.f_ingreso.mes;
    cout << "Anio: "; cin >> libro1.f_ingreso.anio;
    cin.ignore();
    cout << "\nAUTOR\n"; 
    cout << "Nombre: "; getline(cin, libro1.autor.nombre);
    cout << "Apellido Paterno: "; cin >> libro1.autor.apeP;
    cout << "Apellido Materno: "; cin >> libro1.autor.apeM;
    cout << "\nFecha Nacimiento Autor: ";
    cout << "\nDia: "; cin >> libro1.autor.f_nacimiento.dia;
    cout << "Mes: "; cin >> libro1.autor.f_nacimiento.mes;
    cout << "Anio: "; cin >> libro1.autor.f_nacimiento.anio;
    cout << "\nISBN: "; cin >> libro1.isbn;
    cout << "\nPrecio: $"; cin >> libro1.precio;

    //Mostrar Datos
    mostrarTitulo();
    cout << "\n\t\t\tLIBRO\n\n";
    cout << "              TITULO: " << libro1.nombreLibro << endl;
    cout << "         PUBLICACION: " << libro1.f_publicacion.dia << "/" << libro1.f_publicacion.mes << "/" << libro1.f_publicacion.anio << endl;
    cout << "INGRESO A BIBLIOTECA: " << libro1.f_ingreso.dia << "/" << libro1.f_ingreso.mes << "/" << libro1.f_ingreso.anio << endl;
    cout << "                ISBN: " << libro1.isbn << endl;
    cout << "              PRECIO: " << libro1.precio << endl;
    cout << "\n\t\t\tAUTOR\n\n";
    cout << "              NOMBRE: " << libro1.autor.nombre << " " << libro1.autor.apeP << " " << libro1.autor.apeM << endl;
    cout << "    FECHA NACIMIENTO: " << libro1.autor.f_nacimiento.dia << "/" << libro1.autor.f_nacimiento.mes << "/" << libro1.autor.f_nacimiento.anio << endl;
}