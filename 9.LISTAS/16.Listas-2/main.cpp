/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #16: Ejercicio Listas 2
*/
#include <iostream>
using namespace std;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #16: Listas Ejercicio #2\n" << endl;
}

void pressEnter(){
   cout << "\nPresione enter para continuar...";
   cin.ignore();
}

struct articulo{
   int codigo;
   char nombre[20];
   char categoria[20];
   float precio;
   int anio_fabri;
   articulo *nextList;
};

//Definir prototipo funciones Listas
void addItem(articulo *&);
void addFirst(articulo *&);
void addLast(articulo *&);
void addMid(articulo *&, int);
void showItems(articulo *);
void searchItem(articulo *, int);
void deleteItem(articulo *&, int);
int showPos(articulo *);

int mostrarOpc(){
    int opc=0, salir=0;
    do{
        mostrarTitulo();
        cout << "1.-Agregar articulo al inicio\n"
            << "2.-Agregar articulo al final\n"
            << "3.-Insertar un articulo en medio de la lista\n"
            << "4.-Consultar lista\n"
            << "5.-Buscar articulo por codigo\n"
            << "6.-Eliminar articulo por codigo\n"
            << "7.-Salir\n"
            << "\nElige la operacion a realizar: ";
        cin>>opc;
        if(opc>=1 && opc<=7){
            salir=1;
            return opc;
        }else{
            cout << "\nOpcion no valida" << endl;
            cin.ignore();
            pressEnter();
        }
   }while (salir !=1); 
}

void selecOpc(articulo *&lista, int n){
    int num=0;
    mostrarTitulo();
    switch (n)
    {
    case 1: 
        addFirst(lista);
        pressEnter(); 
        break;
    case 2:
        addLast(lista);
        pressEnter();
        break;
    case 3:
        n = showPos(lista);
        if(n == 1){
            cout << "Lista menor a 2 no puedes insertar enmedio" << endl;
            pressEnter();
        }else if(n >= 2){
            cout << "\nEscribe la posicion donde insertar: ";
            cin >> num;
            cin.ignore();
            if(num<=n){
                addMid(lista,num);
                pressEnter();
            }else{
                cout << "\nPosicion fuera de rango";
                pressEnter();
            }
        }
        break;
    case 4:
        if(lista == NULL){
            cout<<"Lista vacia\n";
            pressEnter();
        }else{
            showItems(lista);
            pressEnter();
        }
        break;
    case 5:
        if(lista == NULL){
            cout<<"Lista vacia\n";
            pressEnter();
        }else{
            cout << "\nEscribe el codigo del articulo a buscar: ";
            cin >> num;
            cin.ignore();
            searchItem(lista,num);
            pressEnter();
        }
        break;
    case 6:
        if(lista == NULL){
            cout<<"Lista vacia\n";
            pressEnter();
        }else{
            cout << "\nEscribe el codigo del articulo a eliminar: ";
            cin >> num;
            cin.ignore();
            deleteItem(lista,num);
            pressEnter();
        }
        break;
    case 7:
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
        opc==7 ? salir=2 : salir=1;
        selecOpc(lista,opc);
    }while(salir==1);
}

//Definir funciones listas
void addItem(articulo *&nvo_item){
    cout << "ARTICULO\nCodigo: ";
    cin >> nvo_item->codigo;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(nvo_item->nombre,20, '\n');
    cout << "Categoria: ";
    cin.getline(nvo_item->categoria,20, '\n');
    cout << "Precio: ";
    cin >> nvo_item->precio;
    cout << "Anio de Fabricacion: ";
    cin >> nvo_item->anio_fabri;
}

void addFirst(articulo *&lista){
    articulo *nvo_item = new articulo();
    addItem(nvo_item);
    nvo_item->nextList = lista;
    lista = nvo_item;
}

void addLast(articulo *&lista){
    articulo *aux,*nvo_item = new articulo();
    addItem(nvo_item);
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

void addMid(articulo *&lista,int pos){
    articulo *aux, *nvo_item = new articulo();
    addItem(nvo_item);
    if(pos==1){
        nvo_item->nextList = lista;
        lista = nvo_item;
    }
    else{
        int lugar,x;
        cout<<"Insertar antes(1) o despues(2)?: "; cin>>x;
        (x==1) ? lugar=-1 : lugar=0;
        aux = lista;
        for(int i=1; aux!=NULL; i++){
            if(i==pos+lugar){
                nvo_item->nextList = aux->nextList;
                aux->nextList = nvo_item;
                return;
            }
            aux = aux->nextList;
        }
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

void searchItem(articulo *lista, int n){
    int con = 1; 
    bool isItem = false;
    articulo *actual = new articulo();
    actual = lista;
    while(actual != NULL && isItem == false){
        if(actual->codigo == n){
            isItem = true;
            cout << "Codigo encontrado en posicion #"<< con << endl;
        }else{
            actual=actual->nextList;
            con++;
        }
    }
    if(isItem == false)
        cout << "Codigo NO existe" << endl;
}

void deleteItem(articulo *&lista, int n){
    int con = 1;
    articulo *busc = lista;
    articulo *aux;
    bool isItem = false;

    while(busc!=NULL){
        if(busc->codigo == n){
            (busc==lista)
                ? lista = lista->nextList
                : aux->nextList = busc->nextList;
            delete(busc);
            isItem = true;
            cout << "Codigo eliminado en posicion #"<< con << endl;
            return; 
        }
        aux = busc;
        busc = busc->nextList;
        con++;
    }
    if(isItem == false)
        cout << "Codigo NO existe" << endl;
}

int showPos(articulo *lista){
    int cont=0;
    articulo *actual = lista;
    if(actual == NULL){
        cout << "Lista Vacia" << endl;
        pressEnter();
        return cont;
    }else{
        while(actual != NULL){
            cont++;
            actual=actual->nextList;
        }
        if(cont>1)
            cout << "Lista del 1 al " << cont;
        return cont;
    }
}

