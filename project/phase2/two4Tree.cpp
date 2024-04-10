//
// Created by Donald on 3/4/2024.
//
#include <iostream>
// #include "CircularDynamicArray.cpp"

template <typename elmtype>
class CircularDynamicArray {
public:
    CircularDynamicArray();
    explicit CircularDynamicArray(int s);
    // rule of three
    ~CircularDynamicArray(); // destructor
    CircularDynamicArray(const CircularDynamicArray &old); // copy constructor
    CircularDynamicArray& operator=(const CircularDynamicArray& rhs); // copy assignment

    elmtype& operator[](int i);

    void addEnd(elmtype v);
    void addFront(elmtype v);
    void delEnd();
    void delFront();

    int length() const;
    int capacity() const;
    void clear();

    elmtype QSelect(int k);
    void Sort();

    int linearSearch(elmtype e);
    int binSearch(elmtype e);

private:
    int size, capacitySize, front;
    elmtype *array;
    elmtype error;

    // helper functions
    void sizeUp();
    void sizeDown();

    int partition(int l, int r);
    int kthSmallest(int l, int r, int k);
    // int kthSmallest(int *A, int pivot, int k);

    void quickSort(int low, int high);

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
void CircularDynamicArray<elmtype>::sizeUp()
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

template <typename elmtype>
void CircularDynamicArray<elmtype>::addEnd(elmtype v) {
    // increases the size of the array by 1 and stores v at the end of the array.
    // Should double the capacity when the new element doesn't fit.

    // if full
    if (size == capacitySize) sizeUp();

    // adding 'v' to the end of the array
    int back = (front + size) % capacitySize; // wrap around for addEnd
    array[back] = v;
    size++;
    // std::cout << "CDA array (end): ";
    // for (int i = 0; i < capacitySize; i++) std::cout << array[i] << " "; std::cout << std::endl;
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::clear()
{
    // Frees any space currently used and starts over with an array of capacity 2 and size 0

    delete[] array;
    size = front = 0;
    capacitySize = 2;
    array = new elmtype[capacitySize];
}

template <typename elmtype>
void CircularDynamicArray<elmtype>::sizeDown()
{
    // prevent deleting when size is 0
    if (size == 0) return;

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


template <typename elmtype>
void CircularDynamicArray<elmtype>::delEnd() {
    // reduces the size of the array by 1 at the end.
    // Should shrink the capacity when only 25% of the array is in use after the delete.

    if (size == (capacitySize / 4)) sizeDown();

    // int back = (front + size - 1) % capacitySize;
    size--;
}

template <typename keytype, typename valuetype>
struct Node {
    keytype keys[3];
    CircularDynamicArray<valuetype> values;
    Node *children[4];
    int keyCount; // node size
    bool leaf;
};

template <typename keytype, typename valuetype>
class two4Tree {
public:
    two4Tree();
    two4Tree(keytype k[], valuetype V[], int s);

    // rule of three
    ~two4Tree(); // destructor
    two4Tree(const two4Tree &old); // copy constructor
    two4Tree& operator=(const two4Tree& rhs); // copy assignment

    valuetype * search(keytype k);

    void insert(keytype k, valuetype v);
    int remove(keytype k);

    int rank(keytype k);
    keytype select(int pos);

    // keytype *successor(keytype k);
    // keytype *predecessor(keytype k);

    int duplicates(keytype k);
    int size();

    void preorder();
    void inorder();
    void postorder();

private:
    Node<keytype, valuetype> *root;
    int treeSize;
    int *keyArray, *valArray;

    // helper functions
    void split(Node<keytype, valuetype> *node, Node<keytype, valuetype> *parent);

    void preorderTraversal(Node<keytype, valuetype> *node);
    void inorderTraversal(Node<keytype, valuetype> *node);
    void postorderTraversal(Node<keytype, valuetype> *node);
};

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::two4Tree()
{
    // Default Constructor.
    // The tree should be empty
    root = nullptr;
    treeSize = 0;

}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::two4Tree(keytype k[], valuetype V[], int s)
{
    // For this constructor the tree should be built
    // using the arrays K and V containing s items of
    // keytype and valuetype. The tree should be
    // built using repeated insertion.
    root = nullptr;
    treeSize = 0;
    for (int i = 0; i < s; i++)
    {
        insert(k[i], V[i]);
    }
}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::~two4Tree()
{
    // destructor for the class
    if (root != nullptr)
    {
        // delete root;
    }
}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::two4Tree(const two4Tree &old)
{
    // copy constructor
    root = nullptr;
    treeSize = 0;
    Node<keytype, valuetype> *node = old.root;
    while (node != nullptr)
    {
        for (int i = 0; i < node->keyCount; i++)
        {
            insert(node->keys[i], node->values[i]);
        }

        node = node->children[node->keyCount];
    }

}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>& two4Tree<keytype, valuetype>::operator=(const two4Tree& rhs)
{
    // copy assignment
    if (this != &rhs)
    {
        // delete root;
        root = nullptr;
        treeSize = 0;
        Node<keytype, valuetype> *node = rhs.root;
        while (node != nullptr)
        {
            for (int i = 0; i < node->keyCount; i++)
            {
                insert(node->keys[i], node->values[i]);
            }

            node = node->children[node->keyCount];
        }
    }

    return *this;
}

template <typename keytype, typename valuetype>
valuetype * two4Tree<keytype, valuetype>::search(keytype k)
{
    // Traditional search.
    // Should return a pointer to the first valuetype stored with the key.
    // If the key is not stored in the tree then the function should return NULL.
}

template<typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::split(Node<keytype, valuetype> *node, Node<keytype, valuetype> *parent)
{
    // Create a new node
    Node<keytype, valuetype>* newNode = new Node<keytype, valuetype>;

    // Move the two largest keys and their associated values and children to the new node
    newNode->keys[0] = node->keys[2];
    newNode->values.addEnd(node->values[2]);
    newNode->children[0] = node->children[2];
    newNode->children[1] = node->children[3];
    newNode->keyCount = 1;
    newNode->leaf = node->leaf;

    // Reduce the key count of the old node
    node->keyCount = 1;

    // If the node was the root, create a new root
    if (node == root) {
        root = new Node<keytype, valuetype>;
        root->keys[0] = node->keys[1];
        root->values.addEnd(node->values[1]);
        root->children[0] = node;
        root->children[1] = newNode;
        root->keyCount = 1;
        root->leaf = false;
    } else {
        // If the node was not the root, move the middle key and value up to the parent node
        int i;
        for (i = 0; i < parent->keyCount; i++) {
            if (node->keys[1] < parent->keys[i]) {
                break;
            }
        }

        // Shift keys and children to the right
        for (int j = parent->keyCount; j > i; j--) {
            parent->keys[j] = parent->keys[j - 1];
            parent->values[j] = parent->values[j - 1];
            parent->children[j + 1] = parent->children[j];
        }

        // Insert new key and child
        parent->keys[i] = node->keys[1];
        parent->values[i] = node->values[1];
        parent->children[i + 1] = newNode;
        ++parent->keyCount;

        // If the parent node is full, split it
        if (parent->keyCount == 3) {
            split(parent, parent->children);
        }
    }
}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::insert(keytype k, valuetype v)
{
    // Inserts the node with key k and value v into the tree.
    // If the item already exists in the tree
    // then increment a counter associated with the
    // key to indicate an additional item of that key in the tree
    // (don’t create a new node)
    // and add the new value v to the end of a circular
    // dynamic array of values associated with that key.

    if (root == nullptr) // when the tree is empty
    {
        root = new Node<keytype, valuetype>;
        root->keys[0] = k;
        root->values.addEnd(v);
        root->keyCount = 1;
        root->leaf = true;
    }
    else // when the tree is not empty
    {
        Node<keytype, valuetype> *node = root;
        Node<keytype, valuetype> *parent = nullptr;

        while (node != nullptr) {
            parent = node;

            for (int i = 0; i < node->keyCount; i++) //  finding the correct leaf node
            {
                if (k < node->keys[i])
                {
                    node = node->children[i];
                    break;
                }

                if (i == node->keyCount - 1)
                {
                    node = node->children[i + 1];
                    break;
                }
            }
        }

        if (parent->keyCount < 3) { // checking if the parent node is not full
            int i;
            for (i = 0; parent->keyCount; i++)
            {
                if (k < parent->keys[i]) break;
            }

            for (int j = parent->keyCount; j > i; --j)
            {
                parent->keys[j] = parent->keys[j - 1];
                parent->children[j + 1] = parent->children[j];
            }

            // insert the key and value
            parent->keys[i] = k;
            parent->values.addEnd(v);
            parent->children[i + 1] = nullptr;
            ++parent->keyCount;

            std::cout << std::endl;
        }
        else // when the parent node is full
        {
            split(parent, parent->children);
            insert(k, v);
        }
    }

    treeSize++;
}

template <typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::remove(keytype k)
{
    // Removes the node with key k and returns 1.
    // If more than one instance of that key is in the tree
    // then decrement the counter for that key
    // and remove the first (front) value in the array of values.
    // If key k is not found then remove should return 0.
    // If the node with key k is not part of a leaf then replace k by its predecessor.
}

template <typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::rank(keytype k)
{
    // Returns the rank of the key k in the tree.
    // Returns 0 if the key k is not found.
    // The smallest item in the tree is rank 1.
    // If there are multiple instances of the key k in the tree,
    // return the rank of the first instance.

}

template <typename keytype, typename valuetype>
keytype two4Tree<keytype, valuetype>::select(int pos)
{
    // Order Statistics. Returns the key of the node at position pos in the tree.
    // Calling with pos = 1 should return the smallest key in the tree,
    // pos = n should return the largest.
}

// template <typename keytype, typename valuetype>
// keytype* two4Tree<keytype, valuetype>::successor(keytype k)
// {
//
// }
//
// template <typename keytype, typename valuetype>
// keytype* two4Tree<keytype, valuetype>::predecessor(keytype k)
// {
//
// }

template<typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::duplicates(keytype k)
{
    // Much like search,
    // but returns the count of key k in the tree.
    // 0 means not in the tree.
}

template <typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::size()
{
    // returns the number of keys in the tree.
    return treeSize;
}

template<typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::preorderTraversal(Node<keytype, valuetype> *node) {
    if (node == nullptr) return;

    for (int i = 0; i < node->keyCount; i++)
    {
        std::cout << node->keys[i] << std::endl;
    }

    for (int i = 0; i < node->keyCount + 1; i++)
    {
        preorderTraversal(node->children[i]);
    }
}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::preorder()
{
    // Prints the nodes of the tree in a preorder traversal.
    // Print all keys in a node separated by spaces, terminated by a newline.
    // Then continue to the next node in the traversal.

    // empty
    if (root == nullptr) return;

    preorderTraversal(root);
}

template<typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::inorderTraversal(Node<keytype, valuetype> *node) {
    if (node == nullptr) return;

    for (int i = 0; i < node->keyCount; i++)
    {
        inorderTraversal(node->children[i]);
        std::cout << node->keys[i] << std::endl;
    }

    inorderTraversal(node->children[node->keyCount]);
}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::inorder()
{
    // Prints the keys of the tree in an inorder traversal.
    // The list of keys are separated by a single space and terminated with a newline.
    // The keys should appear in sorted order.

    // empty
    if (root == nullptr) return;

    inorderTraversal(root);
}

template<typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::postorderTraversal(Node<keytype, valuetype> *node) {
    if (node == nullptr) return;

    for (int i = 0; i < node->keyCount + 1; i++)
    {
        postorderTraversal(node->children[i]);
    }

    for (int i = 0; i < node->keyCount; i++)
    {
        std::cout << node->keys[i] << std::endl;
    }
}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::postorder()
{
    // Prints the keys of the tree in a postorder traversal.
    // Print all keys in a node separated by spaces, terminated by a newline.
    // Then continue to the next node in the traversal.

    // empty
    if (root == nullptr) return;

    postorderTraversal(root);
}
