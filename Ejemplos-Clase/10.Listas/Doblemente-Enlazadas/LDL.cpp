#include<iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo *next;
    Nodo *prev;
};

void insInicio(Nodo *&,int);
void insFin(Nodo *&,int);
void mostrar(Nodo *);
void borrarPos(Nodo *&,int);


int main(){
    int opc,x;
    Nodo *lista = NULL;

    do{

        cout<<"Selecciona la opcion"<<endl;
        cout<<"1.- Agregar al inicio"<<endl;
        cout<<"2.- Agregar al final"<<endl;
        cout<<"3.- Borrar"<<endl;
        cout<<"4.- Mostrar"<<endl;
        cin>>opc;

        switch(opc){
        case 1:
            cout<<"Dame el valor a insertar al inicio: "; cin>>x;
            insInicio(lista,x);
            mostrar(lista);
        break;
        case 2:
            cout<<"Dame el valor a insertar al final: "; cin>>x;
            insFin(lista,x);
            mostrar(lista);
        break;
        case 3:
            cout<<"Dame la posici�n a borrar: "; cin>>x;
            borrarPos(lista,x);
            mostrar(lista);
        break;
        case 4:
            mostrar(lista);
        break;


        }
        cout<<"\n\nQuieres otra operaci�n 1.Si 2.NO: "; cin>>opc;
    }while(opc==1);


}

void insInicio(Nodo *&lista, int n){
    Nodo *nvo_nodo = new Nodo();
    nvo_nodo->dato = n;

    nvo_nodo->next = lista;
    nvo_nodo->prev = NULL;

    if(lista != NULL)
        lista->prev = nvo_nodo;

    lista = nvo_nodo;
}
void insFin(Nodo *&lista,int n){
    Nodo *nvo_nodo = new Nodo(); //1. Crear nodo
    Nodo *ultimo = lista; //Se usa en el paso 5
    nvo_nodo->dato = n; //2. Ponemos dato(s)

    nvo_nodo->next = NULL; //3. Como es �ltimo nodo, next apunta a NULL

    if(lista == NULL){//4. Si la lista est� vac�a, el nvo_nodo es lista
        nvo_nodo->prev = NULL; //El campo previo apunta a NULL
        lista = nvo_nodo; //Lista ahora es Nvo_nodo, y por ende el sig apunta a NULL
        return; //Se sale de la funci�n
    }

    while(ultimo->next != NULL)//5. De otro modo, hay que recorrer la lista
        ultimo = ultimo->next; //Ultimo, ahora es lo que ten�a ultimo en su campo siguiente

    ultimo->next = nvo_nodo;  //6. Cuando ya llegamos al final, insertamos el nvo nodo en SIGUIENTE
    nvo_nodo->prev = ultimo;  //7. Y el nvo nodo, en PREVIO apunta a donde est� �ltimo.
}
void mostrar(Nodo *lista){
    Nodo *last;
    cout<<"Mostrando hacia adelante: ";
    while(lista != NULL){
        cout<<lista->dato<<" ";
        last = lista;
        lista = lista->next;
    }
    cout<<endl;
    cout<<"Mostrando hacia atras: ";
    while(last != NULL){
        cout<<last->dato<<" ";
        last = last->prev;
    }
}
void borrarPos(Nodo *&lista,int n){
    if(lista == NULL || n<=0){//Si la lista est� vacia o la posici�n es inv�lida
        cout<<"Lista vac�a o posici�n no v�lida"<<endl;
        return; //Finaliza funci�n
    }

    Nodo *actual = lista;
    for(int i=1; actual!=NULL && i<n ;i++)//Moverse desde 1 hasta la posici�n dada
        actual = actual->next; //Se mueve a la siguiete posicion

    if(actual == NULL){ //Si la posicion fue m�s alta que el tama�o de la lista
        cout<<"Posici�n fuera de rango"<<endl;
        return; //Finaliza
    }

    if(lista == actual)
        lista = actual->next;

    if(actual->next != NULL)
        actual->next->prev = actual->prev;

    if(actual->prev != NULL)
        actual->prev->next = actual->next;

    delete(actual);

}








