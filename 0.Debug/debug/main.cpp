/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Programa #Numero: Descripcion de creacion de archivo binario, desglose de escritura y lectura
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Persona{
    int edad;
    int lenName;
    char nombre[25];
    Persona *next;
    Persona *prev;
};

//TODO Agregar de acuerdo a menu de opciones
void mostrar(ostream &out, Persona p){
    out << p.nombre << ':' << p.edad << endl;
}

void showPerson(Persona *pList)
{
    int count = 1;
    Persona *aux = pList;
    if(aux == nullptr){
        cout << "\nLista Vacia" << endl;
    }
    while(aux->next!=nullptr){
        cout << "\nPersona #" << count << endl;
        cout << "\nNOMBRE: " << aux->nombre;
        cout << "\nEDAD: " << aux->edad;
        count++;
        aux=aux->next;
    }
    cout << endl;
}

void write(Persona *p){
    Persona *aux = p;
    //Creacion de variable para guardar datos
    ofstream myFile("datos.bin", ios::binary);
    
    while (aux!=nullptr) {
        myFile.write((const char *)(&(aux->edad)), sizeof(int));
        myFile.write((const char *)(&(aux->lenName)), 1);
        myFile.write((const char *)(&(aux->nombre)), aux->lenName+1);
        aux=aux->next;
    }
    myFile.close();
//    ofstream f("datos.bin", ios::binary); //Revisar ios::opcion para cuando se guarden mas registros
//    if(f.is_open()){
//        f.write((char *) &p, sizeof(Persona));
//    }else{
//        cout << "Error de apertura de archivo." << endl;
//    }
//    f.close();
}

void read(){
    Persona *p;
    //Creacion de variable para leer datos
    ifstream in("datos.bin", ios::binary); //Abre archivos.bin
    if(in.is_open()){
        while(!in.eof()){
            in.read((char *) &p->edad, sizeof(int));
            in.read((char *) &p->lenName, sizeof(int));
            in.read((char *) &p->nombre, p->lenName);
            p=p->next;
            p->prev=p;
        }
    }else{
        cout << "Error de apertura de archivo." << endl;
    }
    in.clear();
    in.close();
    cout << "\nARCHIVO LEIDO:\n";
    showPerson(p);
    
}

void addPerson(Persona *&pList)
{
    Persona *nvaPerson = new Persona();
    cout << "\nIngresa el nombre: ";
    cin.getline(nvaPerson->nombre, 25, '\n');
    cout << "Ingresa la edad: ";
    cin >> nvaPerson->edad;
    nvaPerson->lenName = (int)strlen(nvaPerson->nombre);
    nvaPerson->next = pList;
    nvaPerson->prev = NULL;

    if(pList != NULL)
        pList->prev = nvaPerson;

    pList = nvaPerson;
}

int main() {
    Persona *pList = new Persona();
    
    addPerson(pList);
    showPerson(pList);
    cin.ignore();
    write(pList);
    read();
//    addPerson(pList);
//    showPerson(pList);
//    write(pList);

    // read();
}
