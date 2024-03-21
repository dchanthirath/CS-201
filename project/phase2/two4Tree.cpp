//
// Created by Donald on 3/4/2024.
//
#include <iostream>
#include "CircularDynamicArray.cpp"

class Node {
public:
    int data;
    Node *left;
    Node *right;
private:
};

template <typename keytype, typename valuetype>
class two4Tree {
public:
    two4Tree();
    explicit two4Tree(keytype k[], valuetype V[], int s);
    // rule of three
    ~two4Tree(); // destructor
    two4Tree(const two4Tree &old); // copy constructor
    two4Tree& operator=(const two4Tree& rhs); // copy assignment

    valuetype * search(keytype k);

    void insert(keytype k, valuetype v);
    int remove(keytype k);
    int rank(keytype k);

    keytype select(int pos);
    keytype *successor(keytype k);
    keytype *predecessor(keytype k);

    int size();

    void preorder();
    void inorder();
    void postorder();

private:
    int treeSize;
    int *keyArray, *valArray;

    // helper functions

};

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::two4Tree()
{
    // Default Constructor.
    // The tree should be empty
    keyArray = *
    treeSize = 0;

}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::two4Tree(keytype k[], valuetype V[], int s)
{
    // For this constructor the tree should be built
    // using the arrays K and V containing s items of
    // keytype and valuetype. The tree should be
    // built using repeated insertion.
    treeSize = s;

}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::~two4Tree()
{
    
}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>::two4Tree(const two4Tree &old)
{

}

template <typename keytype, typename valuetype>
two4Tree<keytype, valuetype>& two4Tree<keytype, valuetype>::operator=(const two4Tree& rhs)
{

}

template <typename keytype, typename valuetype>
valuetype * two4Tree<keytype, valuetype>::search(keytype k)
{

}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::insert(keytype k, valuetype v)
{

}

template <typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::remove(keytype k)
{

}

template <typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::rank(keytype k)
{

}

template <typename keytype, typename valuetype>
keytype two4Tree<keytype, valuetype>::select(int pos)
{

}

template <typename keytype, typename valuetype>
keytype* two4Tree<keytype, valuetype>::successor(keytype k)
{

}

template <typename keytype, typename valuetype>
keytype* two4Tree<keytype, valuetype>::predecessor(keytype k)
{

}

template <typename keytype, typename valuetype>
int two4Tree<keytype, valuetype>::size()
{

}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::preorder()
{

}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::inorder()
{

}

template <typename keytype, typename valuetype>
void two4Tree<keytype, valuetype>::postorder()
{

}
