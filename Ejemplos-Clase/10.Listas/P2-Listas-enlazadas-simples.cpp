#include<iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo *next;
};
void insInicio(Nodo *&, int);
void insFinal(Nodo *&,int);
void insMed(Nodo *&,int,int);
void eliminar(Nodo *&, int );
void mostrar(Nodo *&);
void buscar(Nodo *&,int);

int main(){
    int opc,x,again,pos;
    Nodo *lista = NULL;

    do{
        system("CLS");
        cout<<"1.- Insertar al Inicio"<<endl;
        cout<<"2.- Insertar al Final"<<endl;
        cout<<"3.- Insertar en una Posici�n (en medio)"<<endl;
        cout<<"4.- Mostrar"<<endl;
        cout<<"5.- Buscar Elemento"<<endl;
        cout<<"6.- Borrar Elemento"<<endl;
        cout<<"Seleciona la opci�n: "<<endl;
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
        case 3:
            cout<<"Valor a ingresar: "; cin>>x;
            cout<<"Posici�n donde se ingresar�: "; cin>>pos;
            insMed(lista,x,pos);
            mostrar(lista);
        break;
        case 4:
            mostrar(lista);
        break;
        case 5:
            cout<<"Valor a buscar: "; cin>>x;
            buscar(lista,x);
        break;
        case 6:
            cout<<"Valor a eliminar: "; cin>>x;
            eliminar(lista,x);
        break;
        }
        cout<<"\nDeseas otra operaci�n? 1-Si, 2-No: "; cin>>again;
    }while(again==1);


}

void eliminar(Nodo *&lista, int n){
    Nodo *busc = lista;
    Nodo *aux;

    if(lista!=NULL){
        while(busc!=NULL){
            if(busc->dato==n){
                if(busc==lista){
                    lista = lista->next;
                }
                else
                    aux->next = busc->next;
                delete(busc);
                return; //Finaliza la funci�n de inmediato.
            }
            aux = busc;
            busc = busc->next;
        }

    }
    else
        cout<<" Lista vacia..!";
}
void buscar(Nodo *&lista,int n){
    Nodo *busc = lista;
    int i = 1, band = 0;

    while(busc!=NULL){
        if(busc->dato==n){
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        busc = busc->next;
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;

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
void insMed(Nodo *&lista,int n,int pos){
    Nodo *aux,*nvo_nodo = new Nodo();
    nvo_nodo->dato = n;

    if(pos==1){
        nvo_nodo->next = lista;
        lista = nvo_nodo;
    }
    else{
        int lugar,x;
        cout<<"Insertas antes(1) o despues(2)?: "; cin>>x;
        if(x==1)
            lugar=-1;
        else
            lugar=0;

        aux = lista;

        for(int i=1; aux!=NULL; i++){
            if(i==pos+lugar){
                nvo_nodo->next = aux->next;
                aux->next = nvo_nodo;
                return;
            }
            aux = aux->next;
        }
    }
}
void mostrar(Nodo *&lista){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout<<actual->dato<<"->";
        actual=actual->next;
    }
}
