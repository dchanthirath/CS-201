//
// Created by Donald on 1/29/2024.
//

#include "CircularDynamicArray.h"

CircularDynamicArray::CircularDynamicArray() {
    // Default Constructor.
    // The array should be of capacity 2 and size 0
    capacitySize = 2;
    size = 0;
    a = new int[capacitySize]

}

CircularDynamicArray::CircularDynamicArray(int s) {
    // For this constructor the array should be of capacity and size s
    capacitySize = s;
    size = s;
    a = new int[capacitySize]

}

CircularDynamicArray::~CircularDynamicArray() {
    // destructor for the class
    delete[] a;

}

elmtype& CircularDynamicArray::operator[](int i) {
    // Traditional [] operator.
    // Should print a message if i is out of bounds and
    // return a reference to value of type elmtype stored in the class for this purpose

}
void CircularDynamicArray::addEnd(elmtype v) {
    // increases the size of the array by 1 and stores v at the end of the array.
    // Should double the capacity when the new element doesn't fit.

}
void CircularDynamicArray::addFront(elmtype v) {
    // increases the size of the array by 1 and stores v at the beginning of the array.
    // Should double the capacity when the new element doesn't fit.
    // The new element should be the item returned at index 0.

}

void CircularDynamicArray::delEnd() {
    // reduces the size of the array by 1 at the end.
    // Should shrink the capacity when only 25% of the array is in use after the delete.
    size--;
    if (capacitySize >= (size / 4))
    {
        size /= 2;
        //FIXME: make a new array and insert old values into new array
    }

}

void CircularDynamicArray::delFront() {
    // reduces the size of the array by 1 at the beginning of the array.
    // Should shrink the capacity when only 25% of the array is in use after the delete.
    size--;
    if (capacitySize >= (size / 4))
    {
        size /= 2;

        // FIXME: make new array and insert old values into that
    }

}

int CircularDynamicArray::length() {
    // returns the size of the array
    return size;

}

int CircularDynamicArray::capacity() {
    // returns the capacity of the array
    return capacitySize;

}
void CircularDynamicArray::clear() {
    // Frees any space currently used and starts over with an array of capacity 2 and size 0

}

Elmtype CircularDynamicArray::QSelection(int k) {
    // returns the kth smallest element in the array using the quickselect algorithm.
    // This method should choose a pivot element at random.

}

void CircularDynamicArray::sort() {
    // Sorts the values in the array using a comparison based O(N lg N) algorithm.
    // The sort must be stable.

}

int CircularDynamicArray::linearSearch(elmtype e) {
    // Performs a linear search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.

}

int CircularDynamicArray::binSearch(elmtype e) {
    // Performs a binary search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.
    // This method assumes that the array is in increasing order, but there is no guarantee that the sort method has been called.

}
