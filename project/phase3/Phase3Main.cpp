#include <iostream>
using namespace std;
#include "BHeap.cpp"

int main(){
	char K[6] = {'a','b','c','d','e','f'};
	
	BHeap<char> H1(K,6), H2;
	
	cout << H1.extractMin() << endl;
	//Should output a
	
	H1.printKey();
	//Should output "B2:\n b c d e\n B0:\n f \n"
	
	H1.insert('g'); H1.insert('h'); H1.insert('a'); H1.insert('i');
	
	H1.printKey();
	//Should output "B0:\n a\n B2:\n b c d e\n B0:\n f\n B0:\n g\n B0:\n h\n B0:\n i\n"
	
	cout << H1.extractMin() << endl;
	//Should output a
	
	H1.printKey();	
	//Should output 
	
	H1.insert('j'); H1.insert('k'); H1.insert('l');
    
	cout << H1.extractMin() << endl;
	//Should output b
	H1.printKey();
	//Should output	
	
	H2.insert('A'); H2.insert('B'); H2.insert('C'); H2.insert('D');
	cout<< H2.extractMin() << endl;
	
	H2.printKey();
	//Should output
	
	H1.merge(H2); H1.printKey();
	//Should output
	
	cout << H1.extractMin() << endl;
	//Should output B
	
	H1.printKey();
	//Should output
	
	
	return 0;
}
