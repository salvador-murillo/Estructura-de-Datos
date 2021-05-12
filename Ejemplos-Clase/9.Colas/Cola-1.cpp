#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
};
void insertarQ(Nodo *&, Nodo *&,int);
bool q_empty(Nodo *);
void show(Nodo *&);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    int x;
    cout<<"Dame un num: ";  cin>>x;
    insertarQ(frente,fin,x);

    cout<<"Dame un num: ";  cin>>x;
    insertarQ(frente,fin,x);

    cout<<"Dame un num: ";  cin>>x;
    insertarQ(frente,fin,x);

    show(frente);

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
    cout<<"NULL<-";
    Nodo *aux = frente;
    while(aux != NULL){
        cout<<aux->dato<<"<-";
        aux = aux->next;
    }

}
