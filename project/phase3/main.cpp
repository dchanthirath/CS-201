#include <iostream>
using namespace std;
#include "BHeap.cpp"

int main()
{
    char K[6] = {'a','b','c','d','e','f'};

    BHeap<char> H1(K,6), H2;

    cout << H1.extractMin() << endl;
    //Should output a

    H1.printKey();
    //Should output "B2:\n b c d e\n B0:\n f \n"

    return 0;
}