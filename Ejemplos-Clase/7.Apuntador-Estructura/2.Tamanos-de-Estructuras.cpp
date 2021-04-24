#include<iostream>
// #include<conio.h>
using namespace std;

 struct art1{
     char c1;
     double d;
     char c2;
     int i;

}reg, *ptrReg = &reg;

struct art2{
     double d;
     char c1;
     char c2;
     int i;

}reg2, *ptrReg2 = &reg2;



int main(){
    setlocale(LC_ALL, "spanish");

    ptrReg = (art1 *) malloc(sizeof(art1));
    ptrReg2 = new(art2);


    cout<<"Tama�o de la estructura 1: "<<sizeof(art1)<<endl;
    cout<<"Tama�o de la estructura 2: "<<sizeof(art2)<<endl;

    cout<<"\nDIrecci�n C1: "<<(int *)&ptrReg->c1<<"\ndirecci�n d: "<<&ptrReg->d<<"\ndireccion c2: "<<(int *)&ptrReg->c2<<"\ndirecci�n i: "<<&ptrReg->i<<endl<<endl;
    cout<<"================================================================================================"<<endl;
    cout<<"\ndirecci�n d: "<<&ptrReg2->d<<"\nDIrecci�n C1: "<<(int *)&ptrReg2->c1<<"\ndireccion c2: "<<(int *)&ptrReg2->c2<<"\ndirecci�n i: "<<&ptrReg2->i<<endl<<endl;

}



