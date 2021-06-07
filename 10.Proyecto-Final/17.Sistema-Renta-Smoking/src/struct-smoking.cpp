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
    case 1: case 2: case 3:
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
            cout << "\n\033[7;3;33mID: \033[1;3;36m hasta 4 digitos ejemplo '1' o '1234'\033[0m";
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
                cout << "NOTA! Numero negativo o mayor de 4 digitos" << endl;
                cin.ignore();
                pressEnter();
                mostrarTitle();
            }
        }else
        {
            cout << "\n\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
            cout << "\n\033[7;3;33mID: \033[1;3;36m hasta 4 digitos ejemplo '1' o '1234'\033[0m";
            cout << "\nID: ";
            cin >> num;
            if(num>0 && num<10000)
            {
                checkDigit = true;
                checkNum = true;
                nvoSuit->id = num;
            }else
            {
                cout << "NOTA! Numero negativo o mayor de 4 digitos" << endl;
                cin.ignore();
                pressEnter();
                mostrarTitle();
            }
        }
    }
}

void newTraje(Smoking *&nvoSuit){
    int num = 0;
    bool tallaValido = true, modeloValido = true;

    // Valores por default
    nvoSuit->isAlquilado = false;
    nvoSuit->diasPrestamo = 0;
    nvoSuit->totalPagar = 0;
    nvoSuit->totalAbono = 0;
    // strcpy(nvoSuit->nombreCliente, "SIN ASIGNAR");

    //Valores a llenar
    while(tallaValido==true){//TALLA
        cout << "\n\033[7;3;33mTALLA: \033[1;3;36m 1.CH 2.MD 3.GD\033[0m\nQue talla es: ";
        cin >> num;
        if(checkTalla(num)==true){
            nvoSuit->talla = num;
            tallaValido = false;
        }
    }
    while(modeloValido==true){//MODELO
        cout << "\n\033[7;3;33mMODELO: \033[1;3;36m 1.Slim 2.Skinny 3.Comfort\033[0m\nQue modelo es: ";
        cin >> num;
        if(checkTalla(num)==true){
            nvoSuit->modelo = num;
            modeloValido = false;
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

void bajaTraje(Smoking *&lista){
    int getID = 0;
    int opc = 1;
    bool idValid = false, numValid = false, searchAgain = false;
    Smoking *actual = new Smoking();

    while(searchAgain == false)
    {
        //Lista Vacia
        if(lista == nullptr)
        {   
            mostrarTitle();
            cout << "\n\033[7;31m****** BAJA DE SMOKING ******\033[0m\n";
            cout<<"\nLista vacia" << endl;
            pressEnter();
            return;
        }

        while(numValid == false && lista !=nullptr)
        {
            actual = lista;
            idValid = false;
            mostrarTitle();
            cout << "\n\033[7;31m****** BAJA DE SMOKING ******\033[0m\n";
            cout << "\nIngresa el ID del Smoking a borrar: ";
            cin >> getID;
            if(getID>0 && getID<10000)
            {
                numValid = true;
                while (actual != nullptr && idValid == false)
                {
                    if(actual->id == getID)
                        idValid = true;
                    if(idValid==false)
                        actual = actual->next; 
                }
            }
            else
            {
                cout << "\nNOTA! Numero negativo o mayor de 4 digitos";
                cout << "\nBuscar/Borrar otro? 1-SI 2-NO: ";
                cin >> opc;
                if(opc==1) cin.ignore(); else return;
            }
        }
        //Si el ID existe y es valido, comprobar que NO este alquilado
        if(numValid == true && idValid == true)
        {   
            // cout << "\nEl ID si existe";
            if(actual->isAlquilado != true)
            {
                cout << "\nEl smoking no se encuentra alquilado";
                //Funcion Borrar Smoking
                //Si se encuentra en la primera posicion, se mueve hacia la siguiente
                if(lista == actual)
                    lista = actual->next;

                //Si se encuentra en medio de la lista
                if(actual->next != NULL)
                    actual->next->prev = actual->prev; //Doble secuencia para llegar al apuntador del siguiente nodo

                if(actual->prev != NULL)
                    actual->prev->next = actual->next; //Doble secuencia para llegar al apuntador del siguiente nodo

                delete(actual);
                cout << "\nSe ha borrado el smoking del sistema";
            }
            else
                cout << "\nEl smoking se encuentra alquilado"; //Condicion si esta alquilado NO se puede dar de baja
        }                
        else if(numValid == true && lista !=nullptr)
            cout << "\nEl ID no existe";
        
        cout << "\n\nBuscar/Borrar otro? 1-SI 2-NO: ";
        cin >> opc;
        (opc==1) ? numValid = false : searchAgain = true;
        pressEnter();
    }
}