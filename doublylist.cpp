#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class doublyList {
    Node* head;
    Node* tail;

    public:
     doublyList() {
        head = tail = NULL;
     }
     
     //function for push_front
     void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
     }

     //function for push_back
     void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //function for pop_front
     void pop_front() {
        if(head == NULL){
            cout<<"List is empty"<<endl;
        }

        Node* temp = head;
        head = head->next;

        if(head != NULL){
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    //function for pop_back
    void pop_back() {
        if(head == NULL){
            cout<<"List is empty"<<endl;
        }

        Node* temp = tail;
        tail = tail->prev;

        if(tail != NULL){
            tail->next = NULL;
        }

        temp->prev = NULL;
        delete temp;
    }
    
    //function for flatten a doubly linked list
    Node* flattenChildNode(Node* head){
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
           if(curr->child != NULL){
              Node* next = curr->next;
              curr->next = flatten(curr->child);
              curr->next->prev = curr;
              curr->child = NULL;
            

            while(curr->next != NULL){
                curr = curr->next;
            }

            if(next != NULL){
                curr->next = next;
                next->prev = curr;
            }
            }
            curr = curr->next;
        }
        return head;
    
    }

    //function for swap k nodes in a doubly linked list
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while(count<k){
            if(temp == NULL){
                return head;
            }

            temp = temp->next;
            count++;
        }
        
        ListNode* prevNode = reverseKGroup(temp , k);

        temp = head;
        count = 0;
        while(count<k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;

            count++;
        }
        return prevNode;
    }

    //function for printing list
    void print(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" => ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        cout<<endl;
    }
};

int main() {
    doublyList l;

    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);
    l.push_front(50);

    l.push_back(60);

    l.pop_back();


    l.print();
    return 0;
}