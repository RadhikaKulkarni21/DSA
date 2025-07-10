#include <iostream>

using namespace std;

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
Implement a member function called swapPairs() 
that swaps the values of every two adjacent nodes in the list.
*/                                           
        // - Utilizes a dummyNode to simplify edge cases.   
        // - Uses pointers to navigate and swap nodes.      
        // - Pay close attention to the 'next' and 'prev'   
        //   pointers of the nodes.                         
        // - Works in-place; doesn't create new nodes.      
        // - Always checks if the list is empty or has only one node.                                      

        void swapPairs(){
            Node* dummy = new Node(0);
            dummy->next = head;
    
            Node* previous = dummy;
            Node* first = head;
    
            while (first != nullptr && first->next != nullptr) {
                Node* second = first->next;
    
                previous->next = second;
                first->next = second->next;
                second->next = first;
    
                previous = first;
                first = first->next;
            }
            head = dummy->next;
            delete dummy;
    }   

};

int main(){
            cout << "\n----- Test: Swap Pairs with Multiple Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
}