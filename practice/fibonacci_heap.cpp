#include <iostream>

template <typename T>
struct Node {
    T key;
    int degree;
    bool mark;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
};

template<typename>
class FibonacciHeap
{
public:
    // constructors
    FibonacciHeap();
    FibonacciHeap(T* keys, int n);
    // rule of three
    ~FibonacciHeap(); // destructor
    FibonacciHeap(const FibonacciHeap& old); // copy constructor
    FibonacciHeap& operator=(const FibonacciHeap& rhs); // copy assignment

    // methods
    void insert(T key);
    void remove();

    T minimum();
    T extractMin();

    void decreaseKey(Node* x, T k);

private:
    Node root;
    Node min;
    int n;

};
