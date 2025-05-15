#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
        oldNext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->value;

        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode;
        }

        if (m.size() == limit) {
            Node* oldNode = tail->prev;
            m.erase(oldNode->key);
            delNode(oldNode);
            delete oldNode;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

// ======= TESTING THE LRU CACHE =======
int main() {
    cout << "Testing LRUCache with capacity 2\n";
    LRUCache cache(2); // Capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Get 1: " << cache.get(1) << " (Expected: 10)\n"; // Should return 10
    cout << "Get 2: " << cache.get(2) << " (Expected: 20)\n"; // Should return 20

    cache.put(3, 30); // Removes key 1 (Least Recently Used)
    cout << "Get 1: " << cache.get(1) << " (Expected: -1, as 1 was evicted)\n"; // Should return -1

    cache.put(4, 40); // Removes key 2 (Least Recently Used)
    cout << "Get 2: " << cache.get(2) << " (Expected: -1, as 2 was evicted)\n"; // Should return -1
    cout << "Get 3: " << cache.get(3) << " (Expected: 30)\n"; // Should return 30
    cout << "Get 4: " << cache.get(4) << " (Expected: 40)\n"; // Should return 40

    cache.put(3, 35); // Update key 3
    cout << "Get 3: " << cache.get(3) << " (Expected: 35, as key 3 was updated)\n"; // Should return 35

    return 0;
}
