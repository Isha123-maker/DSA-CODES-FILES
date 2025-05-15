#include<iostream>
using namespace std;

  //Node class functions on node
class Node{
    public:

        int get(){return object;}  //return value of data element of node
        void set(int object){this->object =  object;}  //assign new value to data element of node

        Node* getNext(){return nextNode;}  //return address of next node
        void setNext(Node* nextNode){this->nextNode = nextNode;}  //assign new address of next node

    private:

        int object;
        Node* nextNode;

};

  //List class for operations on linked list
class List{
    public:

        List();  //constructor make a new node when called
        ~List();  //destructor for free allocate memory
        void add(int addObject);  //add new data element to list
        int get();  //return value of current Node
        bool next();  //advance current Node to next Node
        void traverse();  //traverse through each data element of list
        void reset();  //reset current Node to first Node

    private:
        Node* headNode;
        Node* currentNode;

};

  //Constructor
List::List(){
    headNode = new Node();
    headNode->setNext(NULL);
    currentNode = NULL;
}

  //Destructor
List::~List(){
    Node* currentNode = headNode;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->getNext();    // Save the next node
        delete currentNode;                        // Delete the current node
        currentNode = nextNode;                   // Move to the next node
    }
}

  //add method
void List::add(int addObject){
    Node* newNode = new Node();
    newNode->set(addObject);
    newNode->setNext(NULL);
    if(currentNode != NULL){
        currentNode->setNext(newNode);
    }
    else{
        headNode->setNext(newNode);
    }
    currentNode = newNode;

}

  //get method
int List::get(){
    if(currentNode != NULL){
        return currentNode->get();
    }
    else
    return -1;
     
}

  //next method
bool List::next(){
    if(currentNode == NULL) return false;
    currentNode = currentNode->getNext();
    return currentNode != NULL;
}

  //traverse method
void List::traverse(){
  currentNode = headNode->getNext();
  int i = 1;
  while(currentNode != NULL){
    cout << "Element " << i << " : " << currentNode->get() << endl;
    currentNode = currentNode->getNext();
    i++;
  }
}

  //reset method
void List::reset(){
  currentNode = headNode->getNext();
}

int main(){

  List list;

  list.add(2);
  list.add(3);
  list.add(4);
  list.add(5);
  list.add(6);
  list.add(7);
  
  cout << "Traversing the list:" << endl;
  list.traverse();

  list.reset();
  cout << "\nIterarating through the loop using get and next method:" << endl;

  do{
    int value = list.get();
    cout << "Next Value : " << value << endl;
  }while(list.next());
  return 0;


}