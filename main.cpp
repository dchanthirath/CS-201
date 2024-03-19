#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;

    int arr[] = { 10, 4, 5, 8, 6, 11, 26 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << n << std::endl;

    return 0;

}
