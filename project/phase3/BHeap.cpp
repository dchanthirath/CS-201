//
// Created by Donald on 4/10/2024.
//
#include <iostream>

template <typename keytype>
struct Node {
    keytype key;
    int degree; // tracks the degree of the tree e.g. b0, b1, b2, etc.
    Node* parent;
    Node* child; // the b1, whereas the parent would be b0
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
    static const int MAX_DEGREE = 32;
    Node<keytype>* minimumNode; // pointer to minimum key

    // member functions
    void deleteHeap(Node<keytype>* node);
    void consolidate();
    void link(Node<keytype>* childNode, Node<keytype>* parentNode);

    void removeNode(Node<keytype> *node);
};

template<typename keytype>
BHeap<keytype>::BHeap()
{
    //default constructor
    //the heap should be empty
    std::cout << "DEFAULT CONSTRUCTOR CALLED" << std::endl; // TODO: delete this later

    minimumNode = nullptr;
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
    std::cout << "OVERLOADED CONSTRUCTOR CALLED" << std::endl; // TODO: delete this later

    minimumNode = nullptr;

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
    std::cout << "DESTRUCTOR CALLED" << std::endl; // TODO: delete this later

    if (minimumNode == nullptr) return;

    // if (minimumNode != nullptr) {
    //     deleteHeap(minimumNode);
    // }

    Node<keytype>* currentNode = minimumNode;
    Node<keytype>* nextNode = nullptr;

    do { // does this block first before checking condition, then normal while loop
        nextNode = currentNode->right;
        delete currentNode;
        currentNode = nextNode;
    } while (currentNode != minimumNode);
}

template<typename keytype>
void BHeap<keytype>::deleteHeap(Node<keytype> *node)
{
    // Recursively delete all nodes starting from the given node
    if (node == nullptr) {
        return;
    }
    deleteHeap(node->child); // Recursively delete the child list
    deleteHeap(node->right); // Recursively delete the sibling list
    delete node; // Delete the current node
}

template<typename keytype>
BHeap<keytype>::BHeap(const BHeap &old)
{
    // copy constructor
    // should create a deep copy of the old heap
    std::cout << "COPY CONSTRUCTOR CALLED" << std::endl; // TODO: delete this later

}

template<typename keytype>
BHeap<keytype>& BHeap<keytype>::operator=(const BHeap &rhs)
{
    /*
     * assignment operator
     * should create a deep copy of the right hand side heap
     * and return a reference to the left hand side heap
     */
    std::cout << "ASSIGNMENT OPERATOR CALLED" << std::endl; // TODO: delete this later

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

    // the list empty
    if (minimumNode == nullptr) // the list is empty
    {
        std::cout << "heap is empty" << std::endl; // TODO: delete this later
        return keytype();
    }

    // assign mininum key to key value
    int keyValue = minimumNode->key;

    // pop the minimum
    Node<keytype>* leftOfMinimum = minimumNode->left;
    Node<keytype>* rightOfMinimum = minimumNode->right;

    if (minimumNode->child == nullptr) { // no child case
        leftOfMinimum->right = minimumNode->right;
        rightOfMinimum->left = minimumNode->left;
    } else { // child case
        minimumNode->child->left = minimumNode->left;
        minimumNode->child->right = minimumNode->right;
    }

    // consolidate the heap
    // consolidate();

    delete minimumNode;

   // find new min
    minimumNode = rightOfMinimum;
    Node<keytype>* currentNode = rightOfMinimum->right;

    while (currentNode != rightOfMinimum) {
        if (currentNode->key < minimumNode->key) {
            minimumNode = currentNode;
        }
        currentNode = currentNode->right;
    }

    // returns the old min
    return keyValue;
}

// template<typename keytype>
// keytype BHeap<keytype>::extractMin()
// {
//     /*
//      * Removes the minimum key from the heap and returns the key.
//      * Children of the minimum should be inserted into the root list in place of the minimum.
//      * Consolidate is called starting with the first (smallest rank) child tree.
//      * Written from the book
//      */
//
//     keytype minKey; // Variable to store the minimum key
//
//     // If the heap is not empty
//     if (minimumNode != nullptr) {
//         // Store the minimum key
//         minKey = minimumNode->key;
//
//         // Extract children of the minimum and insert them into the root list
//         Node<keytype>* child = minimumNode->child;
//         while (child != nullptr) {
//             Node<keytype>* nextChild = child->right; // Store the next child before modifying the pointers
//             // insertIntoRootList(child); // Insert the child into the root list
//             child->parent = nullptr; // Reset the parent pointer of the child
//             child = nextChild; // Move to the next child
//         }
//
//         // Remove the minimum from the root list
//         // removeNodeFromRootList(minimumNode);
//
//         // Update the minimum pointer
//         if (minimumNode == minimumNode->right) {
//             minimumNode = nullptr; // If the minimum was the only node in the root list
//         } else {
//             minimumNode = minimumNode->right; // Set minimum to the next node in the root list
//         }
//
//         // Consolidate the heap
//         // consolidate();
//     }
//
//     return minKey; // Return the minimum key
// }

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

    Node<keytype>* rootList[MAX_DEGREE] = {nullptr};

    Node<keytype>* currentNode = minimumNode;
    Node<keytype>* endNode = minimumNode;

    do { // traversing rootlist and consolidating heaps with same degree
        Node<keytype>* nextNode = currentNode->right;
        int degree = currentNode->degree;

        while (rootList[degree] != nullptr)
        { // merging trees with same degree
            Node<keytype>* otherNode = rootList[degree];
            if (otherNode->key < currentNode->key) // swap the two nodes when other is greater than current
            {
                std::swap(currentNode, otherNode);
            }
            // set other node as child of other node
            adoption(otherNode, currentNode);
            rootList[degree] = nullptr;
            ++degree;
        }

        rootList[degree] = currentNode;
        currentNode = nextNode; // gets next node
    } while(currentNode != endNode);
}

template<typename keytype>
void BHeap<keytype>::link(Node<keytype> *childNode, Node<keytype> *parentNode)
{
    /*
    * Link child as a child of parent
    * Update degree of parent and make child a child of parent
    */

    childNode->parent = parentNode;
    childNode->right = parentNode->child;
    if (parentNode->child != nullptr)
    {
        parentNode->child->left = childNode;
    }
    parentNode->child = childNode;

    parentNode->degree++;
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
    newNode->degree = 0;
    newNode->parent = newNode;
    newNode->child = nullptr;

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

    // Node<keytype>* H1MinLeft = minimumNode->left; // acts like a TEMP holding the original node
    //
    // minimumNode->left->right = H2.minimumNode; // updates H1's left of min's right pointer to H2 min
    // minimumNode->left = H2.minimumNode->left; // updates H1's min's left pointer to H2's min's left pointer
    //
    // H2.minimumNode->left->right = minimumNode; // updates H2's left of min's right pointer to H1 min
    // H2.minimumNode->left = H1MinLeft; // updates H2's min's left pointer to H1's min's left pointer

    Node<keytype>* H2MinLeft = H2.minimumNode->left; // acts like a TEMP holding the original node

    H2MinLeft->right = minimumNode; // updates H2's left of min's right pointer to H1's min node
    H2.minimumNode->left = minimumNode->left; // updates's H2's min's left node to H1's min left pointer

    minimumNode->left->right = H2.minimumNode; // updates H1's left of min's right pointer to H2 min
    minimumNode->left = H2MinLeft; // updates H1's min's left pointer to H2's min's left pointer

    // effectively deletes H2 by disconnecting H2's min
    H2.minimumNode = nullptr;
    H2.minimumNode->left = nullptr;
    H2.minimumNode->right = nullptr;
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
    std::cout << "B" << currentNode->degree << ":" << std::endl; // this will only print the first
    do {
        std::cout << currentNode->key << " ";
        currentNode = currentNode->right;
    } while (currentNode != minimumNode);
    std::cout << std::endl;
}
