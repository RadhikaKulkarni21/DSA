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
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
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
    
        int getLength() {
            return length;
        }

        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
            length++;
        }
        
        void reverseBetween(int startIndex, int endIndex) {
            /*
            Write a method reverseBetween(int startIndex, int endIndex) 
            that reverses the nodes of a doubly linked list between 
            the given start and end indices, inclusive.
            */
            // - A dummy node is used to simplify edge cases  
            //   when reversing from the head.                
            // - `prev` is positioned just before the reversal
            //   section.                                     
            // - Nodes are extracted one by one and moved to the 
            //   front of the sublist, reversing the segment. 
            // - All `.next` and `.prev` pointers are correctly  
            //   updated during each step.                    
            // - Updates the list's head and deletes dummy node. 
                // Return early if list is empty or no range to reverse
            if (head == nullptr || startIndex == endIndex) return;
        
            // Dummy node simplifies edge case handling
            Node* dummy = new Node(0);
            dummy->next = head;
            head->prev = dummy;
        
            // Traverse to node BEFORE start index
            Node* prev = dummy;
            for (int i = 0; i < startIndex; i++) {
                prev = prev->next;
            }
        
            // 'current' is the start of the sublist to reverse
            Node* current = prev->next;
        
            // Reverse using node splicing
            for (int i = 0; i < endIndex - startIndex; i++) {
                Node* temp = current->next;
        
                // Detach temp
                current->next = temp->next;
                if (temp->next) {
                    temp->next->prev = current;
                }
        
                // Insert temp after prev
                temp->next = prev->next;
                prev->next->prev = temp;
                prev->next = temp;
                temp->prev = prev;
            }
        
            // Update head in case it changed
            head = dummy->next;
            head->prev = nullptr;
        
            delete dummy;
        }
};

int main(){
    DoublyLinkedList dll1(3);
    dll1.append(8); dll1.append(5); dll1.append(10); dll1.append(2); dll1.append(1);
    cout << "Before: ";
    dll1.printList();
    dll1.reverseBetween(1, 4);
    cout << "After:  ";
    dll1.printList();
}