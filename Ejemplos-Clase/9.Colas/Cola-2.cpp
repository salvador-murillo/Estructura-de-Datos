#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
};

void insertarQ(Nodo *&, Nodo*&,int);
bool q_empty(Nodo *);
void show(Nodo *&);
void borrarQ(Nodo *&, Nodo*&, int &);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int opc,again=1,num;
    do{
        cout<<"1. Agregar a Cola\n2. Eliminar de Cola\n3. Mostrar Cola"<<endl;
        cout<<"Selecciona tu opci�n: "; cin>>opc;

        switch(opc){
        case 1:
            do{
                cout<<"Dame un num: "; cin>>num;
                insertarQ(frente,fin,num);
                cout<<"Agregar Otro? 1Si - 2No: "; cin>>again;
            }while(again==1);
            show(frente);
        break;
        case 2:
            do{
                borrarQ(frente,fin,num);
                show(frente);
                cout<<"\nBorrar Otro? 1Si - 2No: "; cin>>again;
            }while(again==1);
        break;
        }
        cout<<"\nOtra operacion? 1Si - 2No: "; cin>>again;
    }while(again==1);
}

void borrarQ(Nodo *&frente, Nodo*&fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;
    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente->next;
    }
    delete aux;
}
void insertarQ(Nodo *&frente,Nodo *&fin,int n){
    Nodo *nvo_nodo = new Nodo();
    nvo_nodo->dato = n;
    nvo_nodo->next = NULL;
    if(q_empty(frente))
        frente = nvo_nodo;
    else
        fin->next = nvo_nodo;
    fin = nvo_nodo;
    cout<<"Se anex� "<<n<<" a la cola"<<endl;
}
bool q_empty(Nodo *frente){
    //return (frente == NULL)? true : false;
    if(frente == NULL)
        return true;
    else
        return false;
}

void show(Nodo *&frente){

    Nodo *aux = frente;
    while(aux != NULL){
        cout<<aux->dato<<"<-";
        aux = aux->next;
    }
    cout<<"NULL";

}
