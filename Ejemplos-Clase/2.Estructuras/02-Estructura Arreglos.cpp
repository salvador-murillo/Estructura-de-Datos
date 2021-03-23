#include<iostream>
#include<string>
using  namespace std;

struct persona{
    int cod;
    string nom;
    string apP;
    string apM;
};

main(){
    struct persona alumno[3];

    for(int i=0; i<3 ; i++){
        cout<<"Dame el codigo: "; cin>>alumno[i].cod;
        fflush(stdin);
        cout<<"Apellido paterno: "; getline(cin,alumno[i].apP);
        cout<<"Apellido materno: "; getline(cin,alumno[i].apM);
        cout<<"Tu nombre: "; getline(cin,alumno[i].nom);
    }

    cout<<"Los alumnos son: "<<endl;
    for(int i=0;i<3;i++){
        cout<<"Alumno "<<i+1<<endl;
        cout<<alumno[i].nom<<" "<<alumno[i].apP<<" "<<alumno[i].apM<<" - codigo: "<<alumno[i].cod<<endl;
    }

}
