#include<iostream>
#include<string>
using  namespace std;

typedef struct direc{
    string calle,col;
    int num;
    char cp[5];
};

typedef struct persona{
    char nom[30],apell[60];
    direc dirpers;
};

main(){
    persona alumno; //Variable ALUMNO de estructura PERSONA

    cout<<"Dame el nombre: "; cin>>alumno.nom;
    cout<<"Dame apellidos: "; cin>>alumno.apell;
    fflush(stdin);
    cout<<"Calle: "; getline(cin, alumno.dirpers.calle);
    cout<<"Numero: "; cin>>alumno.dirpers.num;
    fflush(stdin);
    cout<<"Colonia: "; getline(cin,alumno.dirpers.col);
    cout<<"CP: "; cin>>alumno.dirpers.cp;

    cout<<"Bienvenido "<<alumno.nom<<" "<<alumno.apell<<"\nTu direccion es: "<<alumno.dirpers.calle<<" #"<<alumno.dirpers.num<<endl;
    cout<<"en la colonia "<<alumno.dirpers.col<<" CP - "<<alumno.dirpers.cp;


}
