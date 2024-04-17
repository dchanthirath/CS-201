//
// created by Donald on 4/12/2024
//
#include <iostream>

template <typename keytype>
struct Node {
    keytype key;
    int height;
    Node* left;
    Node* right;
    Node* parent;
    Node* child;

    Node() {
        height = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        child = nullptr;
    }
};

template <typename keytype>
class BHeap {
public:
    // constructors
    BHeap();
    BHeap(keytype k[], int s);

    // rule of three
    ~BHeap();
    BHeap(const BHeap &old);
    BHeap& operator=(const BHeap& rhs);

    // member functions
    keytype peekKey();
    keytype extractMin();

    void insert(keytype k);
    void merge(BHeap<keytype> &H2);
    void printKey();

private:
    // member variables
    Node<keytype>* minimumNode;

    // member functions
    void consolidate();

};

template<typename keytype>
BHeap<keytype>::BHeap()
{
    minimumNode = nullptr;
}

template<typename keytype>
BHeap<keytype>::BHeap(keytype k[], int s)
{
    minimumNode = nullptr;

    for (int i = 0; i < s; i++) {
        insert(k[i]);
    }
    // consolidate();
}

template<typename keytype>
void BHeap<keytype>::insert(keytype k)
{
    Node<keytype>* newNode = new Node<keytype>;
    newNode->key = k;

    if (minimumNode == nullptr) // when heap is empty
    {
        minimumNode = newNode;
    }
    else // heap is not empty
    {
        newNode->left = minimumNode->left;
        newNode->right = minimumNode;

        minimumNode->left->right = newNode;
        minimumNode->left = newNode;

        // update min
        if (k < minimumNode->key)
        {
            minimumNode = newNode;
        }
    }
}

template<typename keytype>
void BHeap<keytype>::printKey()
{
    if (minimumNode == nullptr) return;

    Node<keytype>* currentNode = new Node<keytype>;
    currentNode = minimumNode;

    std::cout << "B:" << currentNode->height << " " << std::endl;
    do {
        std::cout << currentNode->key << " " << std::endl;
        currentNode = currentNode->right;
    } while(currentNode != minimumNode);
    std::cout << std::endl;
}


int main()
{
    char keys[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    BHeap<char> H1(keys, 6);
    H1.printKey();

    return 0;
}
