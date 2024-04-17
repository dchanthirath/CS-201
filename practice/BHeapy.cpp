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
class BHeapy {
public:
    // constructors
    BHeapy();
    BHeapy(keytype k[], int s);

    // rule of three
    ~BHeapy();
    BHeapy(const BHeapy &old);
    BHeapy& operator=(const BHeapy& rhs);

    // member functions
    keytype peekKey();
    keytype extractMin();

    void insert(keytype k);
    void merge(BHeapy<keytype> &H2);
    void printKey();

private:
    // member variables
    Node<keytype>* minimumNode;

    // member functions
    void consolidate();

};

template<typename keytype>
BHeapy<keytype>::BHeapy()
{
    minimumNode = nullptr;
}

template<typename keytype>
BHeapy<keytype>::BHeapy(keytype k[], int s)
{
    minimumNode = nullptr;

    for (int i = 0; i < s; i++) {
        insert(k[i]);
    }
    // consolidate();
}

template<typename keytype>
BHeapy<keytype>::~BHeapy()
{
    // destructor for the class
    if (minimumNode == nullptr) return;

    Node<keytype>* currentNode = minimumNode;
    Node<keytype>* nextNode = nullptr;

    do { // does this block first before checking condition, then normal while loop
        nextNode = currentNode->right;
        delete currentNode;
        currentNode = nextNode;
    } while (currentNode != minimumNode);
}

template<typename keytype>
void BHeapy<keytype>::insert(keytype k)
{
    Node<keytype>* newNode = new Node<keytype>;
    newNode->key = k;

    if (minimumNode == nullptr) // when heap is empty
    {
        minimumNode = newNode;
        newNode->left = newNode;
        newNode->right = newNode;
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
void BHeapy<keytype>::printKey()
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
