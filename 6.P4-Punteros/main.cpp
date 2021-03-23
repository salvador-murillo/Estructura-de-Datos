/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #4: Punteros
*/
#include <iostream>
using namespace std;

int ent = 5;
float fl = 3.5;
double db = 1234567891011;
char cr = 's';
char crs[2] = {'A','B'};

int* ap_ent = &ent;
float* ap_fl = &fl;
double* ap_db = &db;
char* ap_cr = &cr;
char* ap_crs0 = &crs[0];
char* ap_crs1 = &crs[1];

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #4: Punteros\n" << endl;
}

void mostrarTipoDato(int valor){

    switch (valor)
    {
        case 1:
            cout << "Tipo INT" << endl;
            cout << "Valor de ent : " << ent << endl;
            cout << "Valor de ent (ap_ent) : " << *ap_ent << endl;
            cout << "Direccion de ent : " << &ent << endl;
            cout << "Direccion de ent (ap_ent) : " << ap_ent << endl;
            cout << "Bytes de ent : " << sizeof(ent)  << endl;
            cout << "Bytes de ent (ap_ent) : " << sizeof(*ap_ent)  << endl;
        break;
        case 2:
            cout << "Tipo FLOAT" << endl;
            cout << "Valor de fl : " << fl << endl;
            cout << "Valor de fl (ap_fl) : " << *ap_fl << endl;
            cout << "Direccion de fl : " << &fl << endl;
            cout << "Direccion de fl (ap_fl) : " << ap_fl << endl;
            cout << "Bytes de fl : " << sizeof(fl)  << endl;
            cout << "Bytes de fl (ap_fl) : " << sizeof(*ap_fl)  << endl;
        break;
        case 3:
            cout << "Tipo DOUBLE" << endl;
            cout << "Valor de db : " << db << endl;
            cout << "Valor de db (ap_db) : " << *ap_db << endl;
            cout << "Direccion de db : " << &db << endl;
            cout << "Direccion de db (ap_db) : " << ap_db << endl;
            cout << "Bytes de db : " << sizeof(db)  << endl;
            cout << "Bytes de db (ap_db) : " << sizeof(*ap_db)  << endl;
        break;
        case 4:
            cout << "Tipo CHAR" << endl;
            cout << "Valor de cr : " << cr << endl;
            cout << "Valor de cr (ap_cr) : " << *ap_cr << endl;
            cout << "Direccion de cr : " << static_cast<const void *>(&cr) << endl;
            cout << "Direccion de cr (ap_cr) : " << static_cast<const void *>(ap_cr) << endl;
            cout << "Bytes de cr : " << sizeof(cr)  << endl;
            cout << "Bytes de cr (ap_cr) : " << sizeof(*ap_cr)  << endl;
        break;
        case 5:
            cout << "Tipo CHAR (mas de 1)" << endl;
            cout << "\nValor de crs[0] : " << crs[0] << endl;
            cout << "Valor de crs[0] (ap_crs0) : " << *ap_crs0 << endl;
            cout << "Direccion de crs[0] : " << static_cast<const void *>(&crs[0]) << endl;
            cout << "Direccion de crs[0] (ap_crs0) : " << static_cast<const void *>(ap_crs0) << endl;
            cout << "Bytes de crs[0] : " << sizeof(crs[0])  << endl;
            cout << "Bytes de crs[0] (ap_crs0) : " << sizeof(*ap_crs0)  << endl;
            
            cout << "\nValor de crs[1] : " << crs[1] << endl;
            cout << "Valor de crs[1] (ap_crs1) : " << *ap_crs1 << endl;
            cout << "Direccion de crs[1] : " << static_cast<const void *>(&crs[1]) << endl;
            cout << "Direccion de crs[1] (ap_crs1) : " << static_cast<const void *>(ap_crs1) << endl;
            cout << "Bytes de crs[1] : " << sizeof(crs[1])  << endl;
            cout << "Bytes de crs[1] (ap_crs1) : " << sizeof(*ap_crs1)  << endl;

            cout << "\nGeneral" << endl;
            cout << "Bytes de crs : " << sizeof(crs) << endl;
        break;
        default:
            cout << "Numero NO valido";
        break;
    }
}

int main() {
    int salir=1;
    int tipoDato=0;
    do{
        mostrarTitulo();
        cout << "Tipos de dato:\n" << endl;
        cout << "1.INT" << endl;
        cout << "2.FLOAT" << endl;
        cout << "3.DOUBLE" << endl;
        cout << "4.CHAR" << endl;
        cout << "5.CHAR (mas de 1)" << endl;
        cout << "\nSeleccione: "; cin >> tipoDato;
        mostrarTitulo();
        mostrarTipoDato(tipoDato);
        cout << "\nMostrar otro tipo de dato? 1-SI 2-NO: "; cin >>salir;
    }while(salir==1);
}