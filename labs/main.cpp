#include <iostream>

#include "Queue.cpp"

using namespace std;

int main()
{
    // Queue qList1;

    // qList1.enqueue(3);
    // qList1.enqueue(6);
    // qList1.enqueue(9);

    // for(int i = 0; i < 6; i++)
    // {
    //     qList1.enqueue(i);
    // }
    // cout << "Item dequeued: " << qList1.dequeue() << endl;

    // Queue qList2(12);
    //
    // for (int i = 0; i < 5; i++)
    // {
    //     qList2.enqueue(i);
    // }
    // cout << "Item dequeued: " << qList2.dequeue() << endl;

    // Queue qList3(10);
    // for (int i = 0; i < 8; i++)
    // {
    //     qList3.enqueue(i);
    // }
    // cout << "Item dequeued: " << qList3.dequeue() << endl;
    // cout << "Item dequeued: " << qList3.dequeue() << endl;
    //
    // Queue numbers(qList3); // deep copy
    // cout << "Item dequeued: " << numbers.dequeue() << endl;

    Queue<int> intNums1;

    intNums1.enqueue(4);
    intNums1.enqueue(8);
    intNums1.enqueue(12);

    cout << "Item dequeued: " << intNums1.dequeue() << endl;

    Queue<int> intNums2 = intNums1;

    cout << "Item dequeued: " << intNums1.dequeue() << endl;
    cout << "Item dequeued: " << intNums2.dequeue() << endl;

    intNums2 = intNums1;

    cout << "Item dequeued: " << intNums1.dequeue() << endl;
    cout << "Item dequeued: " << intNums2.dequeue() << endl;

    Queue<double> dbNumb;

    return 0;
}
