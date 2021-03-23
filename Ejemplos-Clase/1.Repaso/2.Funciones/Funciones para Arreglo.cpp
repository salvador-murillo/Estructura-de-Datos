#include<iostream>
using namespace std;

void capARR(int g[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"Dame el valor "<<i<<": ";
        cin>>g[i];
    }
}
void mostARR(int u[],int longitud){
    for(int i=0;i<longitud;i++){
        cout<<"El arreglo en su pos "<<i<<" es: "<<u[i]<<" \n";
    }
}

main(){
    int siz,siz2;
    cout<<"Dame el tamanio del arreglo al: "; cin>>siz;
    cout<<"Dame el tamanio del arreglo mat: "; cin>>siz2;
    int alumnos[siz];
    int mat[siz2];

    capARR(alumnos,siz);
    mostARR(alumnos,siz);

    capARR(mat,siz2);
    mostARR(mat,siz2);

    cout<<mat[1]<<" "<<alumnos[3];


}

