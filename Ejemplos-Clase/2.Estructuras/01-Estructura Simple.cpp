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

    cout<<"Qu� d�a es hoy: "; cin>>hoy.dia;
    cout<<"Qu� mes es hoy: "; cin>>hoy.mes;
    cout<<"Qu� a�o es hoy: "; cin>>hoy.anio;
    cout<<"Qu� d�a de la semana: "; cin>> hoy.nombdia;

    cout<<"La fecha de hoy es: "<<hoy.nombdia<<" "<<hoy.dia<<"/"<<hoy.mes<<"/"<<hoy.anio<<endl;

    persona alumno;
    cout<<"Dame tu nombre: "; cin>>alumno.nom;
    cout<<"Dame tu apellido pat: "; cin>>alumno.app;
    cout<<"Dame tu Apellido mat: "; cin>>alumno.apm;

    cout<<"\nEl alumno se llama "<<alumno.nom<<" "<<alumno.app<<" "<<alumno.apm;



}
