#include <iostream>

template <typename T>
class Queue {
public:
    Queue();
    Queue(int s);

    // void enqueue(int x);
    void enqueue(const T& x);
    // int dequeue();
    T dequeue();

    ~Queue();
    Queue(const Queue &old);
    Queue& operator=(const Queue& rhs);

private:
    int size, capacity, front;
    // int *a;
    T *a;
};

// had to move everything from the .cpp file
// because i had to instantiate templates :)

template <typename T>
Queue<T>::Queue()
{
    // default constructor
    // the array should be of capacity 10 and size 0

    // a = new int[capacity = 10];
    a = new T[capacity = 10];
    size = front = 0;
}

template <typename T>
Queue<T>::Queue(int s)
{
    // array should be of capacity s and size 0

    // a = new int[capacity = s];
    a = new T[capacity = s];
    size = front = 0;
}


// void Queue::enqueue(int x)
template <typename T>
void Queue<T>::enqueue(const T& x)
{
    // insert the item x to the back of the queue

    a[size] = x;
    size++;
}

// int Queue::dequeue()
template <typename T>
T Queue<T>::dequeue()
{
    // remove and return the item from the front of the queue

    // lab solution
    // const int spot = front;
    const T spot = front;
    front = (front + 1) % capacity;
    size--;

    return a[spot];
}

template <typename T>
Queue<T>::~Queue()
{
    // destructor for the class
    std::cout << "destructer called" << std::endl;
    delete[] a;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &old)
{
    // copy constructor
    // makes a deep copy of the queue ref
    // named old into current object
    std::cout << "deep copy called" << std::endl;

    // allocate new memory and copy elements
    // a = new int[old.capacity];
    a = new T[old.capacity];
    for (int i = 0; i < old.size; i++) {
        a[i] = old.a[i];
    }

    // updating capacity, size, and front
    capacity = old.capacity;
    size = old.size;
    front = old.front;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    // copy assignment operator
    std::cout << "copy assignment called" << std::endl;

    if (this != &rhs) {
        std::cout << "allocate, deallocate, assign" << std::endl;

        // allocate new memory and copy elements
        // a = new int[rhs.capacity];
        T* new_a = new T[rhs.capacity];
        for (int i = 0; i < rhs.size; i++) {
            a[i] = rhs.a[i];
        }

        // deallocate old memory
        delete[] a;

        // allocate new memeory
        a = new_a;

        capacity = rhs.capacity;
        size = rhs.size;
        front = rhs.front;
    }

    // by convention always return *this
    return *this;
}

// combined files

int main() {
    Queue<int> intNums1;

    intNums1.enqueue(4);
    intNums1.enqueue(8);
    intNums1.enqueue(12);

    std::cout << "Item dequeued: " << intNums1.dequeue() << std::endl;

    Queue<int> intNums2 = intNums1;

    std::cout << "Item dequeued: " << intNums1.dequeue() << std::endl;
    std::cout << "Item dequeued: " << intNums2.dequeue() << std::endl;

    intNums2 = intNums1;

    std::cout << "Item dequeued: " << intNums1.dequeue() << std::endl;
    std::cout << "Item dequeued: " << intNums2.dequeue() << std::endl;

    Queue<double> dbNumb;

    return 0;
}