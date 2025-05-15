#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

    public:
    Queue(){
        this->head = NULL;
        this->tail = NULL;
    }

    void push(int data){
      Node* newNode = new Node(data);
      if(isEmpty()){
        head = tail = newNode;
      }else{
        tail->next = newNode;
        tail = newNode;
      }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

class CircularQueue {
    int* arr;
    int capacity;
    int arrSize;
    int f, rear;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        f = 0;
        rear = -1;
        arrSize = 0;
    }

    ~CircularQueue() {
        delete[] arr; // Free memory
    }

    void push(int data) {
        if (arrSize == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        arrSize++;
    }

    int pop() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int frontElement = arr[f]; // Store front value before removing
        f = (f + 1) % capacity;
        arrSize--;

        // Reset f and rear if queue becomes empty
        if (arrSize == 0) {
            f = 0;
            rear = -1;
        }

        return frontElement;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return arrSize == 0;
    }

    void print() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int count = arrSize;
        int index = f;
        while (count--) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};

class ImplementStackUsingQueue{
    queue<int> q1, q2;

    public:
    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        
        int ans = q1.front();
        q1.pop();
        return ans; // FIXED: Return popped element
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

class ImplementQueueUsingStack{
    stack<int> s1, s2;

    public:
    void push(int data){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop(){ // FIXED: Changed void to int
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int front(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};

int main(){
    // ImplementStackUsingQueue s;
    // s.push(1);
    // s.push(2);
    // s.push(3);

    // cout<<s.top()<<endl;
    // s.pop();
    // cout<<s.top()<<endl;

    ImplementQueueUsingStack q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;


    // Queue q;

    // q.push(1);
    // q.push(2);
    // q.push(3);

    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;

    // CircularQueue q(5);

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.print(); // Output: 10 20 30

    // q.pop();
    // q.print(); // Output: 20 30

    // cout << "Front: " << q.front() << endl; // Output: 20


    return 0;
}