/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #2: Repaso Funciones
*/
#include <iostream>
#include <vector>
#include <random>   //Libreria para crear numeros aleatorios
using namespace std;

random_device rd;  // Obtiene un # random del dispositivo
mt19937 gen(rd()); // Generador de numeros (Merssene Twister Algoritmo)
uniform_int_distribution<> randNum(0,9); //Define rango de numeros

int i, menu,contP,contI, numeroB, posicionB;

void randomARR(int a[], int tam){
    for(i=0;i<tam;i++){
        a[i]=randNum(gen);
    }
}

int tamanoARR(int &tamA, int &tamB){
   int selArr=0;
   cout << "\nQue arreglo quieres llenar: 1.Arreglo A - 2.Arreglo B\nSeleccione: ";
   cin >> selArr;
   if(selArr==1){
      cout<<"Tamano de Arreglo A: "; 
      cin>>tamA;
   }else if (selArr==2){
      cout<<"Tamano de Arreglo B: "; 
      cin>>tamB;  
   }
   return selArr;
}

void mostrarARR(int a[],int tam){
    for(i=0;i<tam;i++){
        cout<< a[i] << " " ;
    }
}

void escogerARR(int aA[], int aB[], int arrD[], int tA, int tB, int &tD){

   int opc;
   cout << "\nEscoge: 1-Arreglo A o 2-Arreglo B\nSeleccione: ";
   cin >> opc;
   opc == 1 ? tD=tA : tD=tB;
   
   if(opc == 1){
      for(i=0;i<tD;i++){
         arrD[i]=aA[i];
      }
   }else if (opc == 2){
      for(i=0;i<tD;i++){
         arrD[i]=aB[i];
      }
   }else {
      cout << "\nOpcion NO valida";
   }
}

void mostrarPar(int a[], int tam){
   contP=0;
   for(i=0;i<tam;i++){
        if(int(a[i])%2==0){
           cout<< a[i] << " " ;
           contP++;
        }
    }
   cout << "\nCantidad Pares: " << contP; 
}

void mostrarImpar(int a[], int tam){
   contI=0;
   for(i=0;i<tam;i++){
        if(int(a[i])%2!=0){
           cout<< a[i] << " " ;
           contI++;
        }
   }
   cout << "\nCantidad Impares: " << contI;
}

void buscarNumero(int a[], int tam, int numeroB){
   bool check = false;
   for(i=0;i<tam;i++){
      if(numeroB==a[i]){
         check = true;
      }
   }
   check==true ? cout << "\nEl numero SI existe !" : cout << "\nEl numero NO existe !";
}

void mostrarPos(int a[], int posB){
   cout << "\nEl valor en la pos " << posB << " es " << a[posB];
}

void mostrarMenu(int &menu){
   menu=0;
   cout << "\033[2J\033[0;0H";
   cout << "CUCEA | Estructura de Datos | Salvador Murillo Arias\n";
   cout << "\t   Programa #2: Repaso Funciones\n"; 
   
   cout << "\n1- Llenar arreglo deseado de tamaño (N)";
   cout << "\n2- Mostrar arreglo deseado";
   cout << "\n3- Mostrar elementos pares del arreglo deseado";
   cout << "\n4- Mostrar elementos impares del arreglo deseado";
   cout << "\n5- Buscar un valor en el arreglo deseado";
   cout << "\n6- Seleccionar una posición y mostrar el valor de dicha posición en el arreglo deseado.";
   cout << "\n7- Realizar una operación básica (+,-,/,*) a seleccionar, con dos valores del arreglo deseado, seleccionando su posición.";
   cout << "\n8- Cambiar el valor de una posición en el arreglo seleccionado.";

   cout << "\n\nIngrese funcion a realizar: ";
   cin >> menu;
}

int main() {

   // int A1[5]={ 0, 1, 2, 3, 4};// TEST
   // int B1[5]={ 10, 20, 30, 40, 50}; // TEST
   
   int salir=1;
   int tamanoA=1, tamanoB=1, tamanoD=1;
   int arrA[tamanoA];
   int arrB[tamanoB];
   int arrD[tamanoD];
   
   do{
      int salirMenu=1;
      bool checkArrA = false;
      bool checkArrB = false;
      do{
         mostrarMenu(menu);
         if(menu>=1 && menu<=8){

            if(menu==1){
               int opcTam=0;
               opcTam=tamanoARR(tamanoA, tamanoB);
               if(opcTam==1){
                  randomARR(arrA,tamanoA);
                  checkArrA = true;
                  cout << "\nAntes   A: "; mostrarARR(arrA,tamanoA);// TEST
               }else if(opcTam==2){
                  randomARR(arrB,tamanoB);
                  checkArrB = true; 
                  cout << "\nAntes B: "; mostrarARR(arrB,tamanoB);// TEST
               }else {
                  cout << "\nOpcion NO valida";
               }

               cout << "\nDespues A: "; mostrarARR(arrA,tamanoA);// TEST
               cout << "\nDespues B: "; mostrarARR(arrB,tamanoB); // TEST

            }else if (menu==2 && (checkArrA == true || checkArrB == true)){
               escogerARR(arrA, arrB, arrD, tamanoA, tamanoB, tamanoD);
               cout << "\nArreglo D: "; mostrarARR(arrD,tamanoD);
            }else if (menu==3 && (checkArrA == true || checkArrB == true)){
               escogerARR(arrA, arrB, arrD, tamanoA, tamanoB, tamanoD);
               cout << "\n  Pares: "; mostrarPar(arrD,tamanoD);
            }else if (menu==4 && (checkArrA == true || checkArrB == true)){
               escogerARR(arrA, arrB, arrD, tamanoA, tamanoB, tamanoD);
               cout << "\nImpares: "; mostrarImpar(arrD,tamanoD);
            }else if (menu==5 && (checkArrA == true || checkArrB == true)){
               cout << "\nIngresa numero a buscar: ";
               cin >> numeroB;
               escogerARR(arrA, arrB, arrD, tamanoA, tamanoB, tamanoD);
               buscarNumero(arrD, tamanoD, numeroB);
            }else if (menu==6 && (checkArrA == true || checkArrB == true)){
               cout << "\nIngresa posicion a buscar: ";
               cin >> posicionB;
               escogerARR(arrA, arrB, arrD, tamanoA, tamanoB, tamanoD);
               mostrarPos(arrD, posicionB);
            }else if (menu==7 && (checkArrA == true || checkArrB == true)){
               
            }else if (menu==8 && (checkArrA == true || checkArrB == true)){
               
            }else{
               cout << "\nPrimero debes llenar un arreglo, selecciona opcion 1";
            }
         }else{
            cout << "\nNumero del menu NO valido";
         }

         cout << "\nVolver a menu 1-SI 2-NO:";
         cin >> salirMenu;
      }while(salirMenu==1);

      cout << "\nRepetir programa 1-SI 2-NO: ";
      cin >> salir;

   }while(salir==1);
}