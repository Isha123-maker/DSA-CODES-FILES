#include <iostream>
using namespace std;

// Node class for the stack
class Node {
private:
    int data;
    Node* next;
public:
    void set(int x) {
        data = x;
    }

    int get() {
        return data;
    }

    void setNext(Node* ptr) {
        next = ptr;
    }

    Node* getNext() {
        return next;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* head; // Top of the stack

public:
    Stack() : head(nullptr) {} // Constructor initializes the head to nullptr

    // Function to push an element onto the stack
    void push(int x) {
        Node* newNode = new Node();
        newNode->set(x);
        newNode->setNext(head);
        head = newNode;
    }

    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Returning -1 to indicate an error
        }

        int x = head->get();
        Node* p = head;
        head = head->getNext();
        delete p;
        return x;
    }

    // Function to get the top element of the stack without removing it
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Returning -1 to indicate an error
        }

        return head->get();
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (head == nullptr);
    }

    // Destructor to clean up the memory used by the stack
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element after pop: " << s.top() << endl;

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.pop();
    s.pop();

    cout << "Is stack empty after popping all elements? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
