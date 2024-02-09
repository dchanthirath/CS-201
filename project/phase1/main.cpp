#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main()
{
    // CircularDynamicArray<int> array1(4);

    // // 22 20 18 16 14 12 10 8 6 4 2 0
    // for (int i = 0; i < 12; i++) {
    //     array1.addFront(i * 2);
    // }
    // // print the array
    // cout << "array1: ";
    // for (int i = 0; i < array1.length(); i++) {
    //     cout << array1[i] << " ";
    // }
    // cout << endl;
    // // showing capacity and size
    // cout << "capacity: " << array1.capacity() << endl;
    // cout << "size: " << array1.length() << endl;

    // // deleting front
    // // 22 20 18 16 14 12 10 8 6 4 2 0
    // for (int i = 0; i < 8; i++) {
    //     array1.delFront();
    // }
    // // print
    // cout << "array1: ";
    // for (int i = 0; i < array1.length(); i++) {
    //     cout << array1[i] << " ";
    // }
    // cout << endl;
    // // showing capacity and size
    // cout << "capacity: " << array1.capacity() << endl;
    // cout << "size: " << array1.length() << endl;


    // CircularDynamicArray<int> array2;

    // // 22 20 18 16 14 12 10 8 6 4 2 0
    // for (int i = 0; i < 11; i++) {
    //     array2.addEnd(i * 3);
    // }
    // // print the array
    // cout << "array2: ";
    // for (int i = 0; i < array2.length(); i++) {
    //     cout << array2[i] << " ";
    // }
    // cout << endl;
    // // showing capacity and size
    // cout << "capacity: " << array2.capacity() << endl;
    // cout << "size: " << array2.length() << endl;

    // // deleting front
    // // 22 20 18 16 14 12 10 8 6 4 2 0
    // for (int i = 0; i < 7; i++) {
    //     array2.delEnd();
    // }
    // // print
    // cout << "array2: ";
    // for (int i = 0; i < array2.length(); i++) {
    //     cout << array2[i] << " ";
    // }
    // cout << endl;
    // // showing capacity and size
    // cout << "capacity: " << array2.capacity() << endl;
    // cout << "size: " << array2.length() << endl;

    CircularDynamicArray<int> array3;
    for (int i = 0; i < 6; i++)
        array3.addFront(rand() % 10);

    cout << "array3: ";
    for (int i = 0; i < array3.length(); i++) {
        cout << array3[i] << " ";
    }
    cout << endl;

    int k = 3;
    cout << "kth (" << k << ") smallest element: " << array3.QSelection(k) << endl;

    return 0;
}
