//
// Created by Donald on 1/29/2024.
//
#include <iostream>

template <typename elmtype>
class CircularDynamicArray {
public:
    CircularDynamicArray();
    explicit CircularDynamicArray(int s);
    // rule of three
    ~CircularDynamicArray();
    CircularDynamicArray(const CircularDynamicArray &old);
    CircularDynamicArray& operator=(const CircularDynamicArray& rhs);

    elmtype& operator[](int i);

    void addEnd(elmtype v);
    void addFront(elmtype v);
    void delEnd();
    void delFront();

    int length() const;
    int capacity() const;
    void clear();

    elmtype QSelection(int k);
    void sort();

    int linearSearch(elmtype e);
    int binSearch(elmtype e);

private:
    int size, capacitySize, front;
    elmtype *array;
    elmtype error;

    // helper functions
    // for quick select
    int partition(int l, int r);
    int kthSmallest(int l, int r, int k);

    void merge(int left, int mid, int right);
    void mergeSort(int begin, int end);
};

template <typename elmtype>
CircularDynamicArray<elmtype>::CircularDynamicArray() {
    // Default Constructor.
    // The array should be of capacity 2 and size 0
    array = new elmtype[capacitySize = 2];
    size = front = 0;
}

template <typename elmtype>
CircularDynamicArray<elmtype>::CircularDynamicArray(int s) {
    // For this constructor the array should be of capacity and size s
    array = new elmtype[capacitySize = s];
    size = s;
    front = 0;
}

template <typename elmtype>
CircularDynamicArray<elmtype>::~CircularDynamicArray() {
    // destructor for the class
    delete[] array;
}

template <typename elmtype>
CircularDynamicArray<elmtype>::CircularDynamicArray(const CircularDynamicArray& old)
{
    // copy constructor
    // makes a deep copy of the CircularDynamicArray ref
    // named old into current object

    // allocate new memory and copy elements
    array = new elmtype[old.capacitySize];
    for (int i = 0; i < old.size; i++)
        array[i] = old.array[i];

    // reallocating memory
    capacitySize = old.capacitySize;
    size = old.size;
    front = old.front;
}

template <typename elmtype>
CircularDynamicArray<elmtype>& CircularDynamicArray<elmtype>::operator=(const CircularDynamicArray& rhs)
{
    // copy assignment operator
    if (this != &rhs)
    {
        // allocate new memory and copy elements
        elmtype* newArray = new elmtype[rhs.capacitySize];
        for (int i = 0; i < rhs.size; i++)
            newArray[i] = rhs.array[i];

        // deallocate old memory
        delete[] array;

        // allocate new memory
        array = newArray;

        capacitySize = rhs.capacitySize;
        size = rhs.size;
        front = rhs.front;
    }

    // by convention always return *this
    return *this;
}

template <typename elmtype>
elmtype& CircularDynamicArray<elmtype>::operator[](int i)
{
    // Traditional [] operator.
    // Should print a message if i is out of bounds and
    // return a reference to value of type elmtype stored in the class for this purpose
    if (i < 0 || i >= size) {
        std::cout << "i is out of bounds" << std::endl;
        return error;
    }

    return array[(front + i) % capacitySize];
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::addEnd(elmtype v) {
    // increases the size of the array by 1 and stores v at the end of the array.
    // Should double the capacity when the new element doesn't fit.

    // adding 'v' to the end of the array
    int back = (front + size) % capacitySize; // wrap around for addEnd
    array[back] = v;
    size++;

    // if full
    if (size == capacitySize)
    {
        // allocate new memory and copying elements
        elmtype* temp = new elmtype[capacitySize * 2];
        for (int i = 0; i < size; i++) // assigning elements from beginning of temp
            temp[i] = array[(front + i) % capacitySize];
        // deallocating old array
        delete[] array;
        // allocating new memeory
        array = temp;

        capacitySize *= 2;
        front = 0;
    }
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::addFront(elmtype v)
{
    // increases the size of the array by 1 and stores v at the beginning of the array.
    // Should double the capacity when the new element doesn't fit.
    // The new element should be the item returned at index 0.
    front = (front + capacitySize - 1) % capacitySize;
    array[front] = v;
    size++;
    // maybe there is something wrong here???
    if (size == capacitySize)
    {
        // allocating new memory and copying elements
        elmtype* temp = new elmtype[capacitySize * 2];
        for (int i = 0; i < size; i++)
            temp[i] = array[(front + i) % capacitySize];
        // deallocating memory
        delete[] array;
        // reallocating memory
        array = temp;

        capacitySize *= 2;
        front = 0;
    }
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::delEnd() {
    // reduces the size of the array by 1 at the end.
    // Should shrink the capacity when only 25% of the array is in use after the delete.
    size--;

    if (size == (capacitySize / 4))
    {
        // allocating new memory and copying elements
        elmtype* temp = new elmtype[capacitySize / 2];
        for (int i = 0; i < size; i++)
            temp[i] = array[(front + i) % capacitySize];
        // deallocating memory
        delete[] array;
        // reallocating memory
        array = temp;

        capacitySize /= 2;
        front = 0;
    }
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::delFront() {
    // reduces the size of the array by 1 at the beginning of the array.
    // Should shrink the capacity when only 25% of the array is in use after the delete.

    front = (front + 1) % capacitySize; // moves front to next element
    size--;

    if (size == (capacitySize / 4))
    {
        // allocating new memory and copying elements
        elmtype* temp = new elmtype[capacitySize / 2];
        for (int i = 0; i < size; i++)
            temp[i] = array[(front + i) % capacitySize];
        // deallocating memory
        delete[] array;
        // reallocating memory
        array = temp;

        capacitySize /= 2;
        front = 0;
    }
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::length() const
{
    // returns the size of the array
    return size;
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::capacity() const
{
    // returns the capacity of the array
    return capacitySize;
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::clear() {
    // Frees any space currently used and starts over with an array of capacity 2 and size 0

    delete[] array;
    array = new elmtype[capacitySize = 2];
    size = front = 0;
}

template<typename elmtype>
int CircularDynamicArray<elmtype>::partition(int l, int r)
{
    elmtype x = array[r];
    int i = l;
    for (int j = l; j <= r - 1; j++) {
        if (array[j] <= x) {
            std::swap(array[i], array[j]);
            i++;
        }
    }
    std::swap(array[i], array[r]);
    return i;
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::kthSmallest(int l, int r, int k)
{
    // If k is smaller than number of
    // elements in array
    if (k > 0 && k <= r - l + 1) {

        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        const int index = partition(l, r);

        // If position is same as k
        if (index == (l + k - 1))
            return array[index];

        // If position is more, recur
        // for left subarray
        if (index < (l + k - 1))
            return kthSmallest(index + 1, r, k - index + l - 1);

        // Else recur for right subarray
        return kthSmallest(l, index - 1, k);
    }

    // If k is more than number of
    // elements in array
    return size;
}

template <typename elmtype>
elmtype CircularDynamicArray<elmtype>::QSelection(int k) {
    // returns the kth smallest element in the array using the quickselect algorithm.
    // This method should choose a pivot element at random.

    // should be the front;
    // int left = front;
    int left = 0;
    // should be the back;
    // int right = (front + size - 1) % size;
    int right = size - 2;

    return kthSmallest(left, right, k);
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::merge(int left, int mid, int right)
{
    // Merges two subarrays of array[].
    // First subarray is arr[begin..mid]
    // Second subarray is arr[mid+1..end]
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    elmtype *leftArray = new elmtype[subArrayOne],
         *rightArray = new elmtype[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[(left + i) % capacitySize];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[(mid + 1 + j) % capacitySize];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            // array[(indexOfMergedArray + indexOfSubArrayOne) % capacitySize] = leftArray[indexOfSubArrayOne];
            array[(indexOfMergedArray + front) % capacitySize] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            // array[(indexOfMergedArray + indexOfSubArrayTwo) % capacitySize] = rightArray[indexOfSubArrayTwo];
            array[(indexOfMergedArray + front) % capacitySize] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        // && (indexOfMergedArray + indexOfSubArrayOne) % capacitySize < capacitySize) {
        // array[(indexOfMergedArray + indexOfSubArrayOne) % capacitySize] = leftArray[indexOfSubArrayOne];
        array[(indexOfMergedArray + front) % capacitySize] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        // && (indexOfMergedArray + indexOfSubArrayTwo) % capacitySize < capacitySize) {
        // array[(indexOfMergedArray + indexOfSubArrayTwo) % capacitySize] = rightArray[indexOfSubArrayTwo];
        array[(indexOfMergedArray + front) % capacitySize] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::mergeSort(int begin, int end)
{
    // begin is for left index and end is right index
    // of the sub-array of arr to be sorted
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(begin, mid);
        mergeSort(mid + 1, end);
        merge(begin, mid, end);
    }
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::sort() {
    // Sorts the values in the array using a comparison based O(N lg N) algorithm.
    // The sort must be stable.

    // trying merge sort instead
    mergeSort(front, (front + size - 1) % capacitySize);
    // std::cout << "CDA array: ";
    // for (int i = 0; i < size; i++) std::cout << array[i] << " "; std::cout << std::endl;
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::linearSearch(elmtype e) {
    // Performs a linear search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.

    for (int i = 0; i < size; i++)
        // the index to indicate front everytime
        if (array[(front + i) % capacitySize] == e) return i;

    return -1;
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::binSearch(elmtype e) {
    // Performs a binary search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.
    // This method assumes that the array is in increasing order, but there is no guarantee that the sort method has been called.
    int left = 0;
    int right = size - 1;

    // TODO: adjust for wrap around
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (array[mid] == e)
            return mid;

        if (array[mid] < e)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
