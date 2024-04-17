//
// Created by Donald on 4/10/2024.
//
#include <iostream>

template <typename keytype>
struct Node {
    keytype key;
    int height; // tracks the height of the tree e.g. b0, b1, b2, etc.
    Node* parent;
    // Node* child; // the b1, whereas the parent would be b0
    Node* left;
    Node* right;
};

template<typename keytype>
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
    Node<keytype>* minimumNode; // pointer to minimum key

    // member functions
    void consolidate();

    void link(Node<keytype> *node1, Node<keytype> *node2);
    void removeNode(Node<keytype> *node);
};

template<typename keytype>
BHeap<keytype>::BHeap()
{
    //default constructor
    //the heap should be empty

    Node<keytype> *minimum = nullptr;

}

template<typename keytype>
BHeap<keytype>::BHeap(keytype *k, int s)
{
    /*
     * constructor for the class
     * the heap should be built using the array k containing s items
     * heap should be constructed using repeated insertions
     * will call to consolidate after insertions
     */
    Node<keytype> *minimum = nullptr;

    for (int i = 0; i < s; i++)
    {
        insert(k[i]);
    }
    // consolidate();

}

template<typename keytype>
BHeap<keytype>::~BHeap()
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
BHeap<keytype>::BHeap(const BHeap &old)
{
    // copy constructor
    // should create a deep copy of the old heap

}

template<typename keytype>
BHeap<keytype>& BHeap<keytype>::operator=(const BHeap &rhs)
{
    /*
     * assignment operator
     * should create a deep copy of the right hand side heap
     * and return a reference to the left hand side heap
     */

    return *this;
}

template<typename keytype>
keytype BHeap<keytype>::peekKey()
{
    // returns the minimum key in the heap
    // without modifying the heap

    return minimumNode->key;
}

template<typename keytype>
keytype BHeap<keytype>::extractMin()
{
    /*
     * removes the minimum key from the heap and returns the key
     * children of the minimum should be inserted
     * into the root list in place of the minimum
     * (smallest tree to largest tree)
     * and consolidate called starting with the first (smallest rank) child tree
     */

}

template<typename keytype>
void BHeap<keytype>::consolidate() {
    /*
     * the consolidate function should finish with a binomial heap
     * where there is at most one tree of any given size
     * consolidate should start at the minimum pointer and
     * process trees from left to right
     * when the process is finished, the list should be created
     * from smallest tree to largest and the minimum pointer should be updated
     */

}

template<typename keytype>
void BHeap<keytype>::insert(keytype k)
{
    /*
     * inserts the key k into the heap
     * inserts a new b0 tree to the left of the min root
     * does not call consolidate
     */
    Node<keytype>* newNode = new Node<keytype>;
    newNode->key = k;
    newNode->height = 0;
    newNode->parent = nullptr;
    // newNode->child = nullptr;

    if (minimumNode == nullptr) // empty heap
    {
        minimumNode = newNode;
        newNode->left = newNode;
        newNode->right = newNode;
    }
    else // add new node to left of min root
    {
        newNode->left = minimumNode->left;
        newNode->right = minimumNode;

        minimumNode->left->right = newNode;
        minimumNode->left = newNode;

        // if new key is smaller than min, update min
        if (k < minimumNode->key)
        {
            minimumNode = newNode;
        }
    }
}

template<typename keytype>
void BHeap<keytype>::merge(BHeap<keytype> &H2)
{
    /*
     * merges the heap H2 into the current heap
     * consumes H2, H2 should be empty after
     * H2's root list should be inserted
     * after min in H1, with min in H2 being the first root inserted
     */

}

template<typename keytype>
void BHeap<keytype>::printKey()
{
    /*
     * writes the stored in the heap
     * prints the tree with minimum first
     * the proceeds through the root list
     * printing each tree
     * when printing a binomial tree,
     * print the size of the tree first
     * and then use a modified preorder traversal of the tree
     */

    if (minimumNode == nullptr) return;

    Node<keytype>* currentNode = minimumNode;
    std::cout << "B" << currentNode->height << ":" << std::endl;
    do {
        std::cout << currentNode->key << " ";
    } while (currentNode != minimumNode);
}
