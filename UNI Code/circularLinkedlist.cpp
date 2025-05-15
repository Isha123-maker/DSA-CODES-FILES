#include <iostream>
using namespace std;

/* Node class for the circular linked list */
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

/* Circularly linked list class */
class CList {
public:
    CList();
    ~CList();
    void add(int value);
    void start();
    bool next();
    int get();
    void remove();
    int length();

private:
    Node* head;
    Node* tail;
    Node* current;
    int size;
};

/* Constructor */
CList::CList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    size = 0;
}

/* Destructor */
CList::~CList() {
    if (head != nullptr) {
        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
}

/* Add a new element to the circular list */
void CList::add(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = head; // Points to itself, making it circular.
    } else {
        tail->next = newNode;
        newNode->next = head; // The new node points to head, maintaining circularity.
        tail = newNode;
    }
    size++;
}

/* Start traversal from the beginning */
void CList::start() {
    current = head;
}

/* Move to the next node */
bool CList::next() {
    if (current == nullptr || current->next == nullptr) {
        return false;
    }
    current = current->next;
    return true;
}

/* Get the value of the current node */
int CList::get() {
    if (current != nullptr) {
        return current->data;
    }
    return -1; // Sentinel value if current is nullptr.
}

/* Remove the current node */
void CList::remove() {
    if (current == nullptr || size == 0) {
        return;
    }

    Node* prev = head;
    while (prev->next != current) {
        prev = prev->next;
    }

    if (current == head) {
        head = head->next;
        tail->next = head;
    }
    if (current == tail) {
        tail = prev;
        tail->next = head;
    }

    prev->next = current->next;
    delete current;
    current = prev->next;
    size--;
}

/* Get the current size of the list */
int CList::length() {
    return size;
}

/* Main method to solve the Josephus problem */
int main() {
    CList list;
    int N = 10, M = 3;  // N = number of people, M = step count
    for (int i = 1; i <= N; i++) {
        list.add(i);
    }

    list.start();  // Set current to the first element

    // Counting up to M times and removing the element
    while (list.length() > 1) {
        for (int i = 1; i < M; i++) {
            list.next();  // Move to the next element M-1 times
        }
        cout << "Removing: " << list.get() << endl;
        list.remove();  // Remove the current node
    }

    cout << "Leader is: " << list.get() << endl;  // The last remaining element is the leader
    return 0;
}
