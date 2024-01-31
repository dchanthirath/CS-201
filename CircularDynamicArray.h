//
// Created by Donald on 1/29/2024.
//

#ifndef CIRCULARDYNAMICARRAY_H
#define CIRCULARDYNAMICARRAY_H



class CircularDynamicArray {
public:
    CircularDynamicArray();
    CircularDynamicArray(int s);
    ~CircularDynamicArray();

    elmtype& operator[](int i);
    void addEnd(elmtype v);
    void addFront(elmtype v);
    void delEnd();
    void delFront();

    int length();
    int capacity();
    void clear();

    Elmtype QSelection(int k);
    void sort();
    int linearSearch(elmtype e);
    int binSearch(elmtype e);

private:
    int size, capacitySize;
    int *a;

};



#endif //CIRCULARDYNAMICARRAY_H
