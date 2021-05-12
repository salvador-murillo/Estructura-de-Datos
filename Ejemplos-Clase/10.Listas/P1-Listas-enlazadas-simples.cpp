#include<iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo *next;
};
void insInicio(Nodo *&, int);
void insFinal(Nodo *&,int);
void mostrar(Nodo *);

main(){
    int opc,x,again;
    Nodo *lista = NULL;

    do{
        system("CLS");
        cout<<"1.- Insertar al Inicio"<<endl;
        cout<<"2.- Insertar al Final"<<endl;
        cout<<"3.- Insertar al en una Posición (en medio)"<<endl;
        cout<<"4.- Mostrar"<<endl;
        cout<<"Seleciona la opción: "<<endl;
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"Valor a ingresar al inicio: "; cin>>x;
            insInicio(lista,x);
            mostrar(lista);
        break;
        case 2:
            cout<<"Valor a ingresar al final: "; cin>>x;
            insFinal(lista,x);
            mostrar(lista);
        break;
        case 4:
            mostrar(lista);
        break;
        }
        cout<<"\nDeseas otra operación? 1-Si, 2-No: "; cin>>again;
    }while(again==1);


}

void insInicio(Nodo *&lista,int n){
    Nodo *nvo_nodo = new Nodo();
    nvo_nodo->dato = n;
    nvo_nodo->next = lista;
    lista = nvo_nodo;
}
void insFinal(Nodo *&lista,int n){
    Nodo *aux,*nvo_nodo = new Nodo();
    nvo_nodo->dato = n;
    if(lista==NULL){
        lista = nvo_nodo;
    }
    else{
        aux = lista;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nvo_nodo;
    }
}
void mostrar(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout<<actual->dato<<"->";
        actual=actual->next;
    }
}
