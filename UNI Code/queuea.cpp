#include <iostream>

class CircularQueue {
public:
    CircularQueue(int size);
    ~CircularQueue();
    void enqueue(int x);
    int dequeue();
    int front() const;
    bool isFull() const;
    bool isEmpty() const;

private:
    int* array;
    int frontIndex;
    int rearIndex;
    int noElements;
    int capacity;
};

CircularQueue::CircularQueue(int size) 
    : capacity(size), frontIndex(0), rearIndex(-1), noElements(0) {
    array = new int[capacity];
}

CircularQueue::~CircularQueue() {
    delete[] array;
}

void CircularQueue::enqueue(int x) {
    if (isFull()) {
        std::cerr << "Queue overflow: Cannot enqueue " << x << "\n";
        return;
    }
    rearIndex = (rearIndex + 1) % capacity;
    array[rearIndex] = x;
    noElements++;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue underflow: Cannot dequeue\n";
        return -1; // Or throw an exception
    }
    int x = array[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    noElements--;
    return x;
}

int CircularQueue::front() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty\n";
        return -1; // Or throw an exception
    }
    return array[frontIndex];
}

bool CircularQueue::isFull() const {
    return noElements == capacity;
}

bool CircularQueue::isEmpty() const {
    return noElements == 0;
}

int main() {
    CircularQueue q(5); // Queue of capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    std::cout << "Front element: " << q.front() << "\n";

    std::cout << "Dequeue: " << q.dequeue() << "\n";
    std::cout << "Dequeue: " << q.dequeue() << "\n";

    q.enqueue(60);
    q.enqueue(70);

    std::cout << "Front element after enqueues: " << q.front() << "\n";

    std::cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << "\n";
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
