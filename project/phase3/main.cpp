#include <iostream>
using namespace std;
#include "BHeap.cpp"

int main()
{
    char key[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    BHeap<char> H1(key, 6);

    H1.printKey();

    cout << "------------" << endl;
    cout << "This is the min (no extract): " << H1.peekKey() << endl;

    // char key[1] = {'a'};
    //
    // BHeap<char> H2(key, 1);
    //
    // H2.printKey();

    // BHeap<char> H3;
    //
    // H3.insert('a');
    // H3.printKey();

    return 0;
}