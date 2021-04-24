#include <iostream>
// #include <conio.h>
using namespace std;

struct art{

    char desc[30];
    int cod;
    float precio;

}prod, *puntProd = &prod, prod2;

/*
struct art prod, *puntProd = &prod;
*/

void capDatos();
void mostrar();

void capDatosPunt();
void mostrarPunt(art *);
void mostrarDir(art *);

int main(){
    setlocale(LC_ALL, "spanish");

    /*cout<<"Forma normal de captura:"<<endl;

    capDatos();
    mostrar();
    */
    cout<<"Tama�o de la estructura: "<<sizeof(art)<<endl;
    cout<<"============================="<<endl;
    cout<<"Ahora con punteros: "<<endl;

    capDatosPunt();
    mostrarPunt(puntProd);
    cout<<"\nDirecciones\n";
    mostrarDir(puntProd);

    cout<<"Tama�o cod: "<<sizeof(puntProd->cod)<<endl;
    cout<<"Tama�o descripci�n: "<<sizeof(puntProd->desc)<<endl;
    cout<<"Tama�o Precio: "<<sizeof(puntProd->precio)<<endl;

    cout<<endl;
}

void capDatosPunt(){
    cout<<"Dame el c�digo: ";  cin>>puntProd->cod;
    fflush(stdin);
    cout<<"Nombre de prod: ";  cin.getline(puntProd->desc,30,'\n');
    cout<<"Precio: $"; cin>>puntProd->precio;

}
void mostrarPunt(art *puntProducto){
    cout<<"C�digo - "<<puntProducto->cod<<" - Nombre del art�culo: "<<puntProducto->desc<<" - Precio: $"<<puntProducto->precio<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"C�digo - "<<(*puntProducto).cod<<" - Nombre del art�culo: "<<(*puntProducto).desc<<" - Precio: $"<<(*puntProducto).precio<<endl;
}
void mostrarDir(art *puntProducto){
    cout<<"C�digo - "<<&puntProducto->cod<<" - Nombre del art�culo: "<<&puntProducto->desc<<" - Precio: $"<<&puntProducto->precio<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"C�digo - "<<&(*puntProducto).cod<<" - Nombre del art�culo: "<<&(*puntProducto).desc<<" - Precio: $"<<&(*puntProducto).precio<<endl;
}


void capDatos(){
    cout<<"Dame el c�digo: ";  cin>>prod2.cod;
    fflush(stdin);
    cout<<"Nombre de prod: ";  cin.getline(prod2.desc,30,'\n');
    cout<<"Precio: $"; cin>>prod2.precio;

}
void mostrar(){
    cout<<"C�digo - "<<prod2.cod<<"\nNombre del art�culo: "<<prod2.desc<<" - Precio: $"<<prod2.precio<<endl;
}








