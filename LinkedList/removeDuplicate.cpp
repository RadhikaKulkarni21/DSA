#include "R:\C++\Project1\lcHeader.h"

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        length = 1;
    }

    ~LinkedList() {
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
            cout << "empty";
        }
        else {
            while (temp != nullptr) {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
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
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
        length++;
    }

    //   +======================================================+
    /*Implement the removeDuplicates member function for the LinkedList class, 
     which removes all duplicate values from a singly linked list.

    The function should preserve the original order of the non-duplicate elements.
    */
    //   +======================================================+
    void removeDuplicates() {
        Node* current = head;

        while (current != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (runner->next->value == current->value) {
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                    length -= 1;//-1 to reduce the length after deletion    
                }
                else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
};
/*
Pseudo Code Double iteration through the list

Initialize a pointer current to the head of the linked list.

Iterate through the linked list using the current pointer:

Initialize a pointer runner to current.

While the next node of runner is not nullptr, perform the following:

If the value of the next node of runner is equal to the value of the current node, 
update the next pointer of the runner node to point to the next node of the runner's next node (thus skipping the duplicate node) 
and decrement the length of the linked list by 1.

If the value of the next node of runner is not equal to the value of the current node, 
move the runner pointer to the next node in the linked list.

Move the current pointer to the next node in the linked list, and repeat step 2 until the end of the linked list is reached.
*/