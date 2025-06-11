#include <iostream>

using namespace std;

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

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
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

    void makeEmpty() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
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
    }
    /*Implement a member function, findMiddleNode(), which finds and returns the middle node of the linked list.

     Note: this LinkedList implementation does not have a length member variable.
     Example:
     Suppose you have a LinkedList object, list, with the following values:
        1 -> 2 -> 3 -> 4 -> 5

     After calling the findMiddleNode() function:

     Node* middle = list.findMiddleNode();

     The middle pointer should point to the node with value 3.*/


    Node* findMiddleNode() {
        Node* slow = head;
        Node* fast = head;
        if (head != nullptr) {
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};
/*The findMiddleNode() function uses the "tortoise and hare" algorithm to find the middle node of a linked list. 
Here's a step-by-step explanation of the logic:


Initialize two pointers, slow and fast, both pointing to the head of the linked list.

Traverse the linked list using a while loop. The loop continues as long as fast is not nullptr (i.e., it has not reached the end of the list), 
and fast->next is also not nullptr (i.e., there is at least one more node after the current fast node).

Inside the loop, move the slow pointer one step forward (i.e., slow = slow->next) 
and the fast pointer two steps forward (i.e., fast = fast->next->next).

Since the fast pointer moves twice as fast as the slow pointer, by the time the fast pointer reaches the end of the list or goes beyond it,
the slow pointer will be at the middle node.

When the loop terminates, return the slow pointer, which now points to the middle node.*/