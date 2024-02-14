#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

void foo(CircularDynamicArray<int> x) {
    // x => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"
    for (int i=0; i<x.length()/2; i++)
        x[i] = x[x.length()/2+i];
    // x => "6 7 8 9 10 15 19 6 7 8 9 10 15 19 11"
    for (int i=0; i< x.length();i++) cout << x[i] << " ";  cout << endl;
}

int main()
{
    CircularDynamicArray<int> A;

    A.addFront(12);
    A.addFront(15);
    A.addFront(19);
    A.addFront(17);
    A.addFront(11);

    cout << "A: ";
    for (int i = 0; i < A.length(); i++) cout << A[i] << " "; cout << endl;

    A.delFront();
    A.delFront();

    cout << "A: ";
    for (int i = 0; i < A.length(); i++) cout << A[i] << " "; cout << endl;

    return 0;
}
