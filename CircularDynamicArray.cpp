//
// Created by Donald on 1/29/2024.
//

#include "CircularDynamicArray.h"

CircularDynamicArray() {
    // Default Constructor.
    //The array should be of capacity 2 and size 0

}

CircularDynamicArray(int s) {
    // For this constructor the array should be of capacity and size s

}

~CircularDynamicArray() {
    // destructor for the class

}

elmtype& operator[](int i) {
    // Traditional [] operator.
    // Should print a message if i is out of bounds and
    // return a reference to value of type elmtype stored in the class for this purpose

}
void addEnd(elmtype v) {
    // increases the size of the array by 1 and stores v at the end of the array.
    // Should double the capacity when the new element doesn't fit.

}
void addFront(elmtype v) {
    // increases the size of the array by 1 and stores v at the beginning of the array.
    // Should double the capacity when the new element doesn't fit.
    // The new element should be the item returned at index 0.

}

void delEnd() {
    // reduces the size of the array by 1 at the end.
    // Should shrink the capacity when only 25% of the array is in use after the delete.

}

void delFront() {
    // reduces the size of the array by 1 at the beginning of the array.
    // Should shrink the capacity when only 25% of the array is in use after the delete.

}

int length() {
    // returns the size of the array

}

int capacity() {
    // returns the capacity of the array

}
void clear() {
    // Frees any space currently used and starts over with an array of capacity 2 and size 0

}

Elmtype QSelection(int k) {
    // returns the kth smallest element in the array using the quickselect algorithm.
    // This method should choose a pivot element at random.

}

void sort() {
    // Sorts the values in the array using a comparison based O(N lg N) algorithm.
    // The sort must be stable.

}

int linearSearch(elmtype e) {
    // Performs a linear search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.

}

int binSearch(elmtype e) {
    // Performs a binary search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.
    // This method assumes that the array is in increasing order, but there is no guarantee that the sort method has been called.

}
