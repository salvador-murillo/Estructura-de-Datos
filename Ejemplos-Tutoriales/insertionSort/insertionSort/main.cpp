#include <iostream>
#include <string>

using namespace std;


void mostrarNumeros(int n, int ar[]){
    for(int i=0;i<n;i++){
        cout << ar[i] << " ";
    }
    cout << endl;
}

int sockMerchant(int n, int ar[]) {
    int pairs=0;
    int nd=0,aux=0, j=0;
    
    //Reordenar numeros
    for(int i=1; i<n;i++){
        aux=ar[i];
        j=i;
        while(j>0 && ar[j-1]>aux){
            ar[j]=ar[j-1];
            j--;
        }
        ar[j]=aux;
    }
    
    mostrarNumeros(n, ar);
    
    aux=ar[0];
    for(int i=0; i<n ; i++){
        if(aux==ar[i]){
            nd++;
            cout << "\nValor de ND: " << nd;
        }else{
            pairs=pairs+(nd/2);
            cout << "\nValor de PAIRS: " << pairs;
            aux=ar[i];
            nd=1;
        }
    }
    cout << "\nValor final de Pairs: " << pairs;
    return pairs;
}


int main(){
    int n=0;
    cout << "Dame el numero de elementos: "; cin >> n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cout << "Dame el valor #" << i+1 << ": "; cin >> arr[i];
    }
    
    cout << "Valores antes del ordenamiento:\n";
    mostrarNumeros(n, arr);
    sockMerchant(n, arr);
    
}
