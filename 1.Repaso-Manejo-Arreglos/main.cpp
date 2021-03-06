/*Estructura de Datos
  Repaso - Manejo de Arreglos
  Salvador Murillo Arias
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>   //Libreria para crear numeros aleatorios
using namespace std;

random_device rd;  // Obtiene un # random del dispositivo
mt19937 gen(rd()); // Generador de numeros (Merssene Twister Algoritmo)
uniform_int_distribution<> randNum(0,9); //Define rango de numeros

int i, nPar=0, nImp=0, pParMayor=0,vParMayor=0, pParMenor=0,vParMenor=8, pImpMenor=0, vImpMenor=9, pImpMayor=0, vImpMayor=1;
float vMedia = 0;

void calcularNumeros(int a[]){

    nPar=0, nImp=0, pParMayor=0,vParMayor=0, pParMenor=0,vParMenor=8, pImpMenor=0, vImpMenor=9, pImpMayor=0, vImpMayor=1;
    int sPares=0;
    
    cout << "Arreglo : ";
    for(i=0;i<20;i++){

        a[i]=randNum(gen);
        cout << " " << a[i] << " "; 
         
        if(a[i]%2==0){
            nPar++;
            sPares+=a[i];
            if(a[i]>vParMayor){
                vParMayor = a[i];
                pParMayor = i;
            }else if (a[i]<vParMenor){
                vParMenor = a[i];
                pParMenor = i;   
            }
        }else{
            nImp++;
            if(a[i]<vImpMenor){
                vImpMenor = a[i];
                pImpMenor = i;
            }else if (a[i]>vImpMayor){
                vImpMayor = a[i];
                pImpMayor = i;
            }
        }
    }
    vMedia = float(sPares)/nPar;
}

string calcularModa(int a[]){
    int arr[5]={0,0,0,0,0};
    for (i=0; i<20; i++){
        if(a[i]%2!=0){
          if(a[i]==1){
              arr[0]+=1;
          }
          if(a[i]==3){
              arr[1]+=1;
          }
          if(a[i]==5){
              arr[2]+=1;
          }
          if(a[i]==7){
              arr[3]+=1;
          }
          if(a[i]==9){
              arr[4]+=1;
          }
        }
    }

    int mayor=arr[0];
    int checkRep=0;
    vector <string> moda;

    for(i=0; i<5; i++){
        if(mayor<arr[i]){
            mayor=arr[i];
        }
    }

    for (i=0;i<5;i++){
        if(mayor==arr[i]){
            checkRep+=1;
            if(i==0){
                moda.push_back("1");
            }
            if(i==1){
                moda.push_back("3");
            }
            if(i==2){
                moda.push_back("5");
            }
            if(i==3){
                moda.push_back("7");
            }
            if(i==4){
                moda.push_back("9");
            }
        }
    }
   
    string m = "";
    for (int i = 0; i < moda.size(); i++) {
        if(checkRep==1){
            m = moda.at(i);    
        }else if(checkRep>=2){
            m+= moda.at(i) + " ";
        }
    }

    if(checkRep==1){
        return "Moda: " + m;
    }else if(checkRep==2){
        return "Bimodal: " + m; 
    }else if (checkRep>2){
        return "Multimodal: " + m; 
    }
}

void mostrarOrdenado(int a[]){
    sort(a, a+20);
    cout << "\nOrdenado: ";
    for(i=0; i<20; i++){
        cout << " " << a[i] << " ";
    }
}

void mostrarPosicion(){
    cout << "\nPosicion: ";
    for(i=0; i<20; i++){
        i<9 
        ? cout << " " << i+1 << " " 
        : cout << i+1 << " ";
    }
    cout << endl;
}

void mostrarResultados(int a[]){
    cout << "\n";
    cout << "PARES \n";
    cout << "Cantidad: " << nPar << endl;
    cout << "Media: " << vMedia << endl;
    cout << "MAYOR (Pos: " << pParMayor + 1 << " Valor: " << vParMayor << ") | "
         << "MENOR (Pos: " << pParMenor + 1 << " Valor: " << vParMenor << ")\n\n";
    cout << "IMPARES \n";
    cout << "Cantidad: " << nImp << endl;
    cout << calcularModa(a) << endl;
    cout << "MAYOR (Pos: " << pImpMayor + 1 << " Valor: " << vImpMayor << ") | "
         << "MENOR (Pos: " << pImpMenor + 1 << " Valor: " << vImpMenor << ")\n";
}

int main() {
	int salir;
	do {
    cout << "\033[2J\033[0;0H";
		cout << "\t\t\tREPASO DE ARREGLOS\n\n";
        int a[20];

        calcularNumeros(a);
        mostrarOrdenado(a);
        mostrarPosicion();
        mostrarResultados(a);

        cout << "\nQuieres repetir el programa? Si (1) o No (2): ";
        cin >> salir;
        cout << "\033[2J\033[0;0H";
    } while (salir != 2);
}