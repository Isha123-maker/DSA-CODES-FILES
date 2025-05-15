#include <iostream>
using namespace std;

class Product {
private:
    int data;
    Product* next;
    int productId;

public:
    int get() const { return data; }
    void set(int d) { data = d; }
    Product* getNext() const { return next; }
    void setNext(Product* nextNode) { next = nextNode; }
    int getProductId() const { return productId; }
    void setProductId(int pid) { productId = pid; }
};

class Stack {
private:
    Product* head;

public:
    Stack() : head(nullptr) {}

    void push(int x) {
        Product* newProduct = new Product();
        newProduct->set(x);
        newProduct->setNext(head);
        head = newProduct;
        cout << "Pushed digit " << x << " onto the stack." << endl;
    }

    int top() const {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return head->get();
    }

    int pop() {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        int topData = head->get();
        Product* temp = head;
        head = head->getNext();
        delete temp;
        return topData;
    }

    ~Stack() {
        while (head != nullptr) {
            Product* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

int main() {
    Product product;
    int studentIdSuffix = 70;  // Replace with your actual student ID last two digits
    int productId = 2400 + studentIdSuffix;

    product.setProductId(productId);

    cout << "---------------------------------------------" << endl;
    cout << "The Product id is: " << product.getProductId() << endl;
    cout << "---------------------------------------------" << endl;

    int tempId = product.getProductId();
    Stack stack;

    // Pushing each digit onto the stack
    while (tempId > 0) {
        int digit = tempId % 10;
        stack.push(digit);
        tempId /= 10;
    }

    cout << "---------------------------------------------" << endl;
    cout << "The Top element of the stack is : " << stack.top() << endl;
    cout << "---------------------------------------------" << endl;

    // Popping two elements and displaying each
    cout << "The First element poped from the stack is: " << stack.pop() << endl;
    cout << "The Second element poped from the stack is: " << stack.pop() << endl;

    cout << "---------------------------------------------" << endl;
    cout << "The Top element of the stack is : " << stack.top() << endl;
    cout << "---------------------------------------------" << endl;

    return 0;
}
