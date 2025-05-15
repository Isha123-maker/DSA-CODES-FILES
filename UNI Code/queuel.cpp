#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value = 0) : data(value), next(nullptr) {}

    int get() const { return data; }
    void set(int value) { data = value; }
    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }
};

class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    int front() const;
    bool isEmpty() const;

private:
    Node* frontNode;
    Node* rear;
};

Queue::Queue() : frontNode(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int x) {
    Node* newNode = new Node(x);
    newNode->setNext(nullptr);

    if (rear != nullptr) {
        rear->setNext(newNode);
    }
    rear = newNode;

    if (frontNode == nullptr) {
        frontNode = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue underflow in dequeue.\n";
        return -1; // Or throw an exception
    }

    int x = frontNode->get();
    Node* temp = frontNode;
    frontNode = frontNode->getNext();
    delete temp;

    if (frontNode == nullptr) {
        rear = nullptr; // Queue is empty
    }

    return x;
}

int Queue::front() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty.\n";
        return -1; // Or throw an exception
    }
    return frontNode->get();
}

bool Queue::isEmpty() const {
    return frontNode == nullptr;
}

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.front() << std::endl;

    std::cout << "Dequeue: " << q.dequeue() << std::endl;
    std::cout << "Dequeue: " << q.dequeue() << std::endl;

    std::cout << "Front element after dequeues: " << q.front() << std::endl;

    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
