#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "spanish");

    //Funcion sizeof obtiene el tamaño en BYTES de un tipo de Dato
    cout<<"Tamanio de Float: "<<sizeof(float)<<endl;
    cout<<"Tamanio de int short: "<<sizeof(int short)<<endl;
    cout<<"Tamanio de long int: "<<sizeof(long int)<<endl;
    cout<<"Tamanio de long double: "<<sizeof(long double)<<endl;

    cout<<"============================================================\n";
    cout<<"Memoria Estntica:\n\n";
    int n=50, *sta;
    *sta = n;

    cout<<"La direccion de sta es: "<<sta<<"<-- se asigna una direccion fija al momento de compilar"<<endl;
    cout<<"El valor de sta es: "<<*sta<<endl;
    cout<<"La desventaja es que no se sabe el espacio de memoria hasta la compilacinn."<<endl;


    cout<<"============================================================\n";
    cout<<"Funcion malloc y free:\n\n";
    int *ptr; //Declaramos un puntero INT
	ptr = (int*) malloc(sizeof(int));  //Y le asigno un espacio en memoria de manera dinamica del tamano de un INT, asi ninguna otra variable podra usar ese espacio.
	*ptr = 5;
	cout<<"El valor del puntero es: "<<*ptr<<endl;
	cout<<"La direccion es: "<<ptr<<endl;
	free(ptr); //Despues de usar y asignar el valor en la memoria con malloc, hay que liberarlo siempre para que otro lo pueda usar.

	cout<<"============================================================\n";
    cout<<"Funcion new y delete:\n\n";
    int *ptrC; //Declaramos un puntero INT
	ptrC = new int;  //Y le asigno un espacio en memoria de manera dinamica del tamaño de un INT, asi ninguna otra variable podra usar ese espacio.
	*ptrC = 55;
	cout<<"El valor del puntero es: "<<*ptrC<<endl;
	cout<<"La direccinn es: "<<ptrC<<endl;
	delete(ptrC); //Despues de usar y asignar el valor en la memoria con new, hay que liberarlo siempre para que otro lo pueda usar.

    cout<<endl;
}






