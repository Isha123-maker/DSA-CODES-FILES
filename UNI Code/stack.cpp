#include <iostream>
using namespace std;

/* The Stack class */
class Stack {
public:
    Stack() : size(10), current(-1) {} // Constructor using initializer list

    int pop() {
        if (!isEmpty()) {
            return A[current--];
        } else {
            cout << "\n Stack is empty, can't pop";
            return -1; // Return an invalid value or throw an exception if desired
        }
    }

    void push(int x) {
        if (!isFull()) {
            A[++current] = x;
        } else {
            cout << "\n Stack is full, can't insert new element";
        }
    }

    int top() {
        if (!isEmpty()) {
            return A[current];
        } else {
            cout << "\n Stack is empty, no top element";
            return -1; // Return an invalid value or throw an exception if desired
        }
    }

    bool isEmpty() {
        return (current == -1);
    }

    bool isFull() {
        return (current == size - 1);
    }

private:
    int current;       // Index of the array
    int size;          // Max size of the array
    int A[10];         // Array of 10 elements
};

// The main method
int main() {
    Stack stack; // Creating a stack object

    // Pushing the 10 elements to the stack
    for (int i = 0; i < 12; i++) {
        stack.push(i); // Push the element at the top
    }

    // Popping the elements from the stack
    for (int i = 0; i < 12; i++) {
        int poppedElement = stack.pop();
        if (poppedElement != -1) {
            cout << "\n The popped element = " << poppedElement;
        }
    }

    return 0;
}
