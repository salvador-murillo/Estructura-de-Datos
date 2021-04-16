/*
Youtube: mycodeschool Pointers in c/c++
Link: http://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_
*/
#include <iostream>
using namespace std;

int main() {
    cout << "\033[2J\033[0;0H";
    
    int a[]={2,4,6,8,10};
    int* p;
    p=a;
    
    cout << "\n-----PARTE 1: Valores Iniciales (Usando Apuntador)\n" << endl;
    cout << "Direccion Inicial de A: " << p << endl;
    cout << "Valor Inicial de A: " << *p << endl;

    cout << "\n-----PARTE 2: Usando Aritmetica\n" << endl;
    cout << "Direccion de A+1 (Usando p+1): " << p+1 << endl;
    cout << "Valor de A+1 (Usando p+1): : " << *(p+1) << endl;

    cout << "\n-----PARTE 3: Usando Variable\n" << endl;
    
    cout << "Direccion Inicial:" << endl;
    //usando c (printf)
    printf("Usando C:   'a' = %d", a); //Direccion inicial arreglo
    printf(" | '&a[0]' = %d", &a[0]); //Direccion inicial arreglo en pos 0.
    printf(" | '&a' = %d\n", &a); //Direccion inicial arreglo
    
    //usando c++ (cout)
    cout << "Usando C++: 'a' = " << a; //Direccion inicial arreglo
    cout << " | '&a[0]' = " << &a[0]; //Direccion inicial arreglo en pos 0.
    cout << " | '&a' = " << &a << endl; //Direccion inicial arreglo
    
    cout << "\nValor Inicial:" << endl;
    //usando c (printf)
    printf("Usando C:   'a[0]' = %d", a[0]); //Valor inicial arreglo en pos 0.
    printf(" | '*a' = %d\n", *a); //Valor inicial arreglo en a.
    //usando c++ (cout)
    cout << "Usando C++: 'a[0]' = " << a[0]; //Valor inicial arreglo en pos 0.
    cout << " | '*a' = " << *a << endl; //Valor inicial arreglo en a.

}