#include "R:\C++\Project1\lcHeader.h"

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
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

    Node* getTail() {
        return tail;
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
        tail = nullptr;
        length = 0;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    //   +======================================================+
    /*LL: Has Loop ( ** Interview Question)
    Implement a function called hasLoop to detect if a given singly-linked list contains a loop (a cycle) or not.

    The function should return true if a loop is detected in the linked list, and false otherwise.
    */
    //   +======================================================+

    bool hasLoop() {
        Node* slow = head;
        Node* fast = head;
        //if(length == 1)return true;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

};
/*The hasLoop() function is used to determine if there is a loop (cycle) in a linked list. 
It uses the "tortoise and hare" (or "Floyd's cycle-finding") algorithm, which works as follows:

Create two pointers, slow and fast, both initially pointing to the head of the linked list.

Traverse the linked list with the slow pointer moving one step at a time and the fast pointer moving two steps at a time.

If there is a loop in the list, the fast pointer will eventually meet the slow pointer inside the loop. 
If there is no loop, the fast pointer will reach the end of the list (i.e., become null or point to the last node).
*/