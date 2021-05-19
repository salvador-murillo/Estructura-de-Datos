/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #15: Ejercicio Listas 1
*/
#include <iostream>
#include <string>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #15: Listas Ejercicio #1\n" << endl;
}

void pressEnter(){
   cout << "\nPresione enter para continuar...";
   cin.ignore();
}

struct articulo{
   int codigo;
   string nombre;
   string categoria;
   float precio;
   int anio_fabri;
   articulo *nextList;
};

//Definir prototipo funciones Listas
void addFirst(articulo *&);
void addLast(articulo *&);
void showItems(articulo *);

int mostrarOpc(){
   int opc=0, salir=0;
   do{
      cout << "\033[2J\033[0;0H";
      mostrarTitulo();
      cout << "1.-Agregar articulo al inicio de la lista\n"
           << "2.-Agregar artuculo al final de la lista\n"
           << "3.-Consultar lista\n"
           << "4.-Salir\n"
           << "\nElige la operacion a realizar: ";
      cin>>opc;
      if(opc>=1 && opc<=4){
         return opc;
         salir=1;
      }else{
         cout << "\nOpcion no valida" << endl;
         cin.ignore();
         pressEnter();
      }
   }while (salir !=1); 
}

void selecOpc(articulo *&lista, int n){
   switch (n)
   {
   case 1: 
      mostrarTitulo();
      addFirst(lista);
      pressEnter(); 
      break;
   case 2:
      if(lista == NULL){
         cout<<"\nLista vacia";
         pressEnter();
      }else{
         mostrarTitulo();
         addLast(lista);
         pressEnter();
      }
      break;
   case 3:
      if(lista == NULL){
         cout<<"\nLista vacia";
         pressEnter();
      }else{
         showItems(lista);
         pressEnter();
      }
      break;
   case 4:
      cout << "FIN DEL PROGRAMA" << endl;
      break;
   default:
      break;
   }
}

int main() {
   articulo *lista = NULL;
   int salir=1;
   do{
      int opc=0;
      opc = mostrarOpc();
      cin.ignore();
      opc==4 ? salir=2 : salir=1;
      selecOpc(lista,opc);
   }while(salir==1);
}

void addFirst(articulo *&lista){
    articulo *nvo_item = new articulo();
    cout << "ARTICULO:\n";
    cout << "Codigo: ";
    cin >> nvo_item->codigo;
    cout << "Nombre: ";
    cin >> nvo_item->nombre;
    cout << "Categoria: ";
    cin >> nvo_item->categoria;
    cout << "Precio: ";
    cin >> nvo_item->precio;
    cout << "Anio de Fabricacion: ";
    cin >> nvo_item->anio_fabri;
    nvo_item->nextList = lista;
    lista = nvo_item;
}
void addLast(articulo *&lista){
    articulo *aux,*nvo_item = new articulo();
    cout << "ARTICULO:\n";
    cout << "Codigo: ";
    cin >> nvo_item->codigo;
    cout << "Nombre: ";
    cin >> nvo_item->nombre;
    cout << "Categoria: ";
    cin >> nvo_item->categoria;
    cout << "Precio: ";
    cin >> nvo_item->precio;
    cout << "Anio de Fabricacion: ";
    cin >> nvo_item->anio_fabri;
    if(lista==NULL){
        lista = nvo_item;
    }
    else{
        aux = lista;
        while(aux->nextList != NULL){
            aux = aux->nextList;
        }
        aux->nextList = nvo_item;
    }
}
void showItems(articulo *lista){
   int cont=1;
   articulo *actual = new articulo();
   actual = lista;
   while(actual != NULL){
      cout << "\nArticulo #" << cont << endl;
      cout << "Codigo: " << actual->codigo << endl;
      cout << "Nombre: " << actual->nombre << endl;
      cout << "Categoria: " << actual->categoria << endl;
      cout << "Precio: " << actual->precio << endl;
      cout << "Anio Fabricacion: " << actual->anio_fabri << endl;
      actual=actual->nextList;
      cont++;
   }
}