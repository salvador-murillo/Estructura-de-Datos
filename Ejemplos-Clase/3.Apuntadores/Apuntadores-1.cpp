#include <iostream>

using namespace std;

int main(){
    int num;
    int *dir_num; //Puntero guarda la direcci�n de memoria de una variable

    num = 20;
    dir_num = &num; //Al puntero le asigno la direcci�n de memoria

    cout<<"Tamanio de num: "<<sizeof(num)<<endl;

    /*
    cout<<"Numero: "<<num<<endl; //Imprime el valor de num
    cout<<"Direccion de memoria de Num: "<<&num; //Imprime la DIRECCION de memoria de NUM
    */

    cout<<"Numero: "<<*dir_num<<endl; //Imprime el valor de num
    cout<<"Direccion de memoria de Num: "<<dir_num; //Imprime la DIRECCION de memoria de NUM




}
