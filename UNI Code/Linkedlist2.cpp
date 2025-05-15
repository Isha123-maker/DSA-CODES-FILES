#include <iostream>
using namespace std;

/* The Node class */
class Node {
public:
    int get() { return object; }
    void set(int object) { this->object = object; }

    Node* getNext() { return nextNode; }
    void setNext(Node* nextNode) { this->nextNode = nextNode; }

private:
    int object;
    Node* nextNode;
};

/* The List class */
class List {
public:
    List();
    ~List();  // Destructor to free memory.
    void add(int addObject);
    int get();
    bool next();
    void traverse();
    void reset();  // It is the same as the start method.
    void remove(); // Method to remove the current node.
    int length();  // Method to get the length of the list.

private:
    Node* headNode;
    Node* currentNode;
    Node* lastCurrentNode; // Pointer to keep track of the node before currentNode.
    int size; // To keep track of the list's size.
};

/* Constructor */
List::List() {
    headNode = new Node();
    headNode->setNext(nullptr);
    currentNode = nullptr;
    lastCurrentNode = nullptr;
    size = 0;
}

// Destructor for the List class
List::~List() {
    Node* currentNode = headNode;
    while (currentNode != nullptr) {
        Node* nextNode = currentNode->getNext();    // Save the next node.
        delete currentNode;                         // Delete the current node.
        currentNode = nextNode;                     // Move to the next node.
    }
}

/* add() class method */
void List::add(int addObject) {
    Node* newNode = new Node();
    newNode->set(addObject);
    newNode->setNext(nullptr);

    if (currentNode != nullptr) {
        currentNode->setNext(newNode);
    } else {
        headNode->setNext(newNode);
    }

    lastCurrentNode = currentNode; // Update the lastCurrentNode.
    currentNode = newNode;
    size++;
}

/* get() class method */
int List::get() {
    if (currentNode != nullptr)
        return currentNode->get();
    else
        return -1; // Return a sentinel value if currentNode is nullptr.
}

/* next() class method */
bool List::next() {
    if (currentNode == nullptr) return false;

    lastCurrentNode = currentNode; // Store the current node as lastCurrentNode.
    currentNode = currentNode->getNext();
    return currentNode != nullptr;
}

/* Method to traverse and print the list */
void List::traverse() {
    reset(); // Start from the first real node.
    int i = 1;
    while (currentNode != nullptr) {
        cout << "Element " << i << ": " << currentNode->get() << endl;
        next(); // Move to the next node while updating lastCurrentNode.
        i++;
    }
}

/* Reset currentNode to start from the beginning */
void List::reset() {
    lastCurrentNode = nullptr;         // Reset the lastCurrentNode.
    currentNode = headNode->getNext(); // Start from the first real node.
}

/* Method to remove the current node */
void List::remove() {
    if (currentNode != nullptr && lastCurrentNode != nullptr) {
        lastCurrentNode->setNext(currentNode->getNext());
        delete currentNode;
        currentNode = lastCurrentNode->getNext();
        size--;
    } else if (currentNode != nullptr && lastCurrentNode == nullptr) {
        // Removing the first real node (headNode->getNext()).
        headNode->setNext(currentNode->getNext());
        delete currentNode;
        currentNode = headNode->getNext();
        size--;
    }
}

/* Method to get the length of the list */
int List::length() {
    return size;
}

int main() {
    List list;

    // Adding elements to the list.
    list.add(2);
    list.add(6);
    list.add(8);
    list.add(7);
    list.add(5);

    // Traverse and print all elements.
    cout << "Traversing the list:" << endl;
    list.traverse();

    // Reset currentNode to start again and iterate manually.
    list.reset();
    cout << "\nIterating through the list using a loop:" << endl;
    do {
        int value = list.get();
        cout << "Next value: " << value << endl;
    } while (list.next());

    // Display the length of the list.
    cout << "\nLength of the list: " << list.length() << endl;

    // Reset and remove the second element for demonstration.
    list.reset();
    list.next(); // Move to the second element.
    list.remove();
    cout << "\nAfter removing the second element:" << endl;
    list.traverse();

    cout << "\nLength of the list after removal: " << list.length() << endl;

    return 0;
}
