#include <iostream>
#include <ctime>
#include "CircularDynamicArray.cpp"

using namespace std;

int main() {

    srand(time(nullptr)); // Seed for random number generation

    CircularDynamicArray<int> arr;

    for (int i = 0; i < 500000; ++i) {
        arr.addEnd(rand() % 1000); // Adding random numbers between 0 and 999
    }

    // Testing various functions
    cout << "Array length: " << arr.length() << endl;
    cout << "Array capacity: " << arr.capacity() << endl;

    // Sorting the array
    cout << "Sorting the array..." << endl; // Add cout statement
    arr.Sort();
    cout << "Array sorted." << endl; // Add cout statement

    // Testing binary search
    int searchItem = arr[123598];
    int index = arr.binSearch(searchItem);
    if (index != -1) {
        cout << "Element " << searchItem << " found at index: " << index << endl;
    } else {
        cout << "Element " << searchItem << " not found!" << endl;
    }

    // Testing QuickSelect
    int k = 120369;
    cout << "Performing QuickSelect..." << endl; // Add cout statement
    int kthSmallest = arr.QSelect(k);
    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;

    // Deleting elements from the array
    cout << "Deleting elements from the array..." << endl; // Add cout statement
    for (int i = 0; i < 250000; ++i) { // Deleting 37500 elements to make the size 1/4 of capacity
        arr.delEnd();
    }

    cout << "Array length after deletion: " << arr.length() << endl;
    cout << "Array capacity after deletion: " << arr.capacity() << endl;

    // Clearing the array
    cout << "Clearing the array..." << endl; // Add cout statement
    arr.clear();
    cout << "Array length after clearing: " << arr.length() << endl;
    cout << "Array capacity after clearing: " << arr.capacity() << endl;

    return 0;
}
