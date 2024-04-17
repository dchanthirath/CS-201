#include <iostream>

// Define the Node struct outside of the CircularDoublyLinkedList class
template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class CircularDoublyLinkedList {
private:
    Node<T>* minNode; // Pointer to the node with the minimum value

public:
    CircularDoublyLinkedList() {
        minNode = nullptr;
    }

    // Method to insert a new node to the left of the minimum node
    void insertToLeftOfMin(const T& value) {
        Node<T>* newNode = new Node<T>();
        newNode->data = value;
        if (minNode == nullptr) {
            // If the list is empty, set the new node as both the minimum node and its neighbor
            minNode = newNode;
            newNode->left = newNode;
            newNode->right = newNode;
        } else {
            // Insert the new node to the left of the minimum node
            newNode->left = minNode->left;
            newNode->right = minNode;
            minNode->left->right = newNode;
            minNode->left = newNode;

            // Update minNode if the inserted node has a smaller value
            if (value < minNode->data) {
                minNode = newNode;
            }
        }
    }

    // Method to print the contents of the list starting from the minimum node and moving to the right
    void displayFromMin() {
        if (minNode == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node<T>* current = minNode;
        do {
            std::cout << current->data << " ";
            current = current->right;
        } while (current != minNode);
        std::cout << std::endl;
    }

    // Destructor to free memory allocated for nodes
    ~CircularDoublyLinkedList() {
        if (minNode == nullptr) return;

        Node<T>* current = minNode;
        Node<T>* nextNode = nullptr;
        do {
            nextNode = current->right;
            delete current;
            current = nextNode;
        } while (current != minNode);
    }
};

int main() {
    CircularDoublyLinkedList<int> list;

    // Insert some elements into the list
    list.insertToLeftOfMin(4);
    list.insertToLeftOfMin(2);
    list.insertToLeftOfMin(6);
    list.insertToLeftOfMin(1);

    // Display the contents of the list starting from the minimum node
    list.displayFromMin();

    return 0;
}
