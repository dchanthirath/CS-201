#include <iostream>
using namespace std;
#include "two4Tree.cpp"

int main(){
	string K[12] = {"A","B","C","D","E","F","G","H","I","K","L","M"};
	float V[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
	
	two4Tree<string,float> T1(K,V,12), T2;
	
	for(int i=0; i<12; i++) T2.insert(K[i],V[i]);
	// T1 and T2 should be the same trees
	
	T1.preorder();
	//Should output "D\n B\n A\n C\n F H K\n E\n G\n I\n L M\n"
	
	T2.preorder();
	//Should output "D\n B\n A\n C\n F H K\n E\n G\n I\n L M\n"
	
	T2.inorder();
	//Should output	A B C D E F G H I K L M\n	
	
	cout << *(T2.search("I")) << endl;
	// Should output 4
	
	cout << T1.rank("I") << endl;
	//Should output 9
	
	cout << T1.select(3) << endl;
	//Should output C 
	
	cout << T2.remove("D") << endl;
	//Should output 1
	
	T2.preorder();
	//Should output "F\n B\n A\n C E\n H K\n G\n I\n L M\n"
	
	T2.inorder();
	//Should output	A B C E F G H I K L M\n
	
	cout << T2.remove("J") << endl;
	//Should output 0
	
	T2.preorder();
	//Should output "F\n B\n A\n C E\n H L\n G\n I K\n M\n"    remove("J") modifies the tree
	
	cout <<T2.rank("G") << endl;
	//Should output 6
	
	T2.insert("H",5.1);
	T2.insert("H",5.2);
	T2.insert("H",5.3);

	cout << T2.rank("I") << endl;
	//Should output 11

	cout << T2.remove("H") << endl;
	//Should output 1
	
	cout << *(T2.search("H")) << endl;
	// Should output 5.1
	
	cout << T2.duplicates("H") << endl;
	//Should output 3
	
	T2.inorder();
	//Should output	A B C E F G H H H I K L M\n

	T2.preorder();
	//Should output "F\n B\n A\n C E\n H L\n G\n I K\n M\n"  

	cout << T2.rank("H") << endl;
	//Should output 7
	
	cout << T2.size() << endl;
	//Should output 13
	
    two4Tree<int,int> X;
	for (int i=1;i<1001000;i++) X.insert(i,i);
	for (int i=1;i<1001000;i++) {
		if(X.rank(i) != i) cout << "Rank error" << endl;
		if(X.select(i) != i) cout << "Select error" << endl;
		if(*(X.search(i)) != i) cout << "Search error" << endl;
	}  
	//Should be no output and should take seconds, not minutes
	return 0;
}
