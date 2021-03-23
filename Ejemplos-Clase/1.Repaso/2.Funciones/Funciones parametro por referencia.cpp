#include<iostream>
using namespace std;
// Paso de parametro por VALOR
/*
int funcion(int n, int m){//Se pasa el valor al parámetro
    n = n + 2;
    m = m - 5;
    return(n+m);
}
*/

//Paso de Parametro por REFERENCIA
/*
int funcion(int &n, int &m){//Se pasa la variable al parametro
    n = n + 2;
    m = m - 5;
    return(n+m);
}
*/
main(){
    int a=10,b=20;
    cout<<"a,b ->"<<a<<", "<<b<<endl;
    cout<<"funcion(a,b) ->"<<funcion(a,b)<<endl;
    cout<<"a,b ->"<<a<<", "<<b<<endl;
    //cout<<"funcion(10,20) ->"<<funcion(10,20)<<endl;
}

