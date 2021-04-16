#include<iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "spanish");
    char letra='F';
    char *lt;

    lt=&letra;

    cout<<"El valor de apuntador lt: "<<*lt<<endl;
    cout<<"Direccion de apuntador lt: "<<lt<<endl;
    cout<<"==============================================="<<endl;
    cout<<"Convertimos la direccion a un valor, no a texto"<<endl;
    cout<<"==============================================="<<endl<<endl;
    cout<<">>>Forma 1 - conversion por asignacion - (tipo de dato) expresion; -"<<endl<<endl;
    cout<<"En este caso usamos (void *)lt, es decir convertimos la direccion a"<<endl<<

    "NO texto, como puntero y en lugar de "<< lt <<" queda como: "<< (void *)lt <<endl;

    cout<<"\nEjemplo basico de conversion por asignacion"<<endl;
    cout<<"\tdouble x = 1.2;\n";
    cout<<"\tint suma = (int)x + 1; //Convertimos x a INT";
    cout<<"\n\tcout << ''Suma ='' << suma;"<<endl;
    cout<<"El codigo anterior nos daria como salida - Suma = 2"<<endl;

    cout<<"==========================="<<endl<<endl;
    cout<<">>>Forma 2 - conversi�n por operador CAST - static_cast<tipo de dato>(expresi�n); -"<<endl<<endl;
    cout<<"En este caso usamos static_cast<void*>(lt), es decir convertimos la direcci�n a"<<endl<<

    "NO texto, como puntero y en lugar de "<< lt <<" queda como: "<<  static_cast<void*>(lt)<<endl;

    cout<<"\nEjemplo b�sico de conversi�n por static cast"<<endl;
    cout<<"\tfloat f = 3.5;"<<endl;
    cout<<"\tint b = static_cast<int>(f);"<<endl;
    cout<<"\tcout << b;"<<endl;
    cout<<"El c�digo anterior nos dar�a como salida - 3"<<endl;

}
