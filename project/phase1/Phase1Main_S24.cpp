#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"

void foo(CircularDynamicArray<int> x) {
	// x => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"
	for (int i=0; i<x.length()/2; i++)
		x[i] = x[x.length()/2+i];
	// x => "6 7 8 9 10 15 19 6 7 8 9 10 15 19 11"
	for (int i=0; i< x.length();i++) cout << x[i] << " ";  cout << endl;
}

int main(){
	CircularDynamicArray<float> C(10);
	for (int i=0; i< C.length();i++) C[i] = i;
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.delFront();
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 9"
	C.delEnd();
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8"
	C.addEnd(100.0);
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100"
	C.delFront();
	C.addEnd(200.0);
	// C => "2 3 4 5 6 7 8 100 200"	

	C.addEnd(300.0);
	C.addEnd(400.0);
	// C => "2 3 4 5 6 7 8 100 200 300 400"	
	
	C.delEnd(); C.delFront();C.delEnd();
	for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
	// C => "3 4 5 6 7 8 100 200"	
	


	CircularDynamicArray<int> A,B;
	for(int i=0; i<10;i++) A.addEnd(i);
	B = A;
	A.addEnd(15); A.addEnd(19);
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" 
	cout << "Select is " << A.linearSearch(5) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 5
	cout << "Select is " << A.binSearch(12) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => -1
	cout << "Select is " << A.binSearch(15) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 10	
	A.addFront(10); 
	// A => "10 0 1 2 3 4 5 6 7 8 9 15 19"
	cout << "Select is " << A.linearSearch(5) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9 15 19" Search => 6
	cout << "Select is " << A.QSelect(3) << endl;
    // Select => 2	
	
	A.Sort();
	// A => "0 1 2 3 4 5 6 7 8 9 10 15 19"
	A.addEnd(11); A.addFront(1); A.addFront(2); A.addFront(3);
	cout << "capacity is " << A.capacity() << endl;
	// A => "3 2 1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  capacity => 32
	A.delFront(); A.delFront();
	// A => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  capacity => 32

	foo(A);
	for (int i=0; i< A.length();i++) cout << A[i] << " ";  cout << endl;
	// A => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"
	for (int i=0; i< B.length();i++) cout << B[i] << " ";  cout << endl;
	// B => "0 1 2 3 4 5 6 7 8 9"
}