/*
Youtube: mycodeschool Pointers in c/c++
Link: http://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_
*/
#include <iostream>
#include <string.h>
using namespace std;

void print(char* f){ //Receives as argument the initial address of f in the main function

    //We can ommit the letter i to iterate our while loop and use the pointer f
    // int i=0;
    while (*f!='\0') //Use *f instead of f[i]      
    {
        cout << *f << " ";
        f++; //Use of f instead of i
    }
    cout << endl;
}

int main() {
  cout << "\033[2J\033[0;0H";

  char a[4];
  a[0] = 'J';
  a[1] = 'H';
  a[2] = 'O';
  a[3] = 'N';  
  
  cout << a << endl; //This it will print garbage after 'N' because we do not terminate with a value Null.

  char d[5]; 
  d[0] = 'J';
  d[1] = 'H';
  d[2] = 'O';
  d[3] = 'N';
  d[4] = '\0'; //NULL value, it doesn't matter if we have a large size of array if we store '\0' the sentence will finish there.

  cout << d << endl; //This only prints d from index 0 to 3.


  //A character array defined always need to be declared at the same line
  char e[] = "JOHN"; //String literal, Here the '\0' null value is implicity, we do not need to write. (Size 5)
//   char e1[4]= "JOHN"; //This is wrong because we need the extra space for the null value.

  cout << "Size in bytes C= " << sizeof(e) << endl;
  int len = strlen(e);
  cout << "Length C= " << len << endl;

  //2.Arrays and pointers are different types that are used in similar manner

  char c1[6] = "Hello";
  char* c2;
  c2 = c1; //This is valid, using the name of the array returns the address of the first element of the array.

  cout << c2[1] << endl; //e
  c2[0]= 'A'; // c2[i] is *(c2+1) // c1[i] or *(c1+i)
  cout << c1 << endl;
  //3.Arrays are always passed to function by reference

  char f[20]="Hello";
  print(f); //We create an special print function to check how it works

}