#include <iostream>

using namespace std;

// Node structure for Fibonacci Heap
struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool marked;
};

class FibonacciHeap {
private:
    Node* minNode;
    int numNodes;
    static const int MAX_DEGREE;

public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}

    bool isEmpty() const {
        return minNode == nullptr;
    }

    void insert(int key) {
        Node* newNode = createNode(key);
        if (minNode == nullptr) {
            minNode = newNode;
        } else {
            insertNode(minNode, newNode);
            if (newNode->key < minNode->key) {
                minNode = newNode;
            }
        }
        numNodes++;
    }

    int getMin() const {
        if (isEmpty()) {
            cerr << "Heap is empty" << endl;
            return -1;
        }
        return minNode->key;
    }

    int extractMin() {
        if (isEmpty()) {
            cerr << "Heap is empty" << endl;
            return -1;
        }
        Node* oldMin = minNode;
        if (minNode->child != nullptr) {
            // Attach children of min node to the root list
            Node* child = minNode->child;
            do {
                Node* nextChild = child->right;
                insertNode(minNode, child);
                child->parent = nullptr;
                child = nextChild;
            } while (child != minNode->child);
        }
        // Remove min node from the root list
        removeNode(oldMin);
        if (oldMin == oldMin->right) {
            minNode = nullptr;
        } else {
            minNode = oldMin->right;
            consolidate();
        }
        numNodes--;
        int minKey = oldMin->key;
        delete oldMin;
        return minKey;
    }

private:
    Node* createNode(int key) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->degree = 0;
        newNode->parent = nullptr;
        newNode->child = nullptr;
        newNode->left = newNode;
        newNode->right = newNode;
        newNode->marked = false;
        return newNode;
    }

    void insertNode(Node* root, Node* newNode) {
        newNode->left = root->left;
        newNode->right = root;
        root->left->right = newNode;
        root->left = newNode;
    }

    void removeNode(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }

    void consolidate() {
        Node* degreeTable[MAX_DEGREE] = {nullptr};
        Node* nodesToVisit[MAX_DEGREE] = {nullptr};

        Node* currNode = minNode;
        int numRoots = 0;

        // Count the number of root nodes
        do {
            numRoots++;
            currNode = currNode->right;
        } while (currNode != minNode);

        // Traverse the root list and merge trees with the same degree
        while (numRoots > 0) {
            Node* x = currNode;
            int degree = x->degree;
            currNode = currNode->right;

            while (nodesToVisit[degree] != nullptr) {
                Node* y = nodesToVisit[degree];
                if (x->key > y->key) {
                    swap(x, y);
                }
                link(y, x);
                nodesToVisit[degree] = nullptr;
                degree++;
            }
            nodesToVisit[degree] = x;
            numRoots--;
        }

        minNode = nullptr;

        // Reconstruct the root list
        for (int i = 0; i < MAX_DEGREE; ++i) {
            if (nodesToVisit[i] != nullptr) {
                if (minNode == nullptr) {
                    minNode = nodesToVisit[i];
                } else {
                    insertNode(minNode, nodesToVisit[i]);
                    if (nodesToVisit[i]->key < minNode->key) {
                        minNode = nodesToVisit[i];
                    }
                }
            }
        }
    }

    void link(Node* child, Node* parent) {
        // Remove child from root list
        removeNode(child);

        // Make child a child of parent
        child->parent = parent;
        if (parent->child == nullptr) {
            parent->child = child;
            child->left = child->right = child;
        } else {
            insertNode(parent->child, child);
        }
        parent->degree++;
        child->marked = false;
    }
};

int main() {
    FibonacciHeap heap;

    // Insert elements into the heap
    heap.insert(5);
    heap.insert(10);
    heap.insert(3);
    heap.insert(7);

    // Extract and print minimum element
    cout << "Minimum element: " << heap.extractMin() << endl;

    // Get and print minimum element
    cout << "Minimum element: " << heap.getMin() << endl;

    return 0;
}
