#include<iostream>
#include<string.h>
using namespace std;

char ciudad[30];
char *apCH=NULL;

void datos(){
    cout<<"Dame la ciudad: ";
    cin.getline(ciudad,30,'\n');
}

int main(){
    datos();
    apCH = ciudad;
    cout<<"La cadena es: "<<ciudad<<endl;

    cout<<"============================================"<<endl;
    cout<<"La direccion inicial de la cadena es: "<<&ciudad<<endl;

    cout<<"============================================"<<endl;
    cout<<"Las cadenas son arreglos: "<<endl;
    for(int i=0; ciudad[i]!='\0';i++){
        cout<<"Posicion "<<i<<": "<<ciudad[i]<<endl;
    }

    cout<<"============================================"<<endl;
    cout<<"Usando apuntador apCH: "<<endl;
    for(int i=0; *(apCH+i) != '\0'; i++){
        cout<<*(apCH + i) << " en la direccion "<<(void *)(apCH+i) <<endl;
    }

}


