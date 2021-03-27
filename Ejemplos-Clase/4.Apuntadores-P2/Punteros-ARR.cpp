#include<iostream>
using namespace std;

main(){
    int arr[] = {15, 35, 55};
    int *ptr = arr;

    cout<<"El arreglo es: "<<endl;
    cout<<"Valor 0: "<<arr[0]<<" - Valor 1: "<<arr[1]<<" - Valor 2: "<<arr[2]<<endl<<endl;
    cout<<"Direc 0: "<<&arr[0]<<" - Direc 1: "<<&arr[1]<<" - Direc 2: "<<&arr[2]<<endl<<endl;

    cout<<"======================================"<<endl<<endl;

    cout<<"La dirección inicial de arr es: " <<arr<<endl;
    cout<<"La dirección    1    de arr es: " <<arr+1<<endl;
    cout<<"La dirección    2    de arr es: " <<arr+2<<endl<<endl;

    cout<<"======================================"<<endl<<endl;

    cout<<"Valor en  ptr  es: "<< *(ptr) <<" y su dirección es: "<< ptr <<endl;
    cout<<"Valor en ptr+1 es: "<<*(ptr+1)<<" y su dirección es: "<<ptr+1<<endl;
    cout<<"Valor en ptr+2 es: "<<*(ptr+2)<<" y su dirección es: "<<ptr+2<<endl;




}
