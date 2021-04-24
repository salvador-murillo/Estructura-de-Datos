/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #3: Arreglos y Funciones de Estructuras
*/
#include <iostream>
#include <string>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #3: Arreglos y Funciones de Estructuras\n" << endl;
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

void llenarLibros(biblioteca libros[], int num){
    
    for (int i=0; i<num; i++){
        //Captura de Datos
        cin.ignore();
        cout << "\nREGISTRO LIBRO #" << i+1 << endl;
        cout << "\nTitulo: "; getline(cin, libros[i].nombreLibro);
        cout << "\nFecha Publicacion\n";
        cout << "Dia: "; cin >> libros[i].f_publicacion.dia;
        cout << "Mes: "; cin >> libros[i].f_publicacion.mes;
        cout << "Anio: "; cin >> libros[i].f_publicacion.anio;
        cout << "\nFecha Alta a Biblioteca\n";
        cout << "Dia: "; cin >> libros[i].f_ingreso.dia;
        cout << "Mes: "; cin >> libros[i].f_ingreso.mes;
        cout << "Anio: "; cin >> libros[i].f_ingreso.anio;
        cin.ignore();
        cout << "\nAUTOR\n"; 
        cout << "Nombre: "; getline(cin, libros[i].autor.nombre);
        cout << "Apellido Paterno: "; cin >> libros[i].autor.apeP;
        cout << "Apellido Materno: "; cin >> libros[i].autor.apeM;
        cout << "\nFecha Nacimiento Autor\n";
        cout << "Dia: "; cin >> libros[i].autor.f_nacimiento.dia;
        cout << "Mes: "; cin >> libros[i].autor.f_nacimiento.mes;
        cout << "Anio: "; cin >> libros[i].autor.f_nacimiento.anio;
        cout << "\nISBN: "; cin >> libros[i].isbn;
        cout << "\nPrecio: $"; cin >> libros[i].precio;
        cout << "\033[2J\033[0;0H";
    }
}

void mostrarLibros(biblioteca libros[], int num){
    num=num-1;
    cout << "\n\t\t\tLIBRO #" << num+1 << "\n\n";
    cout << "              TITULO: " << libros[num].nombreLibro << endl;
    cout << "         PUBLICACION: " << libros[num].f_publicacion.dia << "/" << libros[num].f_publicacion.mes << "/" << libros[num].f_publicacion.anio << endl;
    cout << "INGRESO A BIBLIOTECA: " << libros[num].f_ingreso.dia << "/" << libros[num].f_ingreso.mes << "/" << libros[num].f_ingreso.anio << endl;
    cout << "                ISBN: " << libros[num].isbn << endl;
    cout << "              PRECIO: " << libros[num].precio << endl;
    cout << "\n\t\t\tAUTOR\n\n";
    cout << "              NOMBRE: " << libros[num].autor.nombre << " " << libros[num].autor.apeP << " " << libros[num].autor.apeM << endl;
    cout << "    FECHA NACIMIENTO: " << libros[num].autor.f_nacimiento.dia << "/" << libros[num].autor.f_nacimiento.mes << "/" << libros[num].autor.f_nacimiento.anio << endl;
}


int main() {
    mostrarTitulo();
    int tam=0, numLibro=0, salir=0;
    cout << "Libros a dar de alta: "; cin >> tam;
    biblioteca books[tam];
    llenarLibros(books, tam);
    do{
        mostrarTitulo();
        cout << "Libros Registrados:\n";
        for(int i=0; i<tam; i++){
            cout << "\n\t" << i+1 << "." << books[i].nombreLibro;
        }
        cout << "\n\nEscribe # de libro a mostrar: "; cin >> numLibro;
        mostrarLibros(books, numLibro);
        cout << "\nMostrar otro libro? 1-SI 2-NO: "; cin >> salir;
    }while(salir!=2);
}