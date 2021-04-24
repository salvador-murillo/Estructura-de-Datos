#include <iostream>
#include <stdlib.h>
using namespace std;

//prototipos de funciones
void prototipoCopia (int); //por copia o valor
void prototipoReferencia (int &); //por referencia o direccion
void prototipoApuntador (int *); //por apuntador


int main(void){
	int num,*ptr;
	ptr = &num;

	//paso por copia o valor
	num = 10;
	cout<<"Por copia antes num = "<<num<<endl;
	prototipoCopia(num);
	cout<<"Por copia despues num = "<<num<<endl;

	/************************************************************************************/
	//paso por referencia o direccion
	num = 10;
	cout<<"Por referencia antes num = "<<num<<endl;
	prototipoReferencia(num);
	cout<<"Por referencia despues num = "<<num<<endl;

	/***********************************************************************************/
	//paso por apuntadores
	num = 10;
	cout<<"Por apuntador antes num = "<<num<<endl;
	prototipoApuntador(ptr);
	cout<<"Por apuntador despues num = "<<num<<endl;


} //main

/**************************************************************************************/

void prototipoCopia(int n){
	n = n*2;
	return;
} //prototipoCopia

void prototipoReferencia(int &n){
	n = n*2;
	return;
}//prototipoReferencia

void prototipoApuntador(int *n){
	*n = (*n) * 2;
	cout<<"Direccion de puntero: "<<n;
	return;
}//prototipoApuntador


