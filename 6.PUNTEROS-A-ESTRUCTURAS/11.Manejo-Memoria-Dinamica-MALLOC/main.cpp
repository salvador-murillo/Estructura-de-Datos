/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #11: Manejo Memoria Dinamica con MALLOC
*/
#include <iostream>
using namespace std;

struct fruta{
   char variedad; //1
   char nombre[15]; //15
   int can_ingresar; //4
   float precio_mayoreo;//4
   float precio_menudeo;//4
   double can_almacen;//8
};

void mostrarTitulo(){
   cout << "\033[2J\033[0;0H";
   cout << "\tPractica #11: Manejo Memoria Dinamica con MALLOC\n" << endl;
}

void capFruta(fruta *);
void mostrarFruta(fruta *);

int main() {
   mostrarTitulo();
   fruta *puntFruta1;
   cout << "Size of struct fruta:" << sizeof(fruta) << endl;
   puntFruta1 = (fruta*) malloc(sizeof(fruta));
   cout << "Size of puntFruta1:" << sizeof(*puntFruta1)<< endl;
   cout << "La direccion de puntFruta1 es:" << puntFruta1 << endl;
   capFruta(puntFruta1);
   mostrarFruta(puntFruta1);
   free(puntFruta1);

   //TEST para validar que se libero espacio en memoria
   // fruta *pfr1;
   // pfr1 = (fruta*) malloc(sizeof(fruta));
   // cout << "\nSize of pfr1:" << sizeof(*pfr1)<< endl;
   // cout << "La direccion de pfr1 es:" << pfr1 << endl;
   // free(pfr1);
}

void capFruta(fruta *puntFruta){
   cout << "\nIngresa los siguientes datos de la fruta:\n" << endl;
   cout << "VARIEDAD (1)(2)(3): "; cin >> puntFruta->variedad;
   cin.ignore();
   cout << "NOMBRE: "; cin.getline(puntFruta->nombre, 15, '\n');
   cout << "CANTIDAD: "; cin >> puntFruta->can_ingresar;
   cout << "PRECIO MAYOREO: "; cin >> puntFruta->precio_mayoreo;
   cout << "PRECIO MENUDEO: "; cin >> puntFruta->precio_menudeo;
   cout << "CANTIDAD ALMACEN: "; cin >> puntFruta->can_almacen;
}

void mostrarFruta(fruta *puntFruta){
   cout << "\nCaracteristicas de la fruta:" << endl;
   cout << "\nVARIEDAD: " << puntFruta->variedad;
   cout << "\nNOMBRE: " << puntFruta->nombre;
   cout << "\nCANTIDAD: " << puntFruta->can_ingresar;
   cout << "\nPRECIO MAYOREO: " << puntFruta->precio_mayoreo;
   cout << "\nPRECIO MENUDEO: " << puntFruta->precio_menudeo;
   cout << "\nCANTIDAD ALMACEN: " << puntFruta->can_almacen;
}