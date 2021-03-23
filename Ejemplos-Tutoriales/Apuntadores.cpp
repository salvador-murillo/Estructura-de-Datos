#include <iostream>
#include <string>

using namespace std;

int main(){
    string saludo = "hola";
    string *p;
    p = &saludo;
    cout << &saludo << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << saludo << endl;

    return 0;
}
