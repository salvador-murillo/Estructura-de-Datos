#include <iostream>
#include <string.h>
#include <ctime>
#include "../headers/date-time.hpp"
using namespace std;

int day(tm *ltm){
    return ltm->tm_mday;  
}

int month(tm *ltm){
    return 1 + ltm->tm_mon;
}

int year(tm *ltm){
    return 1900 + ltm->tm_year;
}

int hour(tm *ltm){
    return ltm->tm_hour;
}

int minutes(tm *ltm){
    return ltm->tm_min;
}

int seconds(tm *ltm){
    return ltm->tm_sec;
}

string getDate(tm *ltm){
    string fecha = "\033[1;37m"; //Negritas Color Blanco
    (day(ltm)<10) ? fecha = fecha + "0" + to_string(day(ltm)) + "/" : fecha = fecha + to_string(day(ltm)) + "/";
    (month(ltm)<10) ? fecha = fecha + "0" + to_string(month(ltm)) + "/" : fecha =  fecha + to_string(month(ltm)) + "/";
    fecha = fecha + to_string(year(ltm)) + "\033[0m";
    return fecha;
}

string getTime(tm *ltm){
    string time = "\033[1;37m"; //Negritas Color Blanco
    hour(ltm)<10 ? time = time + "0" + to_string(hour(ltm)) : time = time + to_string(hour(ltm)); 
    time = time + ":";
    minutes(ltm)<10 ? time = time + "0" + to_string(minutes(ltm)) : time = time + to_string(minutes(ltm));
    // time = time + ":";
    // seconds(ltm)<10 ? time = time + "0" + to_string(seconds(ltm)) : time = time +  to_string(seconds(ltm)); 
    time = time + "\033[0m";
    return time;
}

void returnDate(int &diaFecha, int &mesFecha, int &anioFecha){
    //25/4
    if(mesFecha==4 || mesFecha==6 || mesFecha==9 || mesFecha==11)
    {
        //dia max 30
        if(diaFecha>=31){
            diaFecha = diaFecha - 30;
            mesFecha = mesFecha + 1;
        }
    }
    else if (mesFecha==2)
    {
        //dia max 28
        if(diaFecha>=29){
            diaFecha = diaFecha - 29;
            mesFecha = mesFecha + 1;
        }
    }
    else if(mesFecha==12)
    {
        //dia max 31
        if(diaFecha>31){
            diaFecha = diaFecha - 31;
            mesFecha = 1;
            anioFecha = anioFecha + 1;
        }
    }else
    {
        //dia max 31
        if(diaFecha>31){
            diaFecha = diaFecha - 31;
            mesFecha = mesFecha+1;
        }
    }
}

void validDate(int &diaFecha, int &mesFecha, int &anioFecha){    
    int dia = diaFecha, mes = mesFecha, anio = anioFecha;
    int opcAnio = 0, opcMes = 0, opcDia = 0;

    while (opcAnio==0)
    {

        cout << "\n\033[1;37mAnio de entrega: \033[0m";
        cin >> anioFecha;
        if(anioFecha==anio)
        {
            while(opcMes==0)
            {
                cout << "\n\033[1;37mMes de entrega: \033[0m";
                cin >> mesFecha;
                if(mesFecha>=mes && mesFecha<=12)
                {
                    opcMes=1;
                    while(opcDia==0)
                    {
                        cout << "\n\033[1;37mDia de entrega: \033[0m";
                        cin >> diaFecha;
                        if(mesFecha==mes)
                        {
                            if(diaFecha<dia)
                            {
                                cout << "\n\033[1;31mNOTA!\033[0m El dia debe de ser igual o mayor al actual ("<< dia << ")" << endl;
                            }
                            else if((mesFecha==1 || mesFecha==3 || mesFecha==5 || mesFecha==7 || mesFecha==8 || mesFecha==10 || mesFecha==12) && (diaFecha>=0 && diaFecha<=31))
                            {
                                opcAnio=1;
                                opcDia=1;
                            }
                            else if((mesFecha==4 || mesFecha==6 || mesFecha==9 || mesFecha==11) && (diaFecha>=0 && diaFecha<=30))
                            {
                                opcAnio=1;
                                opcDia=1;
                            }
                            else if((mesFecha==2) && (diaFecha>=0 && diaFecha<=28))
                            {
                                opcDia=1;
                                opcAnio=1; 
                            }else
                                cout << "\n\033[1;31mNOTA!\033[0m El dia ingresado no es valido para el mes seleccionado (" << mesFecha << "/" << anioFecha << ")" << endl; 
                        }
                    }
                }
                else
                    cout << "\n\033[1;31mNOTA!\033[0m Mes no valido, debe de ser mayor o igual al actual (" << mes << ")" << endl;
            }
        }
        else if(anioFecha>anio && anioFecha<2051)
        {
            while(opcMes==0)
            {
                cout << "\n\033[1;37mMes de entrega: \033[0m";
                cin >> mesFecha;
                if(mesFecha>=1 && mesFecha<=12)
                {
                    opcMes=1;
                    while(opcDia==0)
                    {
                        cout << "\n\033[1;37mDia de entrega: \033[0m";
                        cin >> diaFecha;
                        if((mesFecha==1 || mesFecha==3 || mesFecha==5 || mesFecha==7 || mesFecha==8 || mesFecha==10 || mesFecha==12) && (diaFecha>=0 && diaFecha<=31))
                        {
                            opcDia=1;
                            opcAnio=1; 
                        }
                        else if((mesFecha==4 || mesFecha==6 || mesFecha==9 || mesFecha==11) && (diaFecha>=0 && diaFecha<=30))
                        {
                            opcDia=1;
                            opcAnio=1;   
                        }
                        else if((mesFecha==2) && (diaFecha>=0 && diaFecha<=28))
                        {
                            opcDia=1;
                            opcAnio=1; 
                        }else
                            cout << "\n\033[1;31mNOTA!\033[0m El dia ingresado no es valido para el mes seleccionado (" << mesFecha << "/" << anioFecha << ")" << endl; 
                    }
                }
                else
                    cout << "\n\033[1;31mNOTA!\033[0m Mes no valido, eliga entre 1 y 12" << endl;
            }
        }
        else
        {
            cout << "\n\033[1;31mNOTA!\033[0m El anio debe de ser igual o mayor al actual ("<< anio << ") max 2050" << endl;
        }
    }
}