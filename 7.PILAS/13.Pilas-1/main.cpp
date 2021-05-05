/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #13: Pilas Ejercicio 1
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #13: Pilas Ejercicio #1\n" << endl;
}

void pressEnter(){
   cout << "\nPresione enter para continuar...";
   cin.ignore();
}

struct nodo{
   int num;
   nodo *nextNodo;
};

//Definir prototipo funciones Pilas
void push(nodo *&, int ); 
void pop(nodo *&, int &);
void erase(nodo *&);
void show(nodo *&);
void showA(nodo *&);
void show1(nodo *&);

int mostrarOpc(){
   int opc=0, salir=0;
   do{
      cout << "\033[2J\033[0;0H";
      mostrarTitulo();
      cout << "1.-Agregar datos a la pila" << endl;
      cout << "2.-Quitar UN elemento de la pila" << endl;
      cout << "3.-Vaciar la pila" << endl;
      cout << "4.-Mostrar la pila" << endl;
      cout << "5.-Mostrar el dato de la cima de la pila" << endl;
      cout << "6.-Salir" << endl;
      cout << "\nElige la operacion a realizar: ";
      cin>>opc;
      if(opc>=1 && opc<=6){
         return opc;
         salir=1;
      }else{
         cout << "\nOpcion no valida" << endl;
         cin.ignore();
         pressEnter();
      }
   }while (salir !=1); 
}

void selecOpc(nodo *&pila, int n){
   int num=0, addNum=1;
   switch (n)
   {
   case 1:
      do{
         mostrarTitulo();
         cout << "Numero a agregar: ";
         cin>>num;
         push(pila,num);
         cout << "\nAgregar otro numero 1-SI 2-NO: ";
         cin >> addNum;
      }while (addNum!=2);
      break;
   case 2:
      // cout << "DIRECCION PILA: " << pila << endl;
      if(pila == NULL){
         cout<<"\nPila vacia";
         pressEnter();
      }else{
         pop(pila,n);
      }
      break;
   case 3:
      if(pila == NULL){
         cout<<"\nPila vacia";
         pressEnter();
      }else{
         erase(pila);
      }
      break;
   case 4:
      if(pila == NULL){
         cout<<"\nPila vacia";
         pressEnter();
      }else{
         show(pila);
      }
      break;
   case 5:
      if(pila == NULL){
         cout<<"\nPila vacia";
         pressEnter();
      }else{
         show1(pila);
      }
      break;
   case 6:
      cout << "FIN DEL PROGRAMA" << endl;
      break;
   default:
      break;
   }
}

int main() {
   nodo *pila = NULL;
   int salir=1;
   do{
      int opc=0;
      opc = mostrarOpc();
      cin.ignore();
      opc==6 ? salir=2 : salir=1;
      selecOpc(pila,opc);
   }while(salir==1);
}

//Definir funciones Pilas
void push(nodo *&pila, int n){
   nodo *new_Nodo = new nodo();
   new_Nodo->num = n;
   new_Nodo->nextNodo = pila;
   pila = new_Nodo;
   cout << "\nAgregado " << n << " a la pila\n";
   showA(pila);
}

void pop(nodo *&pila, int &n){
   nodo *aux = pila;
   n=aux->num;
   pila = aux->nextNodo;
   delete aux;
   cout << "\nSe borro " << n << " de la pila";
   pressEnter();
}

void erase(nodo *&pila){
   nodo *aux = pila;
   pila = NULL;
   delete aux;
   cout << "\nSe borro la pila";
   pressEnter();
}

void show(nodo *&pila){
   nodo *aux = pila;
   cout << "\nPila actual:" << endl;
   while (aux != NULL){
      cout << aux->num << "->";
      aux = aux->nextNodo; 
   }
   cout<<"NULL";
   pressEnter();  
}

void showA(nodo *&pila){
   nodo *aux = pila;
   while (aux != NULL){
      cout << aux->num << "->";
      aux = aux->nextNodo; 
   }
   cout<<"NULL"<< endl; 
}

void show1(nodo *&pila){
   cout << "\nValor de la cima: " << pila->num;
   pressEnter();
}
