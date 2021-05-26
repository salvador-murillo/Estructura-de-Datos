/*
CUCEA | Estructura de Datos | Salvador Murillo Arias
Test: Para depuracion de fragmentos de codigo
*/
#include <iostream>
#include <ctime>
using namespace std;

int main(){
   int hr, min, sec;
    cout << "\033[2J\033[0;0H";
    cout << "PRUEBAS" << endl;
   // current date/time based on current system
   time_t now = time(0);

   cout << "Number of sec since January 1,1970 is:: " << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<< ltm->tm_mday << endl;
   
   hr = -5+ltm->tm_hour;
   (hr<10) ? cout << "Time: 0" : cout << "Time: ";
   cout << hr << ":";
   
   min = ltm->tm_min;
   (min<10) ? cout << "0" : cout << "";
   cout << min << ":";
   
   sec = ltm->tm_sec;
   (sec<10) ? cout << "0" : cout << "";
   cout << sec << endl;
}