#include<iostream>
using namespace std;

main(){

    int a[4];

    cout<<"Capturar el arreglo \n";
    for(int i=0 ; i<4 ; i++){
        cout<<"Dame el valor en la posicion "<<i<<": ";
        cin>>a[i];
    }
    cout<<"\nEl arreglo fue.. \n";
    for(int i=0 ; i<4 ;i++){
        cout<<"El arreglo en posicion "<<i<<" es: "<<a[i]<<endl;
    }



}
