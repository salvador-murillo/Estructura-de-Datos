#include<iostream>
using namespace std;

void saludo(){ //Esta función solo ejecuta código, no regresa nada
    cout<<"hola mundo"<<endl;
}
int suma(int f,int xy){ //Funcion que regresa valor entero, c/ parámetros
    int r; //Variable local a suma()
    r=f+xy;
    return(r);
}
void sum(int x, int y){ //Función solo ejecuta código, c/ parametros
    cout<<"La suma es: "<<x+y;
}
main(){

    saludo();
    cout<<"El valro de la función es: "<<suma(5,15)+80<<endl;
    sum(7,3);


}





