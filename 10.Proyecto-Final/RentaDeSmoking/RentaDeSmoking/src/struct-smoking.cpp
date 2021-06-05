#include <iostream>
#include <string>
#include "../headers/struct-smoking.hpp"
#include "../headers/intro.hpp"
using namespace std;

bool checkID(Smoking *lista, int num){
    Smoking *actual = lista;
    while(actual != nullptr){
        if(actual->id == num)
            return true;
        actual = lista;
        lista = actual->next;
    }
    return false;
}

void trajeID(Smoking *&nvoSuit, Smoking *lista){
    Smoking *actual = new Smoking();
    actual = lista;
    bool checkNum = false;
    int num = 0;
    cout << "\n\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
    cout << "\n\033[7;3;33mID: \033[1;3;36m(5 numeros)\033[0m";
    if(actual != nullptr){
        while(checkNum == false){
            cout << "\nIntroduzca ID: ";
            cin >> num;
            if(checkID(actual, num) == false){
                cout << "ESTOY  EN ELSE" << endl;
                // nvoSuit->id = num;
                checkNum = true;
            }else{
                cout << "NOTA! El ID ingresado ya existe." << endl;
                cin.ignore();
                pressEnter();
                mostrarTitle();
                cout << "\n\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
                cout << "\n\033[7;3;33mID: \033[1;3;36m(5 numeros)\033[0m";
            }
        }
    }else{
        cout << "\nID: ";
        cin >> nvoSuit->id;
    }
}

void newTraje(Smoking *&nvoSuit){
    // Valores por default
    nvoSuit->isAlquilado = false;
    nvoSuit->diasPrestamo = 0;
    nvoSuit->totalPagar = 0;
    nvoSuit->totalAbono = 0;
    strcpy(nvoSuit->nombreCliente, "SIN ASIGNAR");
    // //Valores a llenar
    cout << "\n\033[7;3;33mTALLA: \033[1;3;36m 1.CH 2.MD 3.GD\033[0m\nQue talla es: ";
    cin >> nvoSuit->talla;
    cout << "\n\033[7;3;33mMODELO: \033[1;3;36m 1.Slim 2.Skinny 3.Comfort\033[0m\nQue modelo es: ";
    cin >> nvoSuit->modelo;
    cout << "\n\033[7;3;33mPRECIO\033[0m\nIngresa el costo por dia $";
    cin >> nvoSuit->precioDiario;
}

void altaTraje(Smoking *&lista){
    Smoking *nvoSuit = new Smoking();
    //Funcion Llenar datos del Smoking

    trajeID(nvoSuit, lista);
    newTraje(nvoSuit);

    //TODO Agregar funcion para ordenar por talla al momento de la insercion
    nvoSuit->next = lista;
    nvoSuit->prev = nullptr;

    if(lista != nullptr)
        lista->prev = nvoSuit;

    lista = nvoSuit;
}

