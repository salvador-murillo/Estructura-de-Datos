#include<iostream>
using namespace std;
main(){
    int TAM,opc;
    do{
        system("CLS");
        cout<<"De qué tamanio quieres el arreglo: ";
        cin>>TAM;

        int a[TAM];

        for(int i=0 ; i<TAM ; i++){
            cout<<"Dame arr en pos "<<i<<": ";
            cin>>a[i];
        }
        cout<<endl<<"El arreglo es: "<<endl;
        for(int i=0 ; i<TAM ; i++){
            cout<<"Valo de arr en pos "<<i<<" es "<<a[i]<<endl;
        }
        cout<<"Again? 1-SI 0-NO";
        cin>>opc;
    }while(opc==1);

}
