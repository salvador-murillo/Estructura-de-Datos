#include<iostream>
using namespace std;

main(){
    setlocale(LC_ALL, "spanish");

    int vec[]={30,20,50}, *dir_ap;

    dir_ap=vec;


    cout<<"================================="<<endl;

    for(int i=0;i<3;i++){
        cout<<"Valor en posici�n "<<i+1<<" es: "<<vec[i]<<" y su direcci�n es: "<<&vec[i]<<endl;
    }

    cout<<"================================="<<endl;

    for(int i=0;i<3;i++){
        cout<<"Valor en posici�n "<<i+1<<" es: "<<*(dir_ap+i)<<" y su direcci�n es: "<<&dir_ap+i<<endl;
    }



}
