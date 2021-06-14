#include <iostream>
#include <ctime>
#include "../headers/intro.hpp"
#include "../headers/date-time.hpp"
using namespace std;

void mostrarIntro(){
    cout << "\033[2J\033[0;0H";
    cout << "\t\t\033[1;31mProyecto Final: Sistema de Renta de Smoking\033[0m" << endl;
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
    cout << "\t\t   Presione \033[1;34menter\033[0m para entrar al sistema ";
    cin.ignore();
}

void mostrarTitle(){
    //Crear variable para obtener fecha y hora del sistema
    time_t now = time(0);
    //HACK Usar para REPL
    now = now - 18000;
    tm *ltm = localtime(&now);

    cout << "\033[2J\033[0;0H";
    cout << getDate(ltm);
    cout << "    \033[1;32mRENTA DE SMOKINGS\033[0m     ";
    cout << getTime(ltm) << endl;
}

void pressEnter(){
    cout << "\nPresione \033[1;34menter\033[0m para continuar...";
    cin.ignore();
}

int mostrarMenu(){
    int opc=0, salir=0;
    do{
        mostrarTitle();
        cout << "\n 1.\033[1;36mDar de alta un nuevo traje\033[0m"
             << "\n 2.\033[1;36mDar de baja un traje por ID\033[0m"
             << "\n 3.\033[1;36mModificar todos los datos de un Smoking\033[0m"
             << "\n 4.\033[1;36mMostrar todos los registros\033[0m"
             << "\n 5.\033[1;36mBuscar por talla y mostrar resultados\033[0m"
             << "\n 6.\033[1;36mBuscar por ID y mostrar resultados\033[0m"
             << "\n 7.\033[1;36mGuardar registros de la lista en un archivo binario \033[1;31m(NO FUNCIONAL)\033[0m"
             << "\n 8.\033[1;36mConsultar los datos del archivo \033[1;31m(NO FUNCIONAL)\033[0m"
             << "\n 9.\033[1;36mAsignar préstamo de Smoking por ID\033[0m"//, cambiando su estatus de alquilado, nombre de cliente, anticipo y fecha de préstamo
             << "\n10.\033[1;36mRecibir Smoking por ID\033[0m"// y cambiando el estatus de alquilado, fecha de devolución, 
            //ajustar cantidad pagada si es necesario… es decir dejar el nodo de ese smoking listo para un siguiente préstamo.
            << "\n11.\033[1;31mSalir\033[0m\n";
        cout << "\n\033[1;37mDigite la opcion deseada:\033[0m ";
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

int menuDatabyID(){
    int opc=0, salir=0;
    do{
        mostrarTitle();
        cout << "\n     \033[7;33m***** MODIFICAR DATOS TRAJES *****\033[0m\n"; 
        cout << "\n 1.\033[1;36mID\033[0m"
             << "\n 2.\033[1;36mTALLA\033[0m"
             << "\n 3.\033[1;36mMODELO\033[0m"
             << "\n 4.\033[1;36mMARCA\033[0m"
             << "\n 5.\033[1;36mNOMBRE CLIENTE\033[0m"
             << "\n 6.\033[1;36mDIAS PRESTAMO\033[0m"
             << "\n 7.\033[1;36mPRECIO DIARIO\033[0m"
             << "\n 8.\033[1;36mTOTAL ABONO\033[0m"
             << "\n 9.\033[1;36mFECHA ENTREGA\033[0m";
        cout << "\n\033[1;37m\nSeleccione el atributo a modificar:\033[0m ";
        cin>>opc;
        if(opc>=1 && opc<=9){
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