#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main()
{
    CircularDynamicArray<int> A,B;
    for(int i=0; i<10;i++) A.addEnd(i);
    B = A;

    return 0;
}
