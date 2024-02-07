#include <array>
#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main()
{
    CircularDynamicArray<int> array1(4);

    for (int i = 0; i < 10; i++) array1.addFront(i * 2);

    for (int i = 0; i < array1.length(); i++) cout << array1[i] << " ";
    cout << endl;

    cout << "capacity: " << array1.capacity() << endl;
    cout << "size: " << array1.length() << endl;
    cout << endl;

    // cout << "linear search for item " << array1[5] << " found at index " << array1.linearSearch(10) << endl;
    // cout << "binary search for item " << array1[5] << " found at index " << array1.binSearch(10) << endl;;

    for (int i = 0; i < 6; i++) array1.delFront();

    cout << "array1: ";
    for (int i = 0; i < array1.length(); i++) cout << array1[i] << " ";
    cout << endl;

    cout << "capacity: " << array1.capacity() << endl;
    cout << "size: " << array1.length() << endl;

    // array1.clear();
    // cout << "capacity: " << array1.capacity() << endl;
    // cout << "size: " << array1.length() << endl;

    return 0;
}
