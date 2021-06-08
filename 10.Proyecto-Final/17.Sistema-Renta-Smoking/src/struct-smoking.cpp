#include <iostream>
#include <string.h>
#include "../headers/struct-smoking.hpp"
#include "../headers/intro.hpp"
using namespace std;

int countSuits(Smoking *lista)
{
    int count = 0;
    Smoking *aux = lista;
    while (aux != nullptr)    
    {
        count++;
        aux = aux->next; 
    }
    return count;
}

bool checkID(Smoking *lista, int num)
{
    Smoking *aux = lista;
    while(aux != nullptr){
        if(aux->id == num)
            return true;
        aux = aux->next;
    }
    return false;
}

bool checkSize(int n)
{
    switch (n)
    {
        case 1: case 2: case 3:
            return true;
            break;
        default:
            return false;
            break;
    }
}

void suitID(Smoking *&nvoSuit, Smoking *lista)
{
    Smoking *actual = new Smoking();
    actual = lista;
    bool checkNum = false, checkDigit = false;
    int num = 0;

    while(checkNum == false && checkDigit == false)
    {
        if(actual != nullptr)
        {
            cout << "\n\t\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
            cout << "\n\033[1;37mID \033[1;35mhasta 4 digitos ejemplo '1' o '1234'\033[0m: ";
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
                    cout << "\n\033[1;31mNOTA!\033[0m El ID ingresado ya existe." << endl;
                    checkDigit = false;
                    cin.ignore();
                    pressEnter();
                    mostrarTitle();
                }
            }else
            {
                cout << "\n\033[1;31mNOTA!\033[0mNOTA! Numero negativo o mayor de 4 digitos" << endl;
                cin.ignore();
                pressEnter();
                mostrarTitle();
            }
        }else
        {
            cout << "\n\t\033[7;32m****** ALTA DE SMOKING ******\033[0m\n";
            cout << "\n\033[1;37mID \033[1;35mhasta 4 digitos ejemplo '1' o '1234'\033[0m: ";
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

void dataSuit(Smoking *&nvoSuit)
{
    int num = 0;
    bool tallaValido = true, modeloValido = true;

    // Valores por default
    nvoSuit->isAlquilado = false;
    nvoSuit->diasPrestamo = 0;
    nvoSuit->totalPagar = 0;
    nvoSuit->totalAbono = 0;
    nvoSuit->totalRestante = 0;
    strcpy(nvoSuit->nombreCliente, "Sin Asignar");

    //Valores a llenar
    while(tallaValido==true){//TALLA
        cout << "\n\033[1;37mTALLA \033[1;35m1.CH 2.MD 3.GD\033[0m: ";
        cin >> num;
        if(checkSize(num)==true){
            nvoSuit->talla = num;
            tallaValido = false;
        }else
            cout << "\nNumero NO valido" << endl;
    }
    while(modeloValido==true){//MODELO
        cout << "\n\033[1;37mMODELO \033[1;35m1.Slim 2.Skinny 3.Comfort\033[0m: ";
        cin >> num;
        if(checkSize(num)==true)
        {
            nvoSuit->modelo = num+3;
            modeloValido = false;
        }else
            cout << "\nNumero NO valido" << endl;
    }
    cout << "\n\033[1;37mPRECIO \033[1;35mIngresa el costo por dia \033[0m$";
    cin >> nvoSuit->precioDiario;
    cin.ignore();
    cout << "\n\033[1;37mMARCA \033[1;35mIngresa la marca: \033[0m";
    cin.getline(nvoSuit->marca, 25, '\n');

}

void addSuit(Smoking *&lista)
{
    Smoking *nvoSuit = new Smoking();
    Smoking *addLast = lista;
    //Funcion Llenar datos del Smoking
    suitID(nvoSuit, lista);
    dataSuit(nvoSuit);

    //Para lista vacia
    nvoSuit->next = nullptr;
    if(lista == nullptr){
        nvoSuit->prev = nullptr;
        lista = nvoSuit;
        return;
    }
    //Recorre hasta la ultima posicion
    while(addLast->next != nullptr)
        addLast = addLast->next; 

    addLast->next = nvoSuit;
    nvoSuit->prev = addLast;

    //TODO Agregar funcion para ordenar por talla al momento de la insercion 

}

void removeSuit(Smoking *&lista)
{
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
            cout << "\n\t\033[7;31m****** BAJA DE SMOKING ******\033[0m\n";
            cout<<"\nNo hay smokings disponibles para borrar" << endl;
            pressEnter();
            return;
        }

        while(numValid == false && lista !=nullptr)
        {
            actual = lista;
            idValid = false;
            mostrarTitle();
            cout << "\n\t\033[7;31m****** BAJA DE SMOKING ******\033[0m\n";
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
                cout << "\n\nBuscar/Borrar otro? 1-SI 2-NO: ";
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
                cout << "\nEl smoking NO se encuentra alquilado";
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
            else{
                //Condicion si esta alquilado NO se puede dar de baja
                cout << "\nEl smoking SE encuentra alquilado";
                cout << "\nNo se puede borrar hasta que sea entregado";
            }
        }                
        else if(numValid == true && lista !=nullptr)
            cout << "\nEl ID no existe";
        
        cout << "\n\nBuscar/Borrar otro? 1-SI 2-NO: ";
        cin >> opc;
        (opc==1) ? numValid = false : searchAgain = true;
        pressEnter();
    }
}

void showSuits(Smoking *lista)
{
    int count = 1;
    int getNumberSuits = countSuits(lista);

    //Lista Vacia
    if(lista == nullptr)
    {   
        mostrarTitle();
        cout << "\n\t\033[7;36m****** LISTA SMOKINGS ******\033[0m\n";
        cout<<"\nNo hay smokings disponibles para mostrar" << endl;
        pressEnter();
        return;
    }

    while (lista != nullptr)
    {
        mostrarTitle();
        cout << "\n\t\033[7;36m****** LISTA SMOKINGS ******\033[0m\n";    
        cout << "\n\033[1;36mSmoking #"<< count;
        cout << "  \033[1;3;37mID:\033[0m " << lista->id;
        cout << "  \033[1;3;37mSTATUS:\033[0m "; (lista->isAlquilado==false) ? cout << "\033[1;33mDisponible": cout << "\033[1;31mAlquilado";
        cout << "\n\033[1;3;37m\nMARCA:\033[0m " << lista->marca;
        cout << "\n\033[1;3;37mTALLA:\033[0m "; 
        (lista->talla==1) ? cout << "Chica": (lista->talla==2) ? cout << "Mediana": cout << "Grande";
        cout << " - \033[1;3;37mMODELO:\033[0m "; 
        (lista->modelo==4) ? cout << "Slim": (lista->modelo==5) ? cout << "Skinny": cout << "Comfort";
        cout << "\n\033[1;3;37mPRECIO DIARIO  $\033[0m" << lista->precioDiario;
        cout << "\n\033[1;3;37m\nNOMBRE CLIENTE:\033[0m " << lista->nombreCliente;
        cout << "\n\033[1;3;37mFECHA SALIDA\033[0m " << lista->fechaPrestamo.day << "/" << lista->fechaPrestamo.month << "/" << lista->fechaPrestamo.year;
        cout << " - \033[1;3;37mENTREGA\033[0m " << lista->fechaEntrega.day << "/" << lista->fechaEntrega.month << "/" << lista->fechaEntrega.year;
        cout << "\n\033[1;3;37m\nDIAS A PRESTAMO:\033[0m " << lista->diasPrestamo;
        cout << "\n\033[1;3;37mTOTAL A PAGAR  $\033[0m" << lista->totalPagar;
        cout << "\n\033[1;3;37mTOTAL ABONO    $\033[0m" << lista->totalAbono;
        cout << "\n\033[1;3;37mTOTAL RESTANTE $\033[0m" << lista->totalRestante << endl;
        count++;
        lista = lista->next;
        if(getNumberSuits>1)
        {
            cout << "\nPresione \033[1;31menter\033[0m para mostrar traje siguiente ...";
            cin.ignore();
            getNumberSuits--;
        }
    }
    pressEnter();
}

void searchBySize(Smoking *lista, Smoking *&listBySize)
{
    int getSize = 0, opc = 0;
    //Lista Vacia
    if(lista == nullptr)
    {   
        mostrarTitle();
        cout << "\n\t\033[7;33m***** BUSQUEDA POR TALLA *****\033[0m\n";
        cout<<"\nNo hay smokings disponibles para mostrar" << endl;
        pressEnter();
        return;
    }
    //Checar items iguales
    do{
        Smoking *aux = new Smoking();
        aux=lista;
        mostrarTitle();
        cout << "\n\t\033[7;33m***** BUSQUEDA POR TALLA *****\033[0m\n";
        cout << "\nTALLAS: 1.CHICA 2.MEDIANA 3.GRANDE";
        cout << "\nIngresa la talla a mostrar: ";
        cin >> getSize;
        if(checkSize(getSize)==true)
        {
            while(aux != nullptr)
            {
                if(aux->talla==getSize)
                {
                    if(listBySize==nullptr)
                    {
                        listBySize->id=aux->id;
                        listBySize->diasPrestamo=aux->diasPrestamo;
                        listBySize->fechaEntrega=aux->fechaEntrega;
                        listBySize->fechaPrestamo=aux->fechaPrestamo;
                        listBySize->isAlquilado=aux->isAlquilado;
                        strcpy(listBySize->marca,aux->marca);
                        listBySize->modelo=aux->modelo;
                        listBySize->talla=aux->talla;
                        strcpy(listBySize->nombreCliente,aux->nombreCliente);
                        listBySize->precioDiario=aux->precioDiario;
                        listBySize->totalAbono=aux->totalAbono;
                        listBySize->totalPagar=aux->totalPagar;
                        listBySize->totalRestante=aux->totalRestante;
                        listBySize->prev=nullptr;
                    }
                    else if(listBySize!=nullptr)
                    {
                        listBySize->id=aux->id;
                        listBySize->diasPrestamo=aux->diasPrestamo;
                        listBySize->fechaEntrega=aux->fechaEntrega;
                        listBySize->fechaPrestamo=aux->fechaPrestamo;
                        listBySize->isAlquilado=aux->isAlquilado;
                        strcpy(listBySize->marca,aux->marca);
                        listBySize->modelo=aux->modelo;
                        listBySize->talla=aux->talla;
                        strcpy(listBySize->nombreCliente,aux->nombreCliente);
                        listBySize->precioDiario=aux->precioDiario;
                        listBySize->totalAbono=aux->totalAbono;
                        listBySize->totalPagar=aux->totalPagar;
                        listBySize->totalRestante=aux->totalRestante;
                        listBySize->prev=listBySize;
                        listBySize->next=nullptr;
                    }
                }
                aux = aux->next;              
            }
            delete(aux);
            showSuits(listBySize);
        }else
            cout << "\nTalla NO existente\n";
        cout << "\nBuscar/Mostrar de nuevo ? 1-SI 2-NO: ";
        cin >> opc;   
    }while (opc!=2);
}

void assignSuit(Smoking *&lista){
    int num = 0, opc = 0, diasP = 0;
    //Lista Vacia
    if(lista == nullptr)
    {   
        mostrarTitle();
        cout << "\n\t\033[7;34m***** ASIGNACION DE TRAJE *****\033[0m\n";
        cout<<"\nNo hay smokings disponibles para alquilar" << endl;
        pressEnter();
        return;
    }

    do
    {
        Smoking *aux = lista;
        bool diasValid = false;
        mostrarTitle();
        cout << "\n\t\033[7;34m***** ASIGNACION DE TRAJE *****\033[0m\n";
        cout << "\nIngresa el ID a asignar: ";
        cin >> num;
        if(num>0 && num<10000)
        {
            while(aux!=nullptr)
            {
                if(aux->id==num && aux->isAlquilado == false)
                {
                    cin.ignore();
                    aux->isAlquilado = true;
                    cout << "\nIngresa los siguientes datos:";
                    cout << "\nNOMBRE: ";
                    cin.getline(aux->nombreCliente, 25, '\n');
                    cout << "\nIngresa los dias de prestamo (de 1 a 10 max)";
                    while(diasValid==false){
                        cout << "\nDIAS: ";
                        cin >> diasP;
                        if(diasP>=1 && diasP<=10){
                            aux->diasPrestamo=diasP;
                            diasValid=true;
                        }
                        else
                            cout << "\nDias no validos, escoge entre 1 y 10" << endl;
                    }
                    cout << "\nDeseas agregar la fecha de hoy como fecha de salida? 1-Si 2-Agregar otra fecha: ";


                }
                else if(aux->id==num && aux->isAlquilado == true)
                {
                    cout << "\n\033[1;31mNOTA!\033[0m El traje se encuentra alquilado\n";
                }
                aux=aux->next;
            }
            // reverseStruct(aux);
            // lista=aux;
            delete(aux);
        }
        else
        {
            cout << "NOTA! Numero negativo o mayor de 4 digitos" << endl;
            cin.ignore();
            pressEnter();
            mostrarTitle();
        }
        cout << "\nAsignar/Buscar otro? 1-SI 2-NO: ";
        cin >> opc;  
    }while(opc!=2);
}