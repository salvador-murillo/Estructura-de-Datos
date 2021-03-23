#include<iostream>
using namespace std;

main(){
    int a[5]={44,5,87,6,8};
    int busc;

    //buscar un valor
    cout<<"Que valor vas a buscar: ";
    cin>>busc;

    for(int i=0 ; i<5 ; i++){
        if(busc==a[i]){
            cout<<"El valor se encontro en la posicion: "<<i;
        }
    }

    //Sacar el valor de una posición
    cout<<"\nEl valor de que posicion deseas: ";
    cin>>busc;

    cout<<"\nEl valor del arreglo en "<<busc<<" es: "<<a[busc];

}
