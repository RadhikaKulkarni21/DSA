//Zero idea what is going on in this code - skip it
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

/*
Write a method called partitionList that rearranges the nodes in a 
doubly linked list so that all nodes with values less than a given integer x 
appear before nodes with values greater than or equal to x.

The original relative order of the nodes in each partition should be preserved.

The partitioning must be done in-place using dummy nodes and pointer manipulation.

Example
Input:
3 <-> 8 <-> 5 <-> 10 <-> 2 <-> 1, x = 5
Output:
3 <-> 2 <-> 1 <-> 8 <-> 5 <-> 10
*/
        void partitionList(int x) {
            //    - Uses two dummy nodes to build two sublists:     
            //      one for values < x and one for values >= x.     
            //    - Traverses the list and adds each node to the    
            //      appropriate sublist.                            
            //    - Reconnects the two sublists at the end.         
            //    - Properly updates both `.next` and `.prev`       
            //      pointers.                                       
            //    - Updates `head` to the new start of the list.    
            //    - Deletes dummy nodes to free memory.             

            // If the list is empty, do nothing
            if (!head) return;
        
            // Create two dummy nodes to start the two partitions
            Node* dummy1 = new Node(0);  // For values < x
            Node* dummy2 = new Node(0);  // For values >= x
        
            // prev1 and prev2 will build the two lists
            Node* prev1 = dummy1;
            Node* prev2 = dummy2;
        
            Node* current = head;
        
            while (current != nullptr) {
                Node* nextNode = current->next;  // Save the next node
        
                // Disconnect the node from the list
                current->next = nullptr;
                current->prev = nullptr;
        
                if (current->value < x) {
                    // Append to the 'less than x' list
                    prev1->next = current;
                    current->prev = prev1;
                    prev1 = current;
                } else {
                    // Append to the 'greater or equal to x' list
                    prev2->next = current;
                    current->prev = prev2;
                    prev2 = current;
                }
        
                current = nextNode;
            }
        
            // Terminate the greater-or-equal list
            prev2->next = nullptr;
        
            // Connect the two lists
            prev1->next = dummy2->next;
        
            if (dummy2->next != nullptr) {
                dummy2->next->prev = prev1;
            }
        
            // Update the head of the full list
            head = dummy1->next;
            if (head) head->prev = nullptr;
        
            // Clean up
            delete dummy1;
            delete dummy2;
        }
        
};

int main(){
    DoublyLinkedList dll1(3);
    dll1.append(8);
    dll1.append(5);
    dll1.append(10);
    dll1.append(2);
    dll1.append(1);
    cout << "BEFORE: ";
    dll1.printList();
    dll1.partitionList(5);
    cout << "AFTER:  ";
    dll1.printList();
}