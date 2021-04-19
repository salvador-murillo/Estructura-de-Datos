/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #10: Apuntadores y Cadenas
*/
#include <iostream>
#include <unistd.h>
using namespace std;

//Variables globales
int i=0;
char cadena1[50], cadena2[50];

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #10: Apuntadores y Cadenas\n" << endl;
}

void mostrarCadenas(){
    cout << "\nCadena 1: " << cadena1 << " | Cadena 2: " << cadena2 << endl;
}

int strLong(char *cadena){
    int con=0;
    while(*cadena!='\0'){
        con+=1;
        cadena++;
    }
    return con;
}

void strInverse(char *cadena){
    int pMax = strLong(cadena)-1, j=0;
    char cadenaInv[30]=" ";
    cout << "\n Original: " << cadena;
    for(i=pMax; i>=0; i--,j++){
        cadenaInv[j]=cadena[i];
    }
    cout << "\nInvertida: " << cadenaInv;
}

void strCopy(char *cadena1, char *cadena2){
    int mayor = 0;
    (strLong(cadena1) >= strLong(cadena2)) ? mayor = strLong(cadena1) : mayor = strLong(cadena2);
    for(i=0; i<mayor; i++){
        cadena1[i]=cadena2[i];
    }
}

void strConc(char *cadena1, char *cadena2){
    int lenCad1= strLong(cadena1);
    for(i=0;*(cadena2+i)!='\0';i++){
        cadena1[lenCad1+i]=cadena2[i];
    }
}

int strBool(char *cadena1, char *cadena2){
    int con=0;
    bool isTrue=0;
    if(strLong(cadena1) == strLong(cadena2)){
        for(i=0; i<strLong(cadena1); i++){
            if(cadena1[i]==cadena2[i]){
                con+=1;
            }
        }
        if(strLong(cadena1)==con){
            cout << "VERDAD";
            isTrue=1;
        }else{
            cout << "FALSO";
            isTrue=0;
        }
    }else{
        cout << "FALSO";
        isTrue=0;
    }
    return isTrue;
}

void calcularFuncion(int opc){
    int opcCad=0;
    mostrarTitulo();
    switch (opc)
        {
        case '1':
            mostrarCadenas();
            cout << "\nCadena a calcular (1) o (2): ";
            cin >> opcCad;
            (opcCad==1) ? cout<<"\n("<< strLong(cadena1) <<") " << cadena1 : cout<<"\n("<< strLong(cadena2) <<") " << cadena2;
            break;
        case '2':
            mostrarCadenas();
            cout << "\nCadena a invertir (1) o (2): ";
            cin >> opcCad;
            (opcCad==1) ? strInverse(cadena1) : strInverse(cadena2);
            break;
        case '3':
            cout << "Antes de copiar:";
            mostrarCadenas();
            strCopy(cadena1, cadena2);
            cout << "\nDespues de copiar:";
            mostrarCadenas();
            break;
        case '4':
            mostrarCadenas();
            strConc(cadena1, cadena2);
            cout << "Cadena 1 + Cadena 2 = " << cadena1;
            break;
        case '5':
            mostrarCadenas();
            cout << "\nEl resultado de comparar es ";
            strBool(cadena1, cadena2);
            break;
        default:
            break;
        }
}

int main() {
    int salir=1, salirOPC=1;
    do{
        char opc='0';
        mostrarTitulo();
        cout << "Ingresa cadena 1: ";
        cin >> cadena1;
        cout << "Ingresa cadena 2: ";
        cin >> cadena2;

        do{
            cout << "\nMENU DE OPCIONES:\n\n"
                << "1.Longitud de Cadena\n"
                << "2.Invertir Cadena\n"
                << "3.Copiar Cadena\n"
                << "4.Concatenar Cadena\n"
                << "5.Comparar Cadena\n";

            cout << "\nIngrese funcion a realizar: ";
            cin >> opc;
            fflush(stdin);
            calcularFuncion(opc);

            if(opc>='1' && opc <='5'){
                cout << "\n\nRepetir menu opciones? Si (1) o No (2): ";
                cin >> salirOPC;
            }else{
                cout << "Opcion no valida";
                cout.flush();
                usleep(1200000);
            }
        }while (salirOPC==1);
        cout << "Repetir con cadenas nuevas? Si (1) o No (2): ";
        cin >> salir;
    } while(salir==1);
}