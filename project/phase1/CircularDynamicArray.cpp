//
// Created by Donald on 1/29/2024.
//

template <typename elmtype>
class CircularDynamicArray {
public:
    CircularDynamicArray();
    explicit CircularDynamicArray(int s);
    ~CircularDynamicArray();

    elmtype& operator[](int i);
    void addEnd(elmtype v);
    void addFront(elmtype v);
    void delEnd();
    void delFront();

    int length();
    int capacity();
    void clear();

    elmtype QSelection(int k);
    void sort();
    int linearSearch(elmtype e);
    int binSearch(elmtype e);

private:
    int size, capacitySize, front, back;
    int *array;

};

template <typename elmtype>
CircularDynamicArray<elmtype>::CircularDynamicArray() {
    // Default Constructor.
    // The array should be of capacity 2 and size 0
    array = new elmtype[capacitySize = 2];
    size = front = back = 0;

}

template <typename elmtype>
CircularDynamicArray<elmtype>::CircularDynamicArray(int s) {
    // For this constructor the array should be of capacity and size s
    array = new elmtype[capacitySize = s];
    size = s;
    front = back = 0;

}

template <typename elmtype>
CircularDynamicArray<elmtype>::~CircularDynamicArray() {
    // destructor for the class
    delete[] array;

}

template <typename elmtype>
elmtype& CircularDynamicArray<elmtype>::operator[](int i) {
    // Traditional [] operator.
    // Should print a message if i is out of bounds and
    // return a reference to value of type elmtype stored in the class for this purpose
    // TODO: implement this function tomorrow :)
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::addEnd(elmtype v) {
    // increases the size of the array by 1 and stores v at the end of the array.
    // Should double the capacity when the new element doesn't fit.
    if (size == capacitySize) capacitySize *= 2;
    size++;
    // TODO: implement the end part of this function

}

template <typename elmtype>
void CircularDynamicArray<elmtype>::addFront(elmtype v) {
    // increases the size of the array by 1 and stores v at the beginning of the array.
    // Should double the capacity when the new element doesn't fit.
    // The new element should be the item returned at index 0.
    if (size == capacitySize) capacitySize *= 2;
    size++;

    // TODO:: implement the front part of this function
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::delEnd() {
    // reduces the size of the array by 1 at the end.
    // Should shrink the capacity when only 25% of the array is in use after the delete.
    if (size <= (capacitySize / 4)) capacitySize /= 2;
    size--;

}

template <typename elmtype>
void CircularDynamicArray<elmtype>::delFront() {
    // reduces the size of the array by 1 at the beginning of the array.
    // Should shrink the capacity when only 25% of the array is in use after the delete.
    if (size <= (capacitySize / 4)) capacitySize /= 2;
    size--;

}

template <typename elmtype>
int CircularDynamicArray<elmtype>::length() {
    // returns the size of the array
    return size;

}

template <typename elmtype>
int CircularDynamicArray<elmtype>::capacity() {
    // returns the capacity of the array
    return capacitySize;

}

template <typename elmtype>
void CircularDynamicArray<elmtype>::clear() {
    // Frees any space currently used and starts over with an array of capacity 2 and size 0

    delete[] array;
    array = new int[capacitySize = 2];
    size = 0;
}

template <typename elmtype>
elmtype CircularDynamicArray<elmtype>::QSelection(int k) {
    // returns the kth smallest element in the array using the quickselect algorithm.
    // This method should choose a pivot element at random.

}

template <typename elmtype>
void CircularDynamicArray<elmtype>::sort() {
    // Sorts the values in the array using a comparison based O(N lg N) algorithm.
    // The sort must be stable.

}

template <typename elmtype>
int CircularDynamicArray<elmtype>::linearSearch(elmtype e) {
    // Performs a linear search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.
    for (int i = 0; i < size; i++) if (array[i] == e) return e;

    return -1;
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::binSearch(elmtype e) {
    // Performs a binary search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.
    // This method assumes that the array is in increasing order, but there is no guarantee that the sort method has been called.
    int low = 0;
    int high = size;
    int mid = (high + low) / 2;
    // TODO: finish implementing this function
    if (array[mid] < e)
    {
        return CircularDynamicArray
    }

    return -1;
}
