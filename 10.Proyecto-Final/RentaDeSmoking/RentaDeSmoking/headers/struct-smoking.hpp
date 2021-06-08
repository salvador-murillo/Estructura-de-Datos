#pragma once

struct Fecha{
    int day, month, year;
};

struct Smoking{
    bool isAlquilado; //SI - default false
    int id; // SI - Obligatorio y revisar que no exista otro igual
    int talla; //SI - Seleccion entre S, M, L
    int modelo; //Mostrar tipos de cortes y ajustar de acuerdo a seleccion
    int diasPrestamo; //NO - 0 Maximo 10, entre 1 y 9
    float precioDiario; //SI - Definir precio por dia
    float totalPagar; //NO - 0, condicion < preciodiario * diasPrestamo
    float totalAbono; //NO - 0, condicion > 0
    float totalRestante; //NO - 0, condicion > 0
    Fecha fechaPrestamo, fechaEntrega; //NO - Default NULL
    char nombreCliente[25]; //NO - Sin Asignar
    char marca[25]; // SI - default
    Smoking *prev, *next;
};

int countSuits(Smoking *);          //DONE Contador trajes para showSuits
bool checkID(Smoking *, int );      //DONE Valida ID para addSuit
bool checkSize(int );               //DONE Valida Size para
void suitID(Smoking *&, Smoking *); //DONE Coloca datos para addSuit
void dataSuit(Smoking *&);          //DONE Coloca datos para addSuit
void addSuit(Smoking *&);           //1 OK
void removeSuit(Smoking *&);        //2 OK
      
void showSuits(Smoking *);          //4 OK
void searchBySize(Smoking *, Smoking *&);       //5 //FIXME Error en creacion de lista personalizada
// void searchByID(Smoking *);         //6 //TODO
// void writeFile(Smoking *);          //7 //TODO
// void readFile(Smoking *);           //8 //TODO
void assignSuit(Smoking *&);        //9 //TODO
// void receiveSuit(Smoking *&);       //10//TODO
