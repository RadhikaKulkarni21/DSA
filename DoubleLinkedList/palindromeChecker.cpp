#include "R:\C++\Project1\lcHeader.h"


class DoublyLinkedList {
    public:
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
Implement a member function called isPalindrome() that checks 
if the list is a palindrome, i.e., 
its elements read the same forward and backward.

Input:
The function is a member of the DoublyLinkedList class, which has a head and a tail 
pointer, as well as a length attribute.

Output:
The function should return a boolean value indicating whether the 
doubly linked list is a palindrome or not.

Constraints:
The doubly linked list may be empty, have only one node, or have two or more nodes.

Example:

Consider the following doubly linked list:

Head: 1
Tail: 1
Length: 5
 
Doubly Linked List:
1 <-> 2 <-> 3 <-> 2 <-> 1
After calling isPalindrome(), the result should be true as the list is a palindrome.

*/

bool isPalindrome(){
    if(length == 0)return true;
        if(length == 1)return true;
        Node* forwardNode = head;
        Node* backwardNode = tail;
            //Only iterating through half because from mid-point its gotta be same
        for(int i = 0; i<= length/2;i++){
            if(forwardNode->value != backwardNode->value) return false;
            forwardNode = forwardNode->next;
            backwardNode = backwardNode->prev;
        }
        return true;
    }
};

int main(){
    //DoublyLinkedList* newDll = new DoublyLinkedList(1);
    DoublyLinkedList dll(1);
    dll.append(2);
    dll.append(3);
    dll.append(2);
    dll.append(0);//dll.append(1);
    dll.printList();
    bool result = dll.isPalindrome();
    cout<<"Result:"<<result<<endl;
}