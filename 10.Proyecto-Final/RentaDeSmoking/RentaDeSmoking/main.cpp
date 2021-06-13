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
        // cout << "TEST" << endl;
        opc = mostrarMenu();
        cin.ignore();
        opc==11 ? salir=2 : salir=1;
        selecOpc(lista,opc);
    }while(salir==1);
}

void selecOpc(Smoking *&lista, int opc){
    switch (opc)
    {
    case 1:
        addSuit(lista); // 32 VERDE
        break;
    case 2:
        removeSuit(lista); //31 ROJO
        break;
    case 3:
        checkData(lista); // 33 AMARILLO
        break;
    case 4:
        showSuits(lista); // 36 AZUL CLARO
        break;
    case 5:
        //FIXME Corregir funcion
        searchBySize(lista); // 33 AMARILLO
        break;
    case 6:
        searchByID(lista);
        break;
    case 7:
        // writeFile(lista);
        break;
    case 8:
        /* code */
        break;
    case 9:
        assignSuit(lista); //37 BLANCO
        break;
    case 10:
        /* code */
        break;
    default:
        break;
    }
}
