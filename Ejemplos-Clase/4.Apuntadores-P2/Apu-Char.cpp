#include<iostream>
using namespace std;
main(){
    setlocale(LC_ALL, "spanish");
    char letra='F';
    char *lt;

    lt=&letra;

    cout<<"El valor de apuntador lt: "<<*lt<<endl;
    cout<<"Dirección de apuntador lt: "<<lt<<endl;
    cout<<"==============================================="<<endl;
    cout<<"Convertimos la dirección a un valor, no a texto"<<endl;
    cout<<"==============================================="<<endl<<endl;
    cout<<">>>Forma 1 - conversión por asignación - (tipo de dato) expresión; -"<<endl<<endl;
    cout<<"En este caso usamos (void *)lit, es decir convertimos la dirección a"<<endl<<"NO texto, como puntero y en lugar de "<<lt<<" queda como: "<<(void *)lt<<endl;
    cout<<"\nEjemplo básico de conversión por asignación"<<endl;
    cout<<"\tdouble x = 1.2;\n";
    cout<<"\tint suma = (int)x + 1; //Convertimos x a INT";
    cout<<"\n\tcout << ''Suma ='' << suma;"<<endl;
    cout<<"El código anterior nos daría como salida - Suma = 2"<<endl;

    cout<<"==========================="<<endl<<endl;
    cout<<">>>Forma 2 - conversión por operador CAST - static_cast<tipo de dato>(expresión); -"<<endl<<endl;
    cout<<"En este caso usamos static_cast<void>*(lt), es decir convertimos la dirección a"<<endl<<"NO texto, como puntero y en lugar de "<<lt<<" queda como: "<<static_cast<void*>(lt)<<endl;
    cout<<"\nEjemplo básico de conversión por static cast"<<endl;
    cout<<"\tfloat f = 3.5;"<<endl;
    cout<<"\tint b = static_cast<int>(f);"<<endl;
    cout<<"\tcout << b;"<<endl;
    cout<<"El código anterior nos daría como salida - 3"<<endl;

}
