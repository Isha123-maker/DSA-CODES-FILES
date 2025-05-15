#include <iostream>
#include <vector>
#include <list>
using namespace std;

class StackVector {
    vector<int> vec;

public:
    void push(int val) {
        vec.push_back(val);
    }

    void pop() {
        if (vec.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            vec.pop_back();
        }
    }

    int top() {
        if (vec.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return vec.back();
    }

    bool isEmpty() {
        return vec.empty();
    }
};

class StackList {
    list<int> ll;

public:
    void push(int val) {
        ll.push_front(val);
    }

    void pop() {
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            ll.pop_front();
        }
    }

    int top() {
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return ll.front();
    }

    bool isEmpty() {
        return ll.empty();
    }
};

int main() {
    StackVector s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.isEmpty()) {  // Fixed function call
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}