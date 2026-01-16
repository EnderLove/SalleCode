#include <iostream>
    
class Node{
private:
    int val;
    Node *next;
public:
    Node(int val, Node *next = nullptr): val(val), next(next){}

    Node *getNext() {return next;}
    int   getVal()  {return val; }

    void setNext (Node* next) {this->next = next;}
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList() : head(nullptr){} 
    ~LinkedList() { std::cout << "OBJ DESTROYED!" << std::endl; }; 

    void insert (int val){
        head = new Node(val, head); 
    }

    void insertEnd(int val){
        Node *newNode= new Node(val);
        
        if (head == nullptr){
            head = newNode;
            return;
        }

        Node *temp = head;
        
        while (temp->getNext() != nullptr) temp = temp->getNext(); 
        temp->setNext(newNode);
    }
    
    void printList(){
        Node *temp = head;
        while (temp != nullptr){
            std::cout << "VAL: " << temp->getVal() << std::endl; 
            temp = temp->getNext(); 
        }
    }

    void deleteList(){
        Node *temp = nullptr;
        temp = head;
        head = head->getNext();
        delete(temp);
    }
};

// Add search, addPos, delPos functions
// Look page 33 DS C++

int main(){

    LinkedList test;
    
    test.insert(10);
    test.insert(11);
    test.insert(12);
    test.insert(13);
    test.insert(14);
    test.insertEnd(100);

    test.printList();

    test.deleteList();
    return 0;
}
