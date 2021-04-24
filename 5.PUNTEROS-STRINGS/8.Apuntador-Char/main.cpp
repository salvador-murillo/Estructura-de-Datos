/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #8: Apuntadores Char
*/
#include <iostream>
using namespace std;

const int MAX_LENGTH = 30;
char word[MAX_LENGTH]= " ";
char* apWord=NULL;

void mostrarTitulo(){
    cout << "\033[2J\033[0;0H";
    cout << "\tPractica #8: Apuntadores Char\n" << endl;
}

void getWord(){
    cout << "Ingresa la palabra: ";
    cin.getline(word,MAX_LENGTH,'\n');
}

void printWord(char* palabra){
    cout << "\nLa cadena es: " << palabra << endl;
}

void direccionesLetras(char* palabra){
    int size = 0;
    cout << "\nDirecciones por letra:\n\n";
    for(int i=0; *(palabra+i)!='\0';i++){
        cout << *(palabra+i) << " en -> " << (void *) (palabra+i) << endl;
        size+=1;
    }
    cout << "\nDireccion inicial: " << (void *) palabra << endl;
    cout << "Direccion final: " << (void *) (palabra+size-1) << endl;
}

int main() {
   apWord = word;
   mostrarTitulo();
   getWord();
   printWord(apWord);
   direccionesLetras(apWord);
}