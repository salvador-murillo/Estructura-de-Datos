#include<iostream>
#include<string>
using  namespace std;

typedef struct persona{
    char nom[30];
    int edad;
};

int sumaEdad(persona al){
    return(al.edad+20);
}

int sumaEdad2(int x){
    return(x+30);
}

main(){
    persona alumno; //Variable ALUMNO de estructura PERSONA

    cout<<"Dame el nombre: ";  cin>>alumno.nom;
    cout<<"Dame la edad: "; cin>>alumno.edad;

    cout<<"La edad +20 es: "<<sumaEdad(alumno)<<endl;

    cout<<"Usando la otra forma +30: "<<sumaEdad2(alumno.edad);
}
