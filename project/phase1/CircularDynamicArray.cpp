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

    // clion suggested this (C++17)
    [[nodiscard]] int length() const;
    [[nodiscard]] int capacity() const;
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
    // TODO: delete arr, just modift array in private
    static int partition(int arr[], int l, int r)
    {
        int x = arr[r], i = l;
        // TODO: shift front index
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
        std::swap(arr[i], arr[r]);
        return i;
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {
        // If k is smaller than number of
        // elements in array
        if (k > 0 && k <= r - l + 1) {

            // Partition the array around last
            // element and get position of pivot
            // element in sorted array
            const int index = partition(arr, l, r);

            // If position is same as k
            if (index - l == k - 1)
                return arr[index];

            // If position is more, recur
            // for left subarray
            if (index - l > k - 1)
                return kthSmallest(arr, l, index - 1, k);

            // Else recur for right subarray
            return kthSmallest(arr, index + 1, r,
                                k - index + l - 1);
        }

        // If k is more than number of
        // elements in array
        return size;
    }
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
    if (this != rhs)
    {
        // allocate new memory and copy elements
        elmtype* new_array = new elmtype[rhs.capacitySize];
        for (int i = 0; i < rhs.size; i++)
            array[i] = rhs.array[i];

        // deallocate old memory
        delete[] array;

        // allocate new memory
        array = new_array;

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
    array[size] = v;
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
    array = new int[capacitySize = 2];
    size = front = 0;
}

template <typename elmtype>
elmtype CircularDynamicArray<elmtype>::QSelection(int k) {
    // returns the kth smallest element in the array using the quickselect algorithm.
    // This method should choose a pivot element at random.

    // TODO: need to adjust for array wrapping
    // should be the front;
    int left = (front + capacitySize) % capacitySize;
    // should be the back;
    int right = size % capacitySize;

    return kthSmallest(array, left, right, k);
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
    for (int i = 0; i < size; i++) if (array[i] == e) return i;

    return -1;
}

template <typename elmtype>
int CircularDynamicArray<elmtype>::binSearch(elmtype e) {
    // Performs a binary search of the array looking for the item e.
    // Returns the index of the item if found or -1 otherwise.
    // This method assumes that the array is in increasing order, but there is no guarantee that the sort method has been called.
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        const int mid = (left + right) / 2;
        if (array[mid] == e) return mid;

        if (array[mid] < e) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}
