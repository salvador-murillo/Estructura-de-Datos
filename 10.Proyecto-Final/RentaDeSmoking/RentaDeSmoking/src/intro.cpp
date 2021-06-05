#include <iostream>
#include <ctime>
#include "../headers/intro.hpp"
#include "../headers/date-time.hpp"
using namespace std;

void mostrarIntro(){
    cout << "\033[2J\033[0;0H";
    cout << "\t\t\033[31mProyecto Final: Sistema de Renta de Smoking\033[0m" << endl;
    cout << "\t\t    ____            _              _\n" <<      
            "\t\t   |  _ \\ ___ _ __ | |_ __ _    __| | ___ \n" <<
            "\t\t   | |_) / _ \\ '_ \\| __/ _` |  / _` |/ _ \\\n" <<
            "\t\t   |  _ <  __/ | | | || (_| | | (_| |  __/\n" <<
            "\t\t __|_| \\_\\___|_| |_|\\__\\__,_|  \\__,_|\\___|\n" <<
            "\t\t/ ___| _ __ ___   ___ | | _(_)_ __   __ _ ___ \n" <<
            "\t\t\\___ \\| '_ ` _ \\ / _ \\| |/ / | '_ \\ / _` / __|\n" <<
            "\t\t ___) | | | | | | (_) |   <| | | | | (_| \\__ \\\n" <<
            "\t\t|____/|_| |_| |_|\\___/|_|\\_\\_|_| |_|\\__, |___/\n" <<
            "\t\t                                    |___/     \n";
    cout << "\t\t\t    \033[32mpor \033[7;32mSalvador Murillo\n\033[0m" << endl;
    cout << "\t\t   Presione \033[34menter\033[0m para entrar al sistema ";
    cin.ignore();
}

void mostrarTitle(){
    time_t now = time(0);
    //now = now - 18000; //Usar para REPL
    tm *ltm = localtime(&now);
    cout << "\033[2J\033[0;0H";
    cout << "\033[0m\t\033[34m    FECHA\033[0m "; 
    day(ltm)<10 ? cout << "0" << day(ltm) : cout << day(ltm); 
    cout << "/";
    month(ltm)<10 ? cout << "0" << month(ltm) : cout << month(ltm);  
    cout << "/" << year(ltm);
    cout << "\033[0m\t\033[34mHORA\033[0m ";
    hour(ltm)<10 ? cout << "0" << hour(ltm) : cout << hour(ltm); 
    cout << ":";
    minutes(ltm)<10 ? cout << "0" << minutes(ltm) : cout << minutes(ltm);
    cout << ":";
    seconds(ltm)<10 ? cout << "0" << seconds(ltm) : cout << seconds(ltm);
    cout << "\n\t\t   \033[7;34mRENTA DE SMOKINGS\033[0m\n";
}

void pressEnter(){
    cout << "\nPresione \033[34menter\033[0m para continuar...";
    cin.ignore();
}

int mostrarMenu(){
    int opc=0, salir=0;
    do{
        mostrarTitle();
        cout << "\n\033[32m 1.-Dar de alta un nuevo traje"
            << "\n 2.-Dar de baja un traje por ID"
            << "\n 3.-Modificar todos los datos de un Smoking"
            << "\n 4.-Mostrar todos los registros"
            << "\n 5.-Buscar por talla y mostrar resultados"
            << "\n 6.-Buscar por ID y Mostrar resultados"
            << "\n 7.-Guardar registros de la lista en un archivo binario"
            << "\n 8.-Consultar los datos del archivo"
            << "\n 9.-Asignar préstamo de Smoking por ID"//, cambiando su estatus de alquilado, nombre de cliente, anticipo y fecha de préstamo
            << "\n10.-Recibir Smoking por ID"// y cambiando el estatus de alquilado, fecha de devolución, 
            //ajustar cantidad pagada si es necesario… es decir dejar el nodo de ese smoking listo para un siguiente préstamo.
            << "\n\033[7;33m11.-Salir\n";
        cout << "\n\033[0mDigite la opcion deseada: ";
        cin>>opc;
        if(opc>=1 && opc<=11){
            salir=1;
            return opc;
        }else{
            cout << "\033[31mOpcion NO valida\033[0m";
            cin.ignore();
            pressEnter();
        }
    }while (salir !=1);
    return 0;
}
