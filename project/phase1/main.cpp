#include <array>
#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main()
{
    CircularDynamicArray<int> array1;

    for (int i = 0; i < 14; i++) array1.addFront(i * 2);
    // the array
    for (int i = 0; i < 14; i++) cout << array1[i] << " ";
    cout << endl;

    cout << "capacity: " << array1.capacity() << endl;
    cout << "size: " << array1.length() << endl;

    cout << "linear search for item " << array1[13] << " found at index " << array1.linearSearch(26) << endl;
    cout << "binary search for item " << array1[13] << " found at index " << array1.binSearch(26) << endl;;

    // cout << array1.binSearch(83) << endl;
    array1.clear();

    return 0;
}
