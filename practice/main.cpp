//
// This is used to test whatever
//

#include <iostream>
using namespace std;

#include "Bheapy.cpp"

int main()
{
    char keys[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    BHeapy<char> H1(keys, 6);
    H1.printKey();

    return 0;
}
