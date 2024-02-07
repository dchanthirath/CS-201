#include <array>
#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main()
{
    CircularDynamicArray<int> array1(4);

    for (int i = 0; i < 12; i++) {
        array1.addFront(i * 2);
    }

    cout << "array1: ";
    for (int i = 0; i < array1.length(); i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    cout << "capacity: " << array1.capacity() << endl;
    cout << "size: " << array1.length() << endl;

    return 0;
}
