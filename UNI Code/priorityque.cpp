#include <iostream>
#define PQMAX 30

// Event class with priority attribute
class Event {
private:
    int priority; // Priority value

public:
    Event(int p) : priority(p) {}

    int getPriority() const {
        return priority;
    }
};

// PriorityQueue class
class PriorityQueue {
private:
    Event* nodes[PQMAX]; // Array to hold Event pointers
    int size;            // Current number of elements
    int rear;            // Last element position

    // Private helper function to sort elements in ascending order based on priority
    void sortElements() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nodes[i]->getPriority() > nodes[j]->getPriority()) {
                    Event* temp = nodes[i];
                    nodes[i] = nodes[j];
                    nodes[j] = temp;
                }
            }
        }
    }

public:
    PriorityQueue() : size(0), rear(-1) {}

    bool full() const {
        return size == PQMAX;
    }

    bool empty() const {
        return size == 0;
    }

    Event* remove() {
        if (!empty()) {
            Event* e = nodes[0];
            for (int j = 0; j < size - 1; j++) {
                nodes[j] = nodes[j + 1];
            }
            size--;
            rear--;
            if (size == 0) rear = -1; // Reset rear when empty
            return e;
        }
        std::cout << "remove - queue is empty." << std::endl;
        return nullptr;
    }

    bool insert(Event* e) {
        if (!full()) {
            rear++;
            nodes[rear] = e;
            size++;
            sortElements(); // Sort after inserting to maintain priority order
            return true;
        }
        std::cout << "insert - queue is full." << std::endl;
        return false;
    }

    int length() const {
        return size;
    }
};

// Main function for testing
int main() {
    PriorityQueue pq;

    // Creating events with different priorities
    Event* event1 = new Event(3); // Priority 3
    Event* event2 = new Event(1); // Priority 1
    Event* event3 = new Event(2); // Priority 2

    // Insert events
    pq.insert(event1);
    pq.insert(event2);
    pq.insert(event3);

    // Display queue length
    std::cout << "Queue length: " << pq.length() << std::endl;

    // Remove elements based on priority
    Event* removedEvent;
    while ((removedEvent = pq.remove()) != nullptr) {
        std::cout << "Removed event with priority: " << removedEvent->getPriority() << std::endl;
        delete removedEvent; // Free memory for removed event
    }

    return 0;
}
