#include<iostream>
#include<string>
using  namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
    char nombdia[10];
};

typedef struct persona{
    char nom[30];
    char app[20];
    char apm[20];
};

main(){
    struct fecha hoy;

    cout<<"Qué día es hoy: "; cin>>hoy.dia;
    cout<<"Qué mes es hoy: "; cin>>hoy.mes;
    cout<<"Qué año es hoy: "; cin>>hoy.anio;
    cout<<"Qué día de la semana: "; cin>> hoy.nombdia;

    cout<<"La fecha de hoy es: "<<hoy.nombdia<<" "<<hoy.dia<<"/"<<hoy.mes<<"/"<<hoy.anio<<endl;

    persona alumno;
    cout<<"Dame tu nombre: "; cin>>alumno.nom;
    cout<<"Dame tu apellido pat: "; cin>>alumno.app;
    cout<<"Dame tu Apellido mat: "; cin>>alumno.apm;

    cout<<"\nEl alumno se llama "<<alumno.nom<<" "<<alumno.app<<" "<<alumno.apm;



}
