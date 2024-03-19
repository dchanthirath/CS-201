#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "CircularDynamicArray.cpp"

void test0(ostream &fp);
void test1(ostream &fp);
void test2(ostream &fp);
void test3(ostream &fp);
void test4(ostream &fp);

void foo(CircularDynamicArray<int> x) {
        // x => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"
        for (int i=0; i<x.length()/2; i++)
                x[i] = x[x.length()/2+i];
        // x => "6 7 8 9 10 15 19 6 7 8 9 10 15 19 11"
        for (int i=0; i< x.length();i++) cout << x[i] << " ";  cout << endl;
}
int printWrapper = 0;

int main(int argc, char **argv){
        int testToRun = atoi(argv[1]);
        switch (testToRun){
                case 1:
                        test1(cout);
                        break;
                case 2:
                        test2(cout);
                        break;
                case 3:
                        test3(cout);
                        break;
                case 4:
                        test4(cout);
                        break;

        }
}

void test1(ostream &fp)
{
if(printWrapper) fp << "Running test 1" << endl;
        CircularDynamicArray<int> C;
        for (int i=0; i< 15;i++)
    {
       C.addEnd(i*10);
     }
     for (int i=0; i< C.length();i++) fp << C[i] << " ";fp << endl;
        // 0 10 20 30 40 50 60 70 80 90 100 110 120 130 140
        C.delFront();
        // 10 20 30 40 50 60 70 80 90 100 110 120 130 140
        C.delFront();
        // 20 30 40 50 60 70 80 90 100 110 120 130 140
        for (int i=0; i< C.length();i++) fp << C[i] << " "; fp << endl;
        C.delEnd();
        // 20 30 40 50 60 70 80 90 100 110 120 130
        C.delEnd();
        // 20 30 40 50 60 70 80 90 100 110 120
        for (int i=0; i< C.length();i++) fp << C[i] << " ";  fp << endl;
        // 20 30 40 50 60 70 80 90 100 110 120
        C.addEnd(5001);
        // 20 30 40 50 60 70 80 90 100 110 120 5001
        C.addEnd(5003);
        // 20 30 40 50 60 70 80 90 100 110 120 5001 5003
        for (int i=0; i< C.length();i++) fp << C[i] << " ";  fp << endl;
        // 20 30 40 50 60 70 80 90 100 110 120 5001 5003
        C.addFront(5004);
        // 5004 20 30 40 50 60 70 80 90 100 110 120 5001 5003
        C.addEnd(1006);
        // 5004 20 30 40 50 60 70 80 90 100 110 120 5001 5003 5006
        for (int i=0; i< C.length();i++) fp << C[i] << " ";  fp << endl;
        // 5004 20 30 40 50 60 70 80 90 100 110 120 5001 5003 5006
        C.delEnd(); C.delEnd();
        // 5004 20 30 40 50 60 70 80 90 100 110 120 5001
        C.addFront(-1050);
        C.addFront(-2050);
        // -2050 -1050 1004 20 30 40 50 60 70 80 90 100 110 120 1001
        for (int i=0; i< C.length();i++) fp << C[i] << " ";  fp << endl;
        fp << "Capacity is " << C.capacity() << endl;
        // 15
        while(C.length()){
                C.delEnd();
        }

        C.clear();
        fp << "Capacity is " << C.capacity() << endl;
        // 2
        if(printWrapper)fp << "-----------------Finished Test 1----------------------" << endl;
}



void test2(ostream &fp){
        if(printWrapper) fp << "Running test 2" << endl;
        CircularDynamicArray<int> A;
        int temp = 0;
        for(int i=0; i<20;i++){
                A.addEnd(i);
        }
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
    fp << endl;
        fp << "Capacity is " << A.capacity() << endl;
        // 32
        fp << "Search is " << A.linearSearch(14) << endl;
        // 14
        fp << "Select is " << A.QSelect(5) << endl;
        // 4
        A.Sort();
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
        //A.Reverse();

        A.addFront(-120);
        // -120 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
        fp << "Search is " << A.linearSearch(19) << endl;
        // 20
        fp << "Search is " << A.linearSearch(120) << endl;
        // -1
        fp << "Search is " << A.binSearch(15) << endl;
      //16
        fp << "Search is " << A.binSearch(25) << endl;
      //-1
        fp << "Select is " << A.QSelect(5) << endl;
        // 3
        A.Sort();
        // -120 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
        A.addEnd(-100);
        // -120 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 -100
        A.Sort();
        // -120 -100 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
        A.delFront(); A.delEnd(); A.addEnd(53); A[4] = 63;
        // -100 0 1 2 63 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53
        for (int i=0; i< A.length();i++) fp << A[i] << " ";  fp << endl;
        A.Sort();
        // -100 0 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53 63
        CircularDynamicArray<int> B;
        A[0] = -1111;
        // -1111 0 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53 63
        B = A;
        // -1111 0 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53 63
        A[0] = -1001;
        // -1001 0 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53 63
        A[1] = -1003;
        // -1001 -1003 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53 63
        fp << B[0] << endl;
        // -1111
        foo(A);
        for (int i=0; i< B.length();i++) fp << B[i] << " "; fp << endl;
        // -1111 0 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 53 63
        CircularDynamicArray<string> testGeneric1(10);
        CircularDynamicArray<wchar_t> testGeneric2(10);
        CircularDynamicArray<long double> testGeneric3(10);
        fp << "Passed Generics Test" << endl;
        if(printWrapper)fp << "-----------------Finished Test 2----------------------" << endl;
}
void test3(ostream &fp){
        if(printWrapper) fp << "Running test 3" << endl;
        CircularDynamicArray<int> A;
    for(int i=0;i<102000;i++)
    A.addEnd(i);
        for(int i = 0; i < 1002000; i++) A.addFront(i);
        fp << "Select is " << A.QSelect(2000) << endl;
        //1999
        A.Sort();
        fp << "Search is " << A.linearSearch(20000) << endl;
        fp << "Search is " << A.linearSearch(2000) << endl;
        fp << "Search is " << A.linearSearch(200) << endl;
        fp << "Search is " << A.linearSearch(20) << endl;
        fp << "Search is " << A.linearSearch(2) << endl;
        if(printWrapper) fp << "-----------------Finished Test 3----------------------" << endl;
}
void test4(ostream &fp){
        if(printWrapper) fp << "Running test 4" << endl;
        CircularDynamicArray<int> A;
    for(int i=0;i<102000;i++)
    A.addEnd(i);
        for(int i = 0; i < 1002000; i++) A.addFront(i);
        fp << "Select is " << A.QSelect(1002000) << endl;
        //1001999
        A.Sort();
//      A.Sort();   //Test running sort on an already sorted array

        for(int i = 0; i < 1002000; i++) A.binSearch(i);   // Test binSearch running time

        fp << "Search is " << A.binSearch(20000) << endl;
        fp << "Search is " << A.binSearch(2000) << endl;
        fp << "Search is " << A.binSearch(200) << endl;

        fp << "Search is " << A.binSearch(20) << endl;
        fp << "Search is " << A.binSearch(2) << endl;
        if(printWrapper) fp << "-----------------Finished Test 4----------------------" << endl;

}
