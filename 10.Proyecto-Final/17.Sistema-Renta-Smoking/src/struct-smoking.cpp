#include <iostream>
#include <string>
#include "../headers/struct-smoking.hpp"
#include "../headers/intro.hpp"
using namespace std;


bool checkID(Smoking *lista, int num){
    Smoking *aux = lista;
    while(aux != nullptr){
        if(aux->id == num)
            return true;
        aux = aux->next;
    }
    return false;
}

bool checkTalla(int n){
    switch (n)
    {
    case 1:
        return true;
        break;
    case 2:
        return true;
        break;
    case 3:
        return true;
        break;
    default:
        cout << "\nNumero NO valido" << endl;
        return false;
        break;
    }
}

void trajeID(Smoking *&nvoSuit, Smoking *lista){
    Smoking *actual = new Smoking();
    actual = lista;
    bool checkNum, checkDigit = false;
    int num = 0;

    while(checkNum == false && checkDigit == false)
    {
        if(actual != nullptr)
        {
            cout << "\n\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
            cout << "\n\033[7;3;33mID: \033[1;3;36m(4 numeros)\033[0m";
            cout << "\nID: ";
            cin >> num;
            if(num>0 && num<10000)
            {
                checkDigit = true;
                if(checkID(actual, num) == false)
                {
                    nvoSuit->id = num;
                    checkNum = true;
                }else
                {
                    cout << "NOTA! El ID ingresado ya existe." << endl;
                    checkDigit = false;
                    cin.ignore();
                    pressEnter();
                    mostrarTitle();
                }
            }else
            {
                cout << "NOTA! Numero mayor de 4 digitos" << endl;
                cin.ignore();
                pressEnter();
                mostrarTitle();
            }
        }else
        {
            cout << "\n\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
            cout << "\n\033[7;3;33mID: \033[1;3;36m(4 numeros)\033[0m";
            cout << "\nID: ";
            cin >> num;
            if(num>0 && num<10000)
            {
                checkDigit = true;
                checkNum = true;
                nvoSuit->id = num;
            }else
            {
                cout << "NOTA! Numero mayor de 4 digitos" << endl;
                cin.ignore();
                pressEnter();
                mostrarTitle();
            }
        }
    }
}

void newTraje(Smoking *&nvoSuit){
    int num = 0;
    bool numIsValid = true;

    // Valores por default
    nvoSuit->isAlquilado = false;
    nvoSuit->diasPrestamo = 0;
    nvoSuit->totalPagar = 0;
    nvoSuit->totalAbono = 0;
    strcpy(nvoSuit->nombreCliente, "SIN ASIGNAR");

    //Valores a llenar
    while(numIsValid==true){//TALLA
        cout << "\n\033[7;3;33mTALLA: \033[1;3;36m 1.CH 2.MD 3.GD\033[0m\nQue talla es: ";
        cin >> num;
        if(checkTalla(num)==true){
            nvoSuit->talla = num;
            numIsValid = false;
        }
    }
    while(numIsValid==true){//MODELO
        cout << "\n\033[7;3;33mMODELO: \033[1;3;36m 1.Slim 2.Skinny 3.Comfort\033[0m\nQue modelo es: ";
        cin >> num;
        if(checkTalla(num)==true){
            nvoSuit->modelo = num;
            numIsValid = false;
        }
    }
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

