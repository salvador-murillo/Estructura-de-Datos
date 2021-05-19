/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #14: Ejercicio Colas 1
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #14: Colas Ejercicio #1\n" << endl;
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
void queue(nodo *&, nodo *&, int);
void showQueue(nodo *&);
void deleteQueue(nodo *&, nodo*&, int &);
void deleteALL(nodo *&, nodo*&);
void showFrenteFin(nodo *&, nodo *&);

int mostrarOpc(){
   int opc=0, salir=0;
   do{
      cout << "\033[2J\033[0;0H";
      mostrarTitulo();
      cout << "1.-Agregar datos a la cola\n"
           << "2.-Quitar UN elemento de la cola\n"
           << "3.-Vaciar la cola\n"
           << "4.-Mostrar la cola\n"
           << "5.-Mostrar el dato del frente y del final de la cola\n"
           << "6.-Salir\n"
           << "\nElige la operacion a realizar: ";
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

void selecOpc(nodo *&frente, nodo *&fin, int n){
   int num=0, addNum=1;
   switch (n)
   {
   case 1:
      do{
         mostrarTitulo();
         cout << "Numero a agregar: ";
         cin>>num;
         queue(frente,fin,num);
         cout << "\nAgregar otro numero 1-SI 2-NO: ";
         cin >> addNum;
      }while (addNum!=2);
      break;
   case 2:
      if(frente == NULL){
         cout<<"\nCola vacia";
         pressEnter();
      }else{
         deleteQueue(frente,fin,n);
         pressEnter();
      }
      break;
   case 3:
      if(frente == NULL){
         cout<<"\nCola vacia";
         pressEnter();
      }else{
         deleteALL(frente,fin);
         pressEnter();
      }
      break;
   case 4:
      if(frente == NULL){
         cout<<"\nCola vacia";
         pressEnter();
      }else{
         showQueue(frente);
         pressEnter();
      }
      break;
   case 5:
      if(frente == NULL){
         cout<<"\nCola vacia";
         pressEnter();
      }else{
         showFrenteFin(frente,fin);
         pressEnter();
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
   nodo *frente = NULL;
   nodo *fin = NULL;
   int salir=1;
   do{
      int opc=0;
      opc = mostrarOpc();
      cin.ignore();
      opc==6 ? salir=2 : salir=1;
      selecOpc(frente,fin,opc);
   }while(salir==1);
}

//Definir funciones Pilas
void queue(nodo *&frente, nodo *&fin,int n){
   nodo *nvo_nodo = new nodo();
   nvo_nodo->num = n;
   nvo_nodo->nextNodo = NULL;
   (frente == NULL) ? frente = nvo_nodo : fin->nextNodo = nvo_nodo;
   fin = nvo_nodo;
   cout<<"Se anexa "<<n<<" a la cola"<<endl;
}

void deleteQueue(nodo *&frente, nodo*&fin, int &n){
   n = frente->num;
   cout << "Se elimina " << n << " de la cola";
   nodo *aux = frente;
   if(frente == fin){
      frente = NULL;
      fin = NULL;
   }else{
      frente = frente->nextNodo;
   }
   delete aux;
}

void deleteALL(nodo *&frente, nodo*&fin){
   while (frente != NULL){
      nodo *aux = frente;
      frente = frente->nextNodo;
      delete aux;
   }
   cout << "Se elimino la cola";
   frente = NULL;
   fin = NULL;
}

void showQueue(nodo *&frente){
   nodo *aux = frente;
    while(aux != NULL){
        cout << aux->num<<"<-";
        aux = aux->nextNodo;
    }
    cout<<"NULL";
}

void showFrenteFin(nodo *&frente, nodo *&fin){
   cout << "PRIMER VALOR: " << frente->num << endl;
   cout << "ULTIMO VALOR: " << fin->num << endl;
}