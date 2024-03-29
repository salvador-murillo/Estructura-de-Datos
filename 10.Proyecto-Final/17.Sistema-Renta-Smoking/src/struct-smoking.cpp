#include <iostream>
#include <string.h>
#include <fstream>
#include "../headers/struct-smoking.hpp"
#include "../headers/intro.hpp"
#include "../headers/date-time.hpp"

using namespace std;

int countSuits(Smoking *lista)
{
    int count = 0;
    while (lista != nullptr)
    {
        count++;
        lista = lista->next;
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
        mostrarTitle();
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
                }
            }else
            {
                cout << "\n\033[1;31mNOTA!\033[0mNOTA! Numero negativo o mayor de 4 digitos" << endl;
                cin.ignore();
                pressEnter();
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
            }
        }
    }
}

void dataSuit(Smoking *&nvoSuit)
{
    int num = 0, precioT = 0;
    bool tallaValido = true, modeloValido = true, precioValido = true;

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
            nvoSuit->modelo = num;
            modeloValido = false;
        }else
            cout << "\nNumero NO valido" << endl;
    }
    while (precioValido==true)//PRECIO
    {
        cout << "\n\033[1;37mPRECIO \033[1;35mIngresa el costo por dia \033[0m$";
        cin >> precioT;
        if(precioT>0)
        {
            nvoSuit->precioDiario = precioT;
            precioValido=false;
        }else
            cout << "\nEl costo debe de ser positivo";
    }
    cin.ignore();
    cout << "\n\033[1;37mMARCA \033[1;35mIngresa marca de smoking: \033[0m";
    cin.getline(nvoSuit->marca, 30, '\n');

}

void addSuit(Smoking *&lista)
{
    int addOther = 1;
    
    while(addOther==1)
    {
        bool listNull = false;
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
            listNull = true;
        }
        //Recorre hasta la ultima posicion
        if(listNull==false){
            while(addLast->next != nullptr)
                addLast = addLast->next;

            addLast->next = nvoSuit;
            nvoSuit->prev = addLast;
        }

        //TODO Agregar funcion para ordenar por talla al momento de la insercion

        cout << "\nAgregar otro traje 1.SI 2.NO: ";
        cin >> addOther;
    }
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
                cout << "\n\033[1;31mNOTA! \033[0mNumero negativo o mayor de 4 digitos";
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
                cout << "\n\033[1;34mNOTA!\033[1;37m Traje en tienda\033[0m";
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
                cout << "\nSe ha borrado el traje del sistema";
            }
            else{
                //Condicion si esta alquilado NO se puede dar de baja
                cout << "\n\033[1;31mNOTA!\033[1;37m Traje alquilado\033[0m";
                cout << "\nNo se puede borrar hasta que se entregue";
            }
        }
        else if(numValid == true && lista !=nullptr)
            cout << "\n\033[1;31mNOTA!\033[0m El ID no existe";
        
        cout << "\n\nBuscar/Borrar otro? 1-SI 2-NO: ";
        cin >> opc;
        (opc==1) ? numValid = false : searchAgain = true;
        pressEnter();
    }
}

void checkData(Smoking *lista)
{
    int getID = 0, edit = 1;
    int opc = 1, opcData = 0;
    bool idValid = false, numValid = false, searchAgain = false;
    Smoking *actual = new Smoking();
     
    //Lista Vacia
    if(lista == nullptr)
    {
        mostrarTitle();
        cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
        cout<<"\n\033[1;31mNOTA!\033[0m No hay smokings disponibles para modificar" << endl;
        pressEnter();
        return;
    }
    else
    {
        while(searchAgain == false)
        {
            edit=1;
            //Validar que existe el ID
            while(numValid == false && lista !=nullptr)
            {
                mostrarTitle();
                cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
                actual = lista;
                idValid = false;
                cout << "\nIngresa el ID del Smoking a modificar: ";
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
                    cout << "\n\033[1;31mNOTA!\033[0m Numero negativo o mayor de 4 digitos" << endl;
                    cout << "\nBuscar/Modificar otro traje? 1-SI 2-NO: ";
                    cin >> opc;
                    if(opc==1) cin.ignore(); else return;
                }
            }
            //Si el ID existe y es valido, comprobar que NO este alquilado
            if(numValid == true && idValid == true)
            {
                // cout << "\nEl ID si existe";
                if(actual->isAlquilado == true)
                {
                    cout << "\n\033[1;34mNOTA!\033[0m El smoking se encuentra alquilado" << endl;
                    cout << "\nDeseas modificar los datos? 1-SI 2-NO: ";
                    cin >> edit;
                }

                while(edit==1)
                {
                    cin.ignore();
                    opcData=menuDatabyID();
                    //Funcion Modificar Smoking
                    editData(actual, lista, opcData);
                    cout << "\nEditar otro dato del traje seleccionado? 1-SI 2-NO: ";
                    cin >> edit;
                }
            }
            else if(numValid == true && lista !=nullptr)
                cout << "\n\033[1;31mNOTA!\033[0m El ID no existe" << endl;
            cout << "\nBuscar/Modificar otro traje? 1-SI 2-NO: ";
            cin >> opc;
            (opc==1) ? numValid = false : searchAgain = true;
            pressEnter();
        }
    }
}

void editData(Smoking *actual, Smoking *&lista, int opc)
{
    int num = 0, prevID = actual->id, prevSize = actual->talla, prevModel = actual->modelo;
    int diaF = actual->fechaEntrega.day, mesF = actual->fechaEntrega.month, anioF = actual->fechaEntrega.year;
    bool repeatWhile = 0, precioValid = 0, diasValid = 0;
    Smoking *aux = lista;

    switch (opc)
    {
        case 1:
            //Ingresar ID nuevo y comparar
            while(repeatWhile==0){
                mostrarTitle();
                show1Suit(actual);
                cout << "\n\033[1;36mNUEVO ID: \033[0m";
                cin >> num;
                if(num>0 && num <10000){
                    repeatWhile=1;
                    if(checkID(aux,num)){
                        cout << "\n\033[1;34mNOTA!\033[0m ID en uso" << endl;
                        repeatWhile=0;
                        cin.ignore();
                        pressEnter();
                    }else{
                        while(aux!=nullptr){
                            if(aux->id==prevID){
                                aux->id=num;
                            }else{
                                aux=aux->next;
                            }
                        }
                        delete(aux);    
                    }
                }else{
                    cout << "\n\033[1;31mNOTA!\033[0m Numero negativo o mayor de 4 digitos" << endl;
                    repeatWhile=0;
                    cin.ignore();
                    pressEnter();
                }
            }
        break;
        case 2:
            //Ingresar talla nueva y comparar
            while(repeatWhile==0){
                mostrarTitle();
                show1Suit(actual);
                cout << "\n\033[1;36mNUEVA TALLA \033[1;35m1.Chica 2.Mediana 3.Grande\033[0m: ";
                cin >> num;
                if(checkSize(num)==true && num!=prevSize){
                    while(aux!=nullptr){
                        if(aux->id==prevID && repeatWhile==0){
                            aux->talla = num;
                            repeatWhile = 1;
                        }else{
                            aux=aux->next;
                        }
                    }
                    delete(aux); 
                }else{
                    repeatWhile = 0;
                    cout << "\nNumero NO valido/Misma Talla" << endl;
                    cin.ignore();
                    pressEnter();
                }
            }
        break;
        case 3:
            //Ingresar modelo nuevo y comparar
            while(repeatWhile==0){
                mostrarTitle();
                show1Suit(actual);
                cout << "\n\033[1;36mNUEVO MODELO \033[1;35m1.Slim 2.Skinny 3.Comfort\033[0m: ";
                cin >> num;
                if(checkSize(num)==true && num!=prevModel){
                    while(aux!=nullptr){
                        if(aux->id==prevID && repeatWhile==0){
                            aux->modelo = num;
                            repeatWhile = 1;
                        }else{
                            aux=aux->next;
                        }
                    }
                    delete(aux); 
                }else{
                    repeatWhile = 0;
                    cout << "\nNumero NO valido/Mismo Modelo" << endl;
                    cin.ignore();
                    pressEnter();
                }
            }
        break;
        case 4:
            //Ingresar marca nueva
            while(repeatWhile==0){
                mostrarTitle();
                show1Suit(actual);
                cin.ignore();
                cout << "\n\033[1;36mMARCA NUEVA:\033[0m ";
                while(aux!=nullptr){
                    if(aux->id==prevID && repeatWhile==0){
                        cin.getline(aux->marca, 30, '\n');
                        repeatWhile = 1;
                    }else{
                        aux=aux->next;
                    }
                }
                delete(aux); 
            }
        break;
        case 5:
            //Ingresar nombre
            mostrarTitle();
            cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
            if(actual->isAlquilado==true)
            {
                cout << "\n\033[1;34mNOTA!\033[0m El traje se encuentra reservado a nombre de:\n\033[1:37m";
                cout << actual->nombreCliente << "\n\n\033[0mDeseas renombrarlo? 1-SI 2-NO: ";
                cin >> num;
                num--;
            }
            else
            {
                cout << "\n\033[1;34mNOTA!\033[0m Este traje se encuentra disponible para renta\n(No es posible cambiar el nombre de cliente)" << endl;
                repeatWhile = 1;
                cin.ignore(); 
            }
            while(repeatWhile==0){
                if(num==0)
                {
                    mostrarTitle();
                    show1Suit(actual);
                    cin.ignore();
                    cout << "\n\033[1;36mNOMBRE:\033[0m ";
                    while(aux!=nullptr){
                        if(aux->id==prevID && repeatWhile==0){
                            cin.getline(aux->nombreCliente, 30, '\n');
                            repeatWhile = 1;
                        }else{
                            aux=aux->next;
                        }
                    }
                    delete(aux); 
                }
                else if(num==1)
                {
                    repeatWhile = 1;
                }
                else
                {
                    cout << "\n\033[1;31mNOTA!\033[0m Opcion no valida" << endl;
                    repeatWhile=0;
                    cin.ignore();
                    pressEnter();
                }
            }
        break;
        case 6:
            //Cambiar dias de prestamo 
            mostrarTitle();
            cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
            if(actual->isAlquilado==true)
            {
                cout << "\n\033[1;34mNOTA!\033[0m El traje se encuentra reservado por \033[1:37m" << actual->diasPrestamo << "\033[0m dias" << endl;
                cout << "\nDeseas cambiar los dias? 1-SI 2-NO: ";
                cin >> num;
                num--;
            }
            else
            {   
                cout << "\n\033[1;34mNOTA!\033[0m Este traje se encuentra disponible para renta\n(No es posible cambiar los dias de prestamo)" << endl;
                repeatWhile = 1;
                cin.ignore();
            }
            while(repeatWhile==0)
            {  
                if(num==0)
                {
                    while(diasValid==0)
                    {
                        mostrarTitle();
                        show1Suit(actual);
                        cout << "\n\033[1;36mDIAS (1 a 10):\033[0m ";
                        cin >> num;
                        if(num>=1 && num<=10){
                            while(aux!=nullptr){
                                if(aux->id==prevID && repeatWhile==0){
                                    aux->diasPrestamo=num;
                                    repeatWhile = 1;
                                    diasValid = 1;
                                }else{
                                    aux=aux->next;
                                }
                            }
                            delete(aux); 
                        }else{
                            cout << "\n\033[1;31mNOTA! \033[0mDias no validos, escoge entre 1 y 10" << endl;
                            cin.ignore();
                            pressEnter();
                        }
                    }
                }
                else if(num==1)
                {
                    repeatWhile = 1;
                }
                else
                {
                    cout << "\n\033[1;31mNOTA!\033[0m Opcion no valida" << endl;
                    repeatWhile=0;
                    cin.ignore();
                    pressEnter();
                }
            }
            if(diaF!=0){
                diaF+=num;
                returnDate(diaF, mesF, anioF);
                actual->fechaDevolucion.day = diaF;
                actual->fechaDevolucion.month = mesF;
                actual->fechaDevolucion.year = anioF;
                actual->totalPagar=actual->diasPrestamo*actual->precioDiario;
                actual->totalRestante=actual->totalPagar-actual->totalAbono;
            }
        break;
        case 7:
            //Cambiar precio por dia
            mostrarTitle();
            cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
            cout << "\n\033[1;34mNOTA!\033[0m El traje tiene un precio por dia de \033[1:37m$" << actual->precioDiario << "\033[0m" << endl;
            cout << "\nDeseas cambiar el precio? 1-SI 2-NO: ";
            cin >> num;
            num--;
            while(repeatWhile==0)
            {  
                if(num==0)
                {   
                    while(precioValid==0)
                    {
                        mostrarTitle();
                        show1Suit(actual);
                        cout << "\n\033[1;36mPRECIO DIARIO NUEVO:\033[0m $";
                        cin >> num;
                        if(num>0)
                        {
                            while(aux!=nullptr)
                            {
                                if(aux->id==prevID && repeatWhile==0)
                                {
                                    aux->precioDiario=num;
                                    repeatWhile = 1;
                                    precioValid = 1;
                                }
                                else
                                    aux=aux->next;
                            }
                            delete(aux); 
                        }
                        else
                        {
                            cout << "\n\033[1;31mNOTA! \033[0mEl precio tiene que ser positivo" << endl;
                            cin.ignore();
                            pressEnter();
                        }
                    }
                }
                else if(num==1)
                {
                    repeatWhile = 1;
                }
                else
                {
                    cout << "\n\033[1;31mNOTA!\033[0m Opcion no valida" << endl;
                    repeatWhile=0;
                    cin.ignore();
                    pressEnter();
                }
            }
            actual->totalPagar=actual->diasPrestamo*actual->precioDiario;
            actual->totalRestante=actual->totalPagar-actual->totalAbono;
        break;
        case 8:
            //Cambiar cantidad abonada
            mostrarTitle();
            cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
            if(actual->isAlquilado==true)
            {
                cout << "\n\033[1;34mNOTA!\033[0m El traje tiene una cantidad abonada de \033[1:37m$" << actual->totalAbono << "\033[0m" << endl;
                cout << "\nDeseas cambiar la cantidad? 1-SI 2-NO: ";
                cin >> num;
                num--;
            }
            else
            {
                cout << "\n\033[1;34mNOTA!\033[0m Este traje se encuentra disponible para renta\n(No es posible cambiar la cantidad abonada)" << endl;
                repeatWhile = 1;
                cin.ignore();
            }
            while(repeatWhile==0)
            {  
                if(num==0)
                {
                    while(precioValid==0)
                    {
                        mostrarTitle();
                        show1Suit(actual);
                        cout << "\n\033[1;36mCANTIDAD ABONAR NUEVA:\033[0m $";
                        cin >> num;
                        if(num>=0 && num<=actual->totalPagar)
                        {
                            while(aux!=nullptr)
                            {
                                if(aux->id==prevID && repeatWhile==0)
                                {
                                    aux->totalAbono=num;
                                    repeatWhile = 1;
                                    precioValid = 1;
                                }
                                else
                                    aux=aux->next;
                            }
                            delete(aux); 
                        }
                        else
                        {
                            cout << "\n\033[1;31mNOTA! \033[0mEl precio tiene que ser mayor o igual a $0 y menor a la cantidad a pagar ($" << actual->totalPagar << ")" << endl;
                            cin.ignore();
                            pressEnter();
                        }
                    }
                }
                else if(num==1)
                {
                    repeatWhile = 1;
                }
                else
                {
                    cout << "\n\033[1;31mNOTA!\033[0m Opcion no valida" << endl;
                    repeatWhile=0;
                    cin.ignore();
                    pressEnter();
                }
            }
            actual->totalRestante=actual->totalPagar-actual->totalAbono;
        break;
        case 9:
            //Cambiar fecha de entrega 
            mostrarTitle();
            cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n";
            if(actual->isAlquilado==true)
            {
                cout << "\n\033[1;34mNOTA!\033[0m El traje tiene fecha de entrega el \033[1:37m"
                     << diaF << "/" << mesF << "/" << anioF << "\033[0m" << endl;
                cout << "\nDeseas cambiar la fecha? 1-SI 2-NO: ";
                cin >> num;
                num--;
            }
            else
            {   
                cout << "\n\033[1;34mNOTA!\033[0m Este traje se encuentra disponible para renta\n(No es posible cambiar la fecha de entrega)" << endl;
                repeatWhile = 1;
                cin.ignore();
            }
            while(repeatWhile==0)
            {  
                if(num==0)
                {
                    mostrarTitle();
                    show1Suit(actual);
                    cout << "\n\033[1;36mFECHA ENTREGA:\033[0m ";
                    while(aux!=nullptr){
                        if(aux->id==prevID && repeatWhile==0){
                            //Entrega
                            validDate(diaF,mesF,anioF);
                            aux->fechaEntrega.day = diaF;
                            aux->fechaEntrega.month = mesF;
                            aux->fechaEntrega.year = anioF;

                            //Devolucion
                            diaF+= aux->diasPrestamo;
                            returnDate(diaF,mesF,anioF);
                            aux->fechaDevolucion.day = diaF;
                            aux->fechaDevolucion.month = mesF;
                            aux->fechaDevolucion.year = anioF;
                            repeatWhile = 1;
                        }else{
                            aux=aux->next;
                        }
                    }
                    delete(aux);
                }
                else if(num==1)
                {
                    repeatWhile = 1;
                }
                else
                {
                    cout << "\n\033[1;31mNOTA!\033[0m Opcion no valida" << endl;
                    repeatWhile=0;
                    cin.ignore();
                    pressEnter();
                }
            }
        break;
    }
}

void show1Suit(Smoking *lista)
{
    cout << "\n \t\033[7;33m***** DATOS DEL TRAJE *****\033[0m\n";
    cout << "\n\033[1;36mID:\033[0m " << lista->id;
    cout << "  \033[1;36mSTATUS:\033[0m "; (lista->isAlquilado==false) ? cout << "\033[1;33mDisponible": cout << "\033[1;31mAlquilado";
    cout << "\n\033[1;36m\nMARCA:\033[0m " << lista->marca;
    cout << "\n\033[1;36mTALLA:\033[0m ";
    (lista->talla==1) ? cout << "Chica": (lista->talla==2) ? cout << "Mediana": cout << "Grande";
    cout << " - \033[1;36mMODELO:\033[0m ";
    (lista->modelo==1) ? cout << "Slim": (lista->modelo==2) ? cout << "Skinny": cout << "Comfort";
    cout << "\n\033[1;36mPRECIO DIARIO  $\033[0m" << lista->precioDiario;
    cout << "\n\033[1;36m\nNOMBRE CLIENTE:\033[0m " << lista->nombreCliente;
    cout << "\n\033[1;36mFECHA ENTREGA\033[0m " << lista->fechaEntrega.day << "/" << lista->fechaEntrega.month << "/" << lista->fechaEntrega.year;
    cout << " - \033[1;36mDEVOLUCION (estimada)\033[0m " << lista->fechaDevolucion.day << "/" << lista->fechaDevolucion.month << "/" << lista->fechaDevolucion.year;
    cout << "\n\033[1;36m\nDIAS A PRESTAMO:\033[0m " << lista->diasPrestamo;
    cout << "\n\033[1;36mTOTAL A PAGAR  $\033[0m" << lista->totalPagar;
    cout << "\n\033[1;36mTOTAL ABONO    $\033[0m" << lista->totalAbono;
    cout << "\n\033[1;36mTOTAL RESTANTE $\033[0m" << lista->totalRestante << endl;
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
        cout << "\n\033[1;31mSmoking #"<< count;
        cout << "  \033[1;36mID:\033[0m " << lista->id;
        cout << "  \033[1;36mSTATUS:\033[0m "; (lista->isAlquilado==false) ? cout << "\033[1;33mDisponible": cout << "\033[1;31mAlquilado";
        cout << "\n\033[1;36m\nMARCA:\033[0m " << lista->marca;
        cout << "\n\033[1;36mTALLA:\033[0m ";
        (lista->talla==1) ? cout << "Chica": (lista->talla==2) ? cout << "Mediana": cout << "Grande";
        cout << " - \033[1;36mMODELO:\033[0m ";
        (lista->modelo==1) ? cout << "Slim": (lista->modelo==2) ? cout << "Skinny": cout << "Comfort";
        cout << "\n\033[1;36mPRECIO DIARIO  $\033[0m" << lista->precioDiario;
        cout << "\n\033[1;36m\nNOMBRE CLIENTE:\033[0m " << lista->nombreCliente;
        cout << "\n\033[1;36mFECHA ENTREGA\033[0m " << lista->fechaEntrega.day << "/" << lista->fechaEntrega.month << "/" << lista->fechaEntrega.year;
        cout << " - \033[1;36mDEVOLUCION (estimada)\033[0m " << lista->fechaDevolucion.day << "/" << lista->fechaDevolucion.month << "/" << lista->fechaDevolucion.year;
        cout << "\n\033[1;36m\nDIAS A PRESTAMO:\033[0m " << lista->diasPrestamo;
        cout << "\n\033[1;36mTOTAL A PAGAR  $\033[0m" << lista->totalPagar;
        cout << "\n\033[1;36mTOTAL ABONO    $\033[0m" << lista->totalAbono;
        cout << "\n\033[1;36mTOTAL RESTANTE $\033[0m" << lista->totalRestante << endl;
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

void searchBySize(Smoking *lista)
{
    int getSize = 0,  searchAgain = 1, sameSize = 0;
    bool sizeNotNull = true;
    Smoking *aux = lista;

    //Lista Vacia
    if(lista == nullptr)
    {
        mostrarTitle();
        cout << "\n\t\033[7;33m***** BUSQUEDA POR TALLA *****\033[0m\n";
        cout<<"\nNo hay smokings disponibles para mostrar" << endl;
        pressEnter();
        return;
    }
    else
    {
        while(searchAgain == 1)
        {
            mostrarTitle();
            cout << "\n\t\033[7;33m***** BUSQUEDA POR TALLA *****\033[0m\n";
            aux=lista;
            sizeNotNull = true;
            cout << "\n\033[1;36mTALLA A FILTRAR\033[1;35m\n1.Chica 2.Mediana 3.Grande\033[0m: ";
            cin >> getSize;
            if(checkSize(getSize)==true)
            {
                //Contar trajes iguales
                while(aux!=nullptr){
                    if(aux->talla==getSize)
                        sameSize++;
                    aux=aux->next;
                }
                delete(aux);
                aux=lista;
                while(aux!=nullptr)
                {
                    if(aux->talla==getSize){
                        cin.ignore();
                        mostrarTitle();
                        show1Suit(aux);
                        sameSize--;
                        sizeNotNull = false;
                        (sameSize>0)
                            ? cout << "\nPresione \033[1;34menter\033[0m para mostrar siguiente..."
                            : cout << "\n\033[1;31mNOTA!\033[0m No hay mas trajes de esta talla";
                    }
                    aux=aux->next;
                }
            }
            else
                cout << "\n\033[1;31mNOTA!\033[0m Numero NO valido";

            if(sizeNotNull)
                cout << "\n\033[1;31mNOTA!\033[0m No existen trajes de la talla seleccionada";
            cout << "\n\nBuscar/filtrar otra talla? 1-SI 2-NO:";
            cin >> searchAgain;
        }
    }
    
}

void searchByID(Smoking *lista)
{
    int getID = 0,  searchAgain = 1, idValid = 0;
    Smoking *aux = lista;
    
    //Lista Vacia
    if(lista == nullptr)
    {
        mostrarTitle();
        cout << "\n\t\033[7;33m***** BUSQUEDA POR ID *****\033[0m\n";
        cout << "\nNo hay smokings disponibles para mostrar" << endl;
        pressEnter();
        return;
    }
    else
    {
        while(searchAgain == 1)
        {
            mostrarTitle();
            cout << "\n\t\033[7;33m***** BUSQUEDA POR ID *****\033[0m\n";
            aux=lista;
            idValid=0;
            cout << "\nIngresa el ID a buscar: ";
            cin >> getID;
            if(getID>0 && getID<10000)
            {
                while(aux!=nullptr && idValid == 0)
                {
                    if(aux->id==getID)
                    {
                        cin.ignore();
                        mostrarTitle();
                        show1Suit(aux);
                        idValid=1;
                    }
                    else
                        aux=aux->next;
                } 
            }
            else
            {
                cout << "\n\033[1;31mNOTA!\033[0m Numero negativo o mayor de 4 digitos" << endl;
                idValid=1;
            }

            if(idValid==0){
                cout << "\n\033[1;31mNOTA!\033[0m Este ID no existe" << endl;
            }

            cout << "\nBuscar/Mostrar otro? 1-SI 2-NO:";
            cin >> searchAgain;
        }
    }
}

void readFile(Smoking *&lista, int opc)
{
    // //Revisar si existen elementos en archivo 'data.bin'
    // if(opc==0)
    // {
    //     ifstream in("data.bin", ios::binary); //Abre archivos.bin
    //     if(in.is_open()){
    //         in.read((char *) &lista, sizeof(Smoking));
    //         while(!in.eof() ) {
    //             in.read((char *) &lista, sizeof(Smoking));
    //         }
    //     }else{
    //         cout << "\n\033[31mError! \033[0m No existe el archivo 'data.bin'." << endl;
    //     }
    //     in.clear();
    //     in.close();
    // }

    // //Creacion de variable para leer datos
    // ifstream in("data.bin", ios::binary); //Abre archivos.bin
    // if(in.is_open()){
    //     in.read((char *) &p, sizeof(Smoking));
    //     while(!in.eof() ) {
    //         // mostrar(cout,&p);
    //         in.read((char *) &p, sizeof(Smoking));
    //     }
    // }else{
    //     cout << "\n\033[31mError! \033[0m No existe el archivo 'data.bin'." << endl;
    // }
    // in.clear();
    // in.close();

}

void writeFile(Smoking *lista)
{
    // int opcFile=0, countList = 0, countListFile = 0;
    // Smoking *aux = new Smoking();

    // mostrarTitle();
    // cout << "\n\t\033[1;36m***** GUARDAR REGISTROS *****\033[0m\n";

    // //Lista Vacia
    // if(lista == nullptr)
    //     cout << "\nNo existen datos/registros (en ejecucion) para guardar" << endl;
    
    // //Lista con elementos
    // if(lista != nullptr)
    // {
    //     //TODO Crear funciones para validar cambios en registro sistema vs bin, de acuerdo a ello implementar opciones
        
    //     countList= countSuits(lista); //Guarda #trajes en lista (en ejecución)


    //     cout << "\n\033[31mNOTA! \033[0m Existen registros nuevos\n\033[33m1.Sobreescribir archivo \n2.Agregar a archivo\n\033[0mSeleccione:";
    //     cin >> opcFile;
    //     if(opcFile==1){
    //         ofstream fileA("data.bin", ios::binary);
    //         if(fileA.is_open()){
    //             fileA.write((char *) &lista, sizeof(Smoking));
    //         }else{
    //             cout << "\n\033[31mERROR! \033[0m Error al crear archivo." << endl;
    //         }
    //         fileA.close();
    //     }
    //     else if (opcFile==2)
    //     {
    //         //Creacion de variable para guardar datos
    //         ofstream fileB("data.bin", ios::binary | ios::app);
    //         if(fileB.is_open()){
    //             fileB.write((char *) &lista, sizeof(Smoking));
    //         }else{
    //             cout << "\n\033[31mERROR! \033[0m Error al crear archivo." << endl;
    //         }
    //         fileB.close();
    //     }
    //     cout << "\nSe ha guardado el archivo.";
    // }
    // pressEnter();
}

void assignSuit(Smoking *&lista)
{
    int num = 0, opc = 0, diasP = 0;
    //Crear variable para obtener fecha y hora del sistema
    time_t now = time(0);
    //HACK Usar para REPL
    now = now - 18000;
    tm *ltm = localtime(&now);

    //Lista Vacia
    if(lista == nullptr)
    {
        mostrarTitle();
        cout << "\n\t\033[7;37m***** ASIGNACION DE TRAJE *****\033[0m\n";
        cout<<"\nNo hay smokings disponibles para alquilar" << endl;
        pressEnter();
        return;
    }

    do
    {
        int opcFecha = 0, diaFecha = 0, mesFecha = 0, anioFecha = 0;
        Smoking *aux = lista;
        bool diasValid = false, fechaValid = false, idValid = true, abonoValid = false;
        mostrarTitle();
        cout << "\n\t\033[7;37m***** ASIGNACION DE TRAJE *****\033[0m\n";
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
                    cout << "\nIngresa los siguientes datos:" << endl;
                    cout << "\n\033[1;37mNombre Cliente: \033[0m";
                    cin.getline(aux->nombreCliente, 30, '\n');
                    cout << "\033[1;37mDias a prestamo (1 a 10) -\033[0m";
                    cout << " [\033[1;32mPrecio Diario \033[1;31m$" << aux->precioDiario << "\033[0m]";
                    //Dias
                    while(diasValid==false)
                    {
                        cout << "\n\033[1;37mDIAS: \033[0m";
                        cin >> diasP;
                        if(diasP>=1 && diasP<=10){
                            aux->diasPrestamo=diasP;
                            diasValid=true;
                        }
                        else
                            cout << "\n\033[1;31mNOTA! \033[0mDias no validos, escoge entre 1 y 10" << endl;
                    }
                    //Fecha Entrega y Devolucion
                    while (fechaValid==false)
                    {
                        diaFecha = day(ltm);
                        mesFecha = month(ltm);
                        anioFecha = year(ltm);

                        cout << "\n\033[1;37mAgregar fecha de hoy como fecha de entrega?\033[0m\n1-Si 2-Agregar otra fecha: ";
                        cin >> opcFecha;
                        if(opcFecha==1)
                        {
                            //Entrega
                            aux->fechaEntrega.day = diaFecha;
                            aux->fechaEntrega.month = mesFecha;
                            aux->fechaEntrega.year = anioFecha;

                            //Devolucion
                            diaFecha+= diasP;
                            returnDate(diaFecha,mesFecha,anioFecha);
                            aux->fechaDevolucion.day = diaFecha;
                            aux->fechaDevolucion.month = mesFecha;
                            aux->fechaDevolucion.year = anioFecha;
                            fechaValid = true;
                        }
                        else if(opcFecha==2)
                        {
                            //Entrega
                            validDate(diaFecha, mesFecha, anioFecha);
                            aux->fechaEntrega.day = diaFecha;
                            aux->fechaEntrega.month = mesFecha;
                            aux->fechaEntrega.year = anioFecha;

                            //Devolucion
                            diaFecha+= diasP;
                            returnDate(diaFecha,mesFecha,anioFecha);
                            aux->fechaDevolucion.day = diaFecha;
                            aux->fechaDevolucion.month = mesFecha;
                            aux->fechaDevolucion.year = anioFecha;
                            fechaValid = true;
                        }
                        else
                            cout << "\nOpcion no valida\n";
                        
                    }
                    //Precios
                    aux->totalPagar = aux->precioDiario*aux->diasPrestamo;
                    cout << "\n\033[1;37mTOTAL A PAGAR \033[1;31m$" << aux->totalPagar;
                    //Abono
                    while(abonoValid==false)
                    {
                        cout << "\n\033[0mIngresa la cantidad a abonar $";
                        cin >> aux->totalAbono;
                        if(aux->totalAbono>=0 && aux->totalAbono<=aux->totalPagar){
                            abonoValid=true;
                            aux->totalRestante = aux->totalPagar - aux->totalAbono;
                        }
                        else
                            cout << "\n\033[1;31mNOTA!\033[0m El abono no puede ser menor a 0 o mayor del total\n";

                    }
                    idValid = false;
                }
                else if(aux->id==num && aux->isAlquilado == true)
                {
                    cout << "\n\033[1;31mNOTA!\033[0m El traje se encuentra alquilado\n";
                    idValid = false;
                }
                else if(aux->next==nullptr && aux->isAlquilado != true)
                {
                    if(idValid==true)
                        cout << "\n\033[1;31mNOTA!\033[0m No existe ningun smoking con este ID\n";
                }
                aux=aux->next;
            }
            delete(aux);
        }
        else
        {
            cout << "\n\033[1;31mNOTA!\033[0m Numero negativo o mayor de 4 digitos" << endl;
        }
        cout << "\n\033[1;37mAsignar/Buscar otro?\033[0m 1-SI 2-NO: ";
        cin >> opc;
    }while(opc!=2);
}

int checkMonth(Smoking *actual, int dia, int mes, int anio){
    int diasP=0;

    if(anio==actual->fechaEntrega.year){
        if(mes==actual->fechaEntrega.month){
            diasP = dia-actual->fechaEntrega.day;
        }else if(mes>actual->fechaEntrega.month){
            if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
            {
                diasP=31-actual->fechaEntrega.day+dia;
            }
            else if(mes==4 || mes==6 || mes==9 || mes==11)
            {
                diasP=30-actual->fechaEntrega.day+dia;
            }
            else if(mes==2)
            {
                diasP=28-actual->fechaEntrega.day+dia; 
            }
        }
    }
    return diasP;
}

void receiveSuit(Smoking *&lista)
{
    int getID = 0,  searchAgain = 1;
    float cantPagar = 0;
    bool idValid = false, suitInShop = false, suitFound = false, precioValid = false;
    Smoking *aux = lista;
    Smoking *actual = new Smoking();
    
    //Crear variable para obtener fecha y hora del sistema
    time_t now = time(0);
    //HACK Usar para REPL
    now = now - 18000;
    tm *ltm = localtime(&now);

    //Lista Vacia
    if(lista == nullptr)
    {
        mostrarTitle();
        cout << "\n\t\033[7;32m***** DEVOLUCION DE TRAJE *****\033[0m\n";
        cout << "\nNo existen trajes alquilados por el momento " << endl;
        pressEnter();
        return;
    }
    else
    {
        while(searchAgain == 1)
        {
            mostrarTitle();
            cout << "\n\t\033[7;32m***** DEVOLUCION DE TRAJE *****\033[0m\n";
            aux=lista;
            idValid = false;
            suitInShop = false;
            suitFound = false;
            cout << "\nIngresa el ID a buscar: ";
            cin >> getID;
            //Determinar si existe, ademas si esta alquilado o no
            if(getID>0 && getID<10000)
            {
                idValid=true;
                while(aux!=nullptr)
                {
                    if(aux->id==getID && aux->isAlquilado==true){
                        suitInShop = false;
                        suitFound = true;
                        actual = aux;
                    }else if(aux->id==getID && aux->isAlquilado==false){
                        suitInShop = true;
                        suitFound = true;
                    }
                    aux=aux->next;
                } 
            }
            
            int diaS = actual->fechaEntrega.day, mesS = actual->fechaEntrega.month, anioS = actual->fechaEntrega.year;
            int diaE = actual->fechaDevolucion.day, mesE = actual->fechaDevolucion.month, anioE = actual->fechaDevolucion.year;
            int dia = day(ltm), mes = month(ltm), anio = year(ltm), diaP = 0, opcDate = 0, cambio = 0;
            bool dateOK = false, diaPrestaOk = false, trajeEntregado=false;

            //Realizar operaciones de recepcion
            if(idValid==true && suitInShop == false && suitFound == true)
            {
                while(dateOK == false){
                    cin.ignore();
                    mostrarTitle();
                    show1Suit(actual);
                    cout << "\n\033[7;35mFECHA DE ENTREGA\033[0m";
                    cout << "\nRealizo la entrega hoy? 1-SI 2-NO:";
                    cin >> opcDate;
                    mostrarTitle();
                    cout << "\n\t\033[7;32m***** DEVOLUCION DE TRAJE *****\033[0m\n";
                    if(opcDate==1)
                    {
                        diaP = dia-diaS;
                        cout << "\n      Fecha Entrega \033[1;33m" << actual->fechaEntrega.day << "/" << actual->fechaEntrega.month << "/" << actual->fechaEntrega.year;
                        cout << "\n\033[0mDevolucion Estimada \033[1;33m" << actual->fechaDevolucion.day << "/" << actual->fechaDevolucion.month << "/" << actual->fechaDevolucion.year;
                        cout << "\n\033[0mDevolucion   Actual \033[1;34m" << dia << "/" << mes << "/" << anio << endl;
                        if((diaP>=1 && diaP<=10) && (anio==anioE) && (mes==mesE || mes==mesS))
                        {
                            dateOK=true;
                            if(diaP!=actual->diasPrestamo)
                                cout << "\n  \033[1;31mHa cambiado el pago total";

                            actual->diasPrestamo=diaP;
                            actual->totalPagar=actual->diasPrestamo*actual->precioDiario;
                            actual->totalRestante=actual->totalPagar-actual->totalAbono;
                            cout << "\n\033[7;33m**************RESUMEN DE PAGO\033[0m";
                            cout << "\n              Pago Total $"<< actual->totalPagar;
                            cout << "\n                Abonando $"<< actual->totalAbono;
                            cout << "\n                \033[1;33mRestante $"<< actual->totalRestante;
                            cout << "\n\033[7;33m*****************************";
                            while(precioValid==false)
                            {
                                cout << "\n\n\033[0mIngrese la cantidad a pagar $";
                                cin >> cantPagar;
                                if(cantPagar>=0)
                                {
                                    if(cantPagar>=actual->totalRestante)
                                    {
                                        cambio=cantPagar-actual->totalRestante;
                                        cout << "\nSu cambio es de $" << cambio;
                                        cin.ignore();
                                        pressEnter();
                                        trajeEntregado=true;
                                        precioValid=true;
                                    }else
                                    {
                                        cout << "\n\033[1;31mNOTA!\033[0m La cantidad a pagar es menor a la cantidad restante";
                                    }  
                                }
                                else
                                    cout << "\nLa cantidad debe de ser positiva";
                            }
                        }
                        else if(diaP==0)
                        {
                            cout << "\n\033[1;31mNOTA!\033[0m No puedes solicitar y entregar el traje el mismo dia" << endl;
                            dateOK=false;
                            pressEnter();
                        }
                        else
                        {
                            cout << "\n\033[1;31mNOTA!\033[0m El traje solo se presta por minimo 1 dia y maximo 10" << endl;
                            dateOK=false;
                            pressEnter();
                        }
                    }
                    else if(opcDate==2)
                    {
                        while(diaPrestaOk==false){
                            cout << "\nIngresa el dia: "; cin >> dia;
                            cout << "\nIngresa el mes: "; cin >> mes;
                            cout << "\nIngresa el anio: "; cin >> anio;
                            diaP = checkMonth(actual, dia, mes, anio);
                            if(diaP>=1 && diaP<=10){
                                diaPrestaOk=true;
                            }else{
                                cout << "\n\033[1;31mNOTA!\033[0m Fecha entrega no valida, no debe de exceder diez dias despues del " << actual->fechaEntrega.day << "/" << actual->fechaEntrega.month << "/" << actual->fechaEntrega.year << endl;
                            }
                        }
                        mostrarTitle();
                        cout << "\n\t\033[7;32m***** DEVOLUCION DE TRAJE *****\033[0m\n";
                        cout << "\n      Fecha Entrega \033[1;33m" << actual->fechaEntrega.day << "/" << actual->fechaEntrega.month << "/" << actual->fechaEntrega.year;
                        cout << "\n\033[0mDevolucion Estimada \033[1;33m" << actual->fechaDevolucion.day << "/" << actual->fechaDevolucion.month << "/" << actual->fechaDevolucion.year;
                        cout << "\n\033[0mDevolucion   Actual \033[1;34m" << dia << "/" << mes << "/" << anio << endl;

                        if((diaP>=1 && diaP<=10) && (anio==anioE) && (mes==mesE || mes==mesS))
                        {
                            dateOK=true;
                            if(diaP!=actual->diasPrestamo)
                                cout << "\n  \033[1;31mHa cambiado el pago total";

                            actual->diasPrestamo=diaP;
                            actual->totalPagar=actual->diasPrestamo*actual->precioDiario;
                            actual->totalRestante=actual->totalPagar-actual->totalAbono;
                            cout << "\n\033[7;33m**************RESUMEN DE PAGO\033[0m";
                            cout << "\n              Pago Total $"<< actual->totalPagar;
                            cout << "\n                Abonando $"<< actual->totalAbono;
                            cout << "\n                \033[1;33mRestante $"<< actual->totalRestante;
                            cout << "\n\033[7;33m*****************************";
                            while(precioValid==false )
                            {
                                cout << "\n\n\033[0mIngrese la cantidad a pagar $";
                                cin >> cantPagar;
                                if(cantPagar>=0)
                                {
                                    if(cantPagar>=actual->totalRestante)
                                    {
                                        cambio=cantPagar-actual->totalRestante;
                                        cout << "\nSu cambio es de $" << cambio;
                                        cin.ignore();
                                        pressEnter();
                                        trajeEntregado=true;
                                        precioValid=true;
                                    }
                                    else
                                    {
                                        cout << "\n\033[1;31mNOTA!\033[0m La cantidad a pagar es menor a la cantidad restante";
                                    }   
                                }
                                else
                                    cout << "\nLa cantidad debe de ser positiva";
                            }
                        }
                        else if(diaP==0)
                        {
                            cout << "\n\033[1;31mNOTA!\033[0m No puedes solicitar y entregar el traje el mismo dia" << endl;
                            dateOK=false;
                            pressEnter();
                        }
                        else
                        {
                            cout << "\n\033[1;31mNOTA!\033[0m El traje solo se presta por minimo 1 dia y maximo 10" << endl;
                            dateOK=false;
                            pressEnter();
                        }
                    }
                    else
                    {
                        cout << "\n\033[1;31mNOTA!\033[0m Opcion No valida" << endl;
                    }
                }

            }
            else if(idValid==true && suitInShop == true && suitFound == true)
            {
                cout << "\n\033[1;35mNOTA!\033[0m El Traje con este ID se encuentra en tienda" << endl;
            }
            else if(idValid==true && suitInShop == false && suitFound == false)
            {
                cout << "\n\033[1;31mNOTA!\033[0m Este ID no existe" << endl;
            }
            else
            {
                cout << "\n\033[1;31mNOTA!\033[0m Numero negativo o mayor de 4 digitos" << endl;
            }

            if(trajeEntregado==true)
            {
                actual->fechaEntrega.day = 0;
                actual->fechaEntrega.month = 0;
                actual->fechaEntrega.year = 0;
                actual->fechaDevolucion.day = 0;
                actual->fechaDevolucion.month = 0;
                actual->fechaDevolucion.year = 0;
                actual->diasPrestamo=0;
                actual->isAlquilado=false;
                actual->totalPagar = 0;
                actual->totalAbono = 0;
                actual->totalRestante = 0;
                strcpy(actual->nombreCliente, "Sin Asignar");
                
                mostrarTitle();
                show1Suit(actual);
                cout << "\n\033[1;35mNOTA!\033[0m Se ha entregado el traje, se encuentra listo para ser alquilado" << endl;
            }

            
            cout << "\nBuscar/Mostrar otro? 1-SI 2-NO: ";
            cin >> searchAgain;
        }
    }
}