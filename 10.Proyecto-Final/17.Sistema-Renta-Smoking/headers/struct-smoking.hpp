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
    Fecha fechaPrestamo, fechaEntrega; //NO - Default NULL
    char nombreCliente[25]; //NO - Sin Asignar 
    Smoking *prev, *next;
};

bool checkID(Smoking *, int );
bool checkTalla(int );
void trajeID(Smoking *&, Smoking *);
void newTraje(Smoking *&);
void altaTraje(Smoking *&);
void bajaTraje(Smoking *&);