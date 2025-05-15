#include <iostream>
#include <memory>

constexpr int MAXSTACKSIZE = 50;

template <class T>
class Stack {
public:
    Stack();
    ~Stack();
    bool empty() const;
    bool push(const T& x);
    T pop();

private:
    int top;
    std::unique_ptr<T[]> nodes;
};

template <class T>
Stack<T>::Stack() : top(-1), nodes(std::make_unique<T[]>(MAXSTACKSIZE)) {}

template <class T>
Stack<T>::~Stack() = default;

template <class T>
bool Stack<T>::empty() const {
    return top < 0;
}

template <class T>
bool Stack<T>::push(const T& x) {
    if (top < MAXSTACKSIZE - 1) {
        nodes[++top] = x;
        return true;
    }
    std::cout << "Stack overflow in push.\n";
    return false;
}

template <class T>
T Stack<T>::pop() {
    if (!empty()) {
        return nodes[top--];
    }
    std::cout << "Stack underflow in pop.\n";
    return T{}; // Return a default-constructed T in case of underflow
}

int main() {
    Stack<int> intstack;
    Stack<char> charstack;
    int x = 10, y = 20;
    char c = 'C', d = 'D';

    intstack.push(x);
    intstack.push(y);
    std::cout << "intstack: " << intstack.pop() << ", " << intstack.pop() << "\n";

    charstack.push(c);
    charstack.push(d);
    std::cout << "charstack: " << charstack.pop() << ", " << charstack.pop() << "\n";

    return 0;
}
