/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Proyecto Final: Sistema de Renta Smoking
*/
#include <iostream>
#include "headers/intro.hpp"
#include "headers/struct-smoking.hpp"
using namespace std;

void selecOpc(Smoking *&lista, int opc);

int main() {
    int salir=1;
    Smoking *lista = nullptr;
    mostrarIntro();
    do{
        int opc=0;
        cout << "TEST" << endl; 
        opc = mostrarMenu();
        cin.ignore();
        opc==11 ? salir=2 : salir=1;
        selecOpc(lista,opc);
    }while(salir==1);
}

void selecOpc(Smoking *&lista, int opc){
    int num=0;
    switch (opc)
    {
    case 1:
        do{
            mostrarTitle();
            altaTraje(lista);
            cout << "\nAgregar otro traje 1.SI 2.NO: ";
            cin >> num;
            cin.ignore();
            pressEnter();
        }while(num==1);
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        /* code */
        break;
    case 10:
        /* code */
        break;
    default:
        break;
    }
}