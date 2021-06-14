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
    Fecha fechaEntrega, fechaDevolucion; //NO - Default NULL
    char nombreCliente[30]; //NO - Sin Asignar
    char marca[30]; // SI - default  
    Smoking *prev, *next;
};

int countSuits(Smoking *);                //DONE  Contador trajes para showSuits
bool checkID(Smoking *, int );            //DONE  Valida ID para addSuit
bool checkSize(int );                     //DONE  Valida Size para dataSuit
void suitID(Smoking *&, Smoking *);       //DONE  Coloca datos para addSuit
void dataSuit(Smoking *&);                //DONE  Coloca datos para addSuit
void addSuit(Smoking *&);                 //DONE  1 Añade nuevo traje
void removeSuit(Smoking *&);              //DONE  2 Elimina traje por su ID
void checkData(Smoking *);                //DONE  - Revisa si existe smokings y si es posible editarlos
void editData(Smoking *, Smoking *&, int);//DONE  3 Modifica datos de un smoking  
void show1Suit(Smoking *);                //DONE  - Muestra un traje
void showSuits(Smoking *);                //DONE  4 Muestra todos los trajes hasta el momento
void searchBySize(Smoking *);             //DONE  5 Busqueda por tamaño
void searchByID(Smoking *);               //DONE  6 Busqueda por ID
void writeFile(Smoking *);                //TODO  7 Guardar registros en archivo Binario
void readFile(Smoking *);                 //TODO  8 Leer registros en archivo Binario
void assignSuit(Smoking *&);              //DONE  9 Asigna traje por ID
int checkMonth(Smoking *, int , int , int );
void receiveSuit(Smoking *&);             //TODO 10