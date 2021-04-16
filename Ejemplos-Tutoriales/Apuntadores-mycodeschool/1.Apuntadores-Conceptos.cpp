/*
Youtube: mycodeschool Pointers in c/c++
Link: http://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_
*/
#include <iostream>
using namespace std;

int main() {
  cout << "\033[2J\033[0;0H";
  
  char letra='a';
  
  cout << "\n-----PARTE 1: APUNTADOR A VARIABLE\n" << endl;
  //Apuntador a variable
  char* p;
  p=&letra;

  cout << "Direccion de letra: "<< (void *) &letra << endl;
  cout << "Valor de letra con variable: "<< letra << endl;
  cout << "Direccion de letra (Contenido de p): "<< (void *) p << endl;
  cout << "Valor de letra con *p: "<< *p << endl;
  cout << "Direccion de p: "<< &p << endl;

  cout << "\n-----PARTE 2: APUNTADOR A APUNTADOR\n" << endl;
  //Apuntador a Apuntador
  char** apP;
  apP = &p;

  cout << "Direccion de p (Contenido de apP): "<< (void *) apP << endl;
  cout << "Direccion de letra (Contenido de p por medio de apP): "<< (void *) *apP << endl;
  cout << "Valor de letra con **apP: "<< **apP << endl;
  cout << "Direccion de apP: "<< &apP << endl;



}