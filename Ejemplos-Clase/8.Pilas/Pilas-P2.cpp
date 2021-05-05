#include<iostream>
using namespace std;

struct  Nodo{
    int dato;
    Nodo *next;
};

void push(Nodo *&,int); //Prototipo de Funcion
void pop(Nodo *&,int &);
void show(Nodo *&);


int main(){
    Nodo *pila = NULL;
    int n,opc, otro, cont;

    do{
        // system("CLS");
        cout << "\033[2J\033[0;0H";
        otro=1;
        cout<<"Que desea hacer? 1- Agregar, 2- Mostrar, 3.- Quitar: "; cin>>opc;
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
            show(pila);
            break;
        case 3:
            if(pila == NULL){
                cout<<"Pila vacia";
            }
            else{
                pop(pila,n);
                show(pila);
            }
        break;
        default:
            cout<<"Opcion no valida!!";
        }
        cout<<"\nDeseas realizar otra operacion? 1-SI 2-NO: "; cin>>cont;
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


