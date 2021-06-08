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
    Smoking *auxList = nullptr;
    switch (opc)
    {
    case 1:
        do{
            mostrarTitle();
            addSuit(lista);
            cout << "\nAgregar otro traje 1.SI 2.NO: ";
            cin >> num;
        }while(num==1);
        break;
    case 2:
        mostrarTitle();
        removeSuit(lista);
        break;
    case 3:
        /* code */
        break;
    case 4:
        showSuits(lista);
        break;
    case 5:
        searchBySize(lista, auxList);
        break;
    case 6:
        // searchByID(lista);
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        assignSuit(lista);
        break;
    case 10:
        /* code */
        break;
    default:
        break;
    }
}
