#include<iostream>
using namespace std;

struct  Nodo{
    int dato;
    Nodo *next;
};

void push(Nodo *&,int); //Prototipo de Funci�n
void pop(Nodo *&,int &);
void show(Nodo *&);


int main(){
    Nodo *pila = NULL;
    int n,opc, otro, cont;

    do{
        system("CLS");
        otro=1;
        cout<<"Que desea hacer? 1- Agregar, 2- Quitar todos, 3.- Quitar uno: "; cin>>opc;
        switch(opc){
        case 1:
            do{
                cout<<"Dame un numero: "; cin>>n;
                push(pila,n);
                cout<<"Deseas agregar otro numero a la pila? 1-SI 2-NO: "; cin>>otro;
            }while(otro==1);
            show(pila);
        break;

        case 2:

            cout<<"Sacando elementos de la pila: "<<endl;
            while(pila != NULL){  //Mientras no hayamos llegado al final de la pila
                pop(pila,n);
                if(pila != NULL){
                    cout<<n<<" , ";
                }
                else{
                    cout<<n<<".";
                }
            }

        break;



        case 3:
            if(pila == NULL){
                cout<<"Pila vac�a";
            }
            else{
                pop(pila,n);
                show(pila);
            }
        break;



        }
        cout<<"\nDeseas realizar otra operaci�n? 1-SI 2-NO: "; cin>>cont;
    }while(cont==1);
}

void push(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->next = pila;
    pila = nuevo_nodo;
    cout<<"\nSe agrego "<<n<<" a la pila"<<endl;
}
void pop(Nodo *&pila,int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->next;
    delete aux;
    //cout<<"\nSe borro "<<n<<" de la pila"<<endl;
}
void show(Nodo *&pila){
    Nodo *aux = pila;
    while(aux != NULL){
        cout<<aux->dato<<"->";
        aux = aux->next;
    }
    cout<<"NULL";

}


