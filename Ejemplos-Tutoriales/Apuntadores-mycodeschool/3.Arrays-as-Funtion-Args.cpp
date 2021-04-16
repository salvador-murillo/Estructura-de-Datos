/*
Youtube: mycodeschool Pointers in c/c++
Link: http://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_
*/
#include <iostream>
using namespace std;

//Arrays always pass as a reference putting int A[] is equal to int* A, Just copy the address of the first element of the array
int SumOfElements(int* A, int size){ 
    int i, sum=0;
    for(i=0; i<size; i++){
        sum+=A[i]; //A[i] is *(A+i)
    }
    return sum;
}

//Passing array as reference it allow us to modify its values in the main function
void doubleValues(int* A, int size){
    int i=0;
    for(i=0; i<size; i++){
        A[i]=2*A[i];
    }
}

int main() {
    cout << "\033[2J\033[0;0H";

    int A[]={1,2,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);
    cout << "\nValue sizeof A= " << sizeof(A) << " | Value sizeof A[0]= " << sizeof(A[0]);
    int total = SumOfElements(A, size);
    cout << "\nSum of elements A= "<< total << endl;

    doubleValues(A,size);
    //Show array A modify by function doubleValues
    for(int i=0; i<size; i++){
        cout << A[i] << " ";
    }
}