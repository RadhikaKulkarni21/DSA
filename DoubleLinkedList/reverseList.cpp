#include "R:\C++\Project1\lcHeader.h"

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        
/*
Implement a member function called reverse() that reverses the order 
of the nodes in the list.

Input:
The function is a member of the DoublyLinkedList class, 
which has a head and a tail pointer, as well as a length attribute.
*/                                              
        //    - Create two pointers: current and temp.            
        //    - Loop through the list swapping next and prev      
        //      for each node.                                    
        //    - After loop, swap head and tail pointers.          


        void reverse(){//expample 1<->2
            Node* current = head;//current = 1
            Node* temp = nullptr;
            while(current != nullptr){
                //just swap prev with next because DLL so no breaks
                temp = current->prev; 
                current->prev = current->next;
                current->next = temp;
                current = current->prev;//move to the next node
            }
            temp = head;//store temporarily
            head = tail;//now head is the tail because reverse
            tail = temp;//tail is head because reverse
        }   
};

int main(){
    DoublyLinkedList list(1);
    list.append(2);
    list.printList();
    list.reverse();
    list.printList();
}