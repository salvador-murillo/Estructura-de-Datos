#include<iostream>
using namespace std;

void saludo(){ //Esta funci�n solo ejecuta c�digo, no regresa nada
    cout<<"hola mundo"<<endl;
}
int suma(int f,int xy){ //Funcion que regresa valor entero, c/ par�metros
    int r; //Variable local a suma()
    r=f+xy;
    return(r);
}
void sum(int x, int y){ //Funci�n solo ejecuta c�digo, c/ parametros
    cout<<"La suma es: "<<x+y;
}
main(){

    saludo();
    cout<<"El valro de la funci�n es: "<<suma(5,15)+80<<endl;
    sum(7,3);


}





