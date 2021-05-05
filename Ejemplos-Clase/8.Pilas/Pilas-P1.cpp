#include<iostream>
using namespace std;

struct  Nodo{
    int dato;
    Nodo *next;
};

void push(Nodo *&,int); //Prototipo de Funcion
void show(Nodo *&);

int main(){
    Nodo *pila = NULL;
    int n1,opc;

    do{
        // system("CLS");
        cout << "\033[2J\033[0;0H";
        cout<<"Dame un numero: "; cin>>n1;
        push(pila,n1);
        show(pila);
        cout<<"\n\nQuieres otro 1-Si 2-No: ";  cin>>opc;

    }while(opc==1);

}

void push(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->next = pila;
    pila = nuevo_nodo;

    cout<<"\n Se agrego "<<n<<" a la pila"<<endl;
}

void show(Nodo *&pila){
    Nodo *aux = pila;
    while(aux != NULL){
        cout<<aux->dato<<"->";
        aux = aux->next;
    }
    cout<<"NULL";
}


