#include<iostream>
#include<stdlib.h>
using namespace std;

main(){
    setlocale(LC_ALL, "spanish");

    //Funcion sizeof obtiene el tamanio en BYTES de un tipo de Dato
    cout<<"tamanio de Float: "<<sizeof(float)<<endl;
    cout<<"tamanio de int short: "<<sizeof(int short)<<endl;
    cout<<"tamanio de long int: "<<sizeof(long int)<<endl;
    cout<<"tamanio de long double: "<<sizeof(long double)<<endl;

    cout<<"============================================================\n";
    cout<<"Memoria Estatica:\n\n";

    int a[3]={3,4,10};
    for(int i=0;i<3;i++){
        cout<<"El valor de "<<i<<" es: "<<a[i]<<endl;
        cout<<"La direccion es: "<<&a[i]<<endl;
	}

    cout<<"============================================================\n";
    cout<<"Varios espacios de memoria -  malloc y free:\n\n";

    int *ptrX; //Declaramos un puntero INT
	ptrX = (int*) malloc(3*sizeof(int));  //Y le asigno un espacio en memoria de manera dinamica del tamanio de un INT, asi ninguna otra variable podra usar ese espacio.
	//revisar el uso de calloc en los recursos de classroom

	ptrX[0] = 12;
	ptrX[1] = 112;
	ptrX[2] = 132;

	for(int i=0;i<3;i++){
        cout<<"El valor del puntero es: "<<*(ptrX+i)<<endl;
        cout<<"La direccion es: "<<ptrX+i<<endl;
	}
	free(ptrX);

	cout<<"============================================================\n";
    cout<<"Varios espacios con new y delete:\n\n";

    int *ptrN = new int[3];

    ptrN[0] = 33;
	ptrN[1] = 44;
	ptrN[2] = 55;

	for(int i=0;i<3;i++){
        cout<<"El valor del puntero es: "<<*(ptrN+i)<<endl;
        cout<<"La direccion es: "<<ptrN+i<<endl;
	}
	delete(ptrN);

    cout<<endl;
}






