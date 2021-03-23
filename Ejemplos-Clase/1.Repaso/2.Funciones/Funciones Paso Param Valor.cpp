#include<iostream>
using namespace std;

int sumar(int paco, int juan){//Función con paso de parámetros por valor
    int r;
    r=paco+juan;
    return(r);//Regresa la variable "r" como valor ENTERO
}

void resta(int a, int b){ //Funcion con paso de parámetros por valor
    cout<<"La resta es: "<<a-b<<endl; //NO REGRESA ningun valor (VOID)
}
/*int mult(){//Funcion sin paso de parámetros
    int a=10,b=8;//Variables locales a "mult"
    return(a*b);//Regresa una expresión.
}*/


main(){
    int a,b;
    resta(50,6);
    cout<<"Dame A: "; cin>>a;
    cout<<"Dame B: "; cin>>b;
    cout<<"La funcion sumar de a+b es: "<<sumar(a,b)<<endl;
    cout<<"La funcion sumar compleja es: "<<sumar(a+10,sumar(10,20))<<endl;
    cout<<"La funcion sumar de 5+10 es: "<<sumar(5,10)<<endl;
    resta(50,6);
}

