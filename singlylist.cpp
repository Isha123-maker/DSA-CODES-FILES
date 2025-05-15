#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    // push_front function
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // push_back function
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // pop_front function
    void pop_front() {
        if (head == NULL) {
            cout << "Can't pop. List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // pop_back function
    void pop_back() {
        if (head == NULL) {
            cout << "Can't pop. List is empty!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // insert function
    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Invalid position!" << endl;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Helper function to create a linked list from an array
    Node* createList(int arr[], int size) {
        Node* newHead = NULL;
        Node* current = NULL;
        for (int i = 0; i < size; i++) {
            Node* newNode = new Node(arr[i]);
            if (newHead == NULL) {
                newHead = current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }
        return newHead;
    }

    // Function to merge two sorted linked lists
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if (list1 == NULL || list2 == NULL) {
            return list1 == NULL ? list2 : list1;
        }

        if (list1->data <= list2->data) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    // Helper function to create a linked list with random pointers
    Node* createRandomList(int values[], int n, int randomIndexes[]) {
        if (n == 0) return NULL;

        Node* head = new Node(values[0]);
        Node* temp = head;
        Node* nodes[n]; // To store pointers to all nodes for setting random pointers

        nodes[0] = head;

        // Create the list
        for (int i = 1; i < n; i++) {
            temp->next = new Node(values[i]);
            temp = temp->next;
            nodes[i] = temp;
        }

        // Set random pointers
        for (int i = 0; i < n; i++) {
            if (randomIndexes[i] != -1) {
                nodes[i]->random = nodes[randomIndexes[i]];
            }
        }

        return head;
    }

    // Function for copying a list with random pointers
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;
        Node* oldTemp = head;
        Node* newHead = new Node(oldTemp->data);
        Node* newTemp = newHead;

        m[oldTemp] = newHead;

        while (oldTemp != NULL) {
            if (oldTemp->next != NULL) {
                if (m.find(oldTemp->next) == m.end()) {
                    m[oldTemp->next] = new Node(oldTemp->next->data);
                }
                newTemp->next = m[oldTemp->next];
            }

            if (oldTemp->random != NULL) {
                if (m.find(oldTemp->random) == m.end()) {
                    m[oldTemp->random] = new Node(oldTemp->random->data);
                }
                newTemp->random = m[oldTemp->random];
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }

    void printLL(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data; // Print the value of the current node
            if (temp->random) {
                cout << " (Random: " << temp->random->data << ")"; // Print the random pointer value
            } else {
                cout << " (Random: NULL)"; // Indicate NULL if no random pointer
            }
            cout << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List listObj;

    // Test case for random list
    int values[] = {1, 2, 3, 4, 5};
    int randomIndexes[] = {4, 3, -1, 1, 0};

    Node* head = listObj.createRandomList(values, 5, randomIndexes);

    cout << "Original List:" << endl;
    listObj.printLL(head);

    Node* copiedList = listObj.copyRandomList(head);
    cout << "\nCopied List:" << endl;
    listObj.printLL(copiedList);

    // // Test case for merging two sorted lists
    // int arr1[] = {1, 3, 5};
    // int arr2[] = {2, 4, 6};
    // Node* list1 = listObj.createList(arr1, 3);
    // Node* list2 = listObj.createList(arr2, 3);

    // cout << "\nList 1: ";
    // listObj.printLL(list1);
    // cout << "List 2: ";
    // listObj.printLL(list2);

    // Node* mergedList = listObj.mergeTwoLists(list1, list2);
    // cout << "Merged List: ";
    // listObj.printLL(mergedList);

    return 0;
}
