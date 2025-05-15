#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val){
      data = val;
      next = NULL;
    }
};

class CircularLinkedList {
   Node* head;
   Node* tail;

   public:
    CircularLinkedList(){
        head = tail = NULL;
    }

    //function for insert node at head
    void insertAtHead(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

    }

    //function for insert node at tail
    void insertAtTail(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    //function for delete node at head
    void deleteAtHead(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            
            temp->next = NULL;
            delete temp;
        }
    }

    //function for delete node at tail
    void  deleteAtTail(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = tail;
            
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    //function for printing list
    void printCl(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        cout<<head->data<<" -> ";
        Node* temp = head->next;
        

        while(temp!=head){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<temp->data<<endl;
    }
};

int main(){
    CircularLinkedList cl;

    cl.insertAtHead(10);
    cl.insertAtHead(20);
    cl.insertAtHead(30);
    cl.insertAtHead(40);

    cl.printCl();

   
    cl.deleteAtTail();
    cl.printCl();
    
    return 0;
}