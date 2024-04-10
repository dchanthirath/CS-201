//
// Created by Donald on 4/2/2024.
//
#include <iostream>
using namespace std;

#include "two4Tree.cpp"

int main() {
    string K[2] = {"A", "B"};
    float V[2] = {12, 11};

    two4Tree<string,float> T1(K,V,2);

    T1.preorder();

    return 0;
}