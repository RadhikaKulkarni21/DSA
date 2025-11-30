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
    int length;

public:
    //making a new node
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

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    /*Implement the reverseBetween member function for the LinkedList class,
    which reverses the nodes of the list from the indexes m to n (the positions are 0-indexed).
    Example:

    Consider the following singly linked list:

        1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    For the given list, the function ll.reverseBetween(1, 3) should modify the list to be:

        1 -> 4 -> 3 -> 2 -> 5 -> nullptr

    The sublist from the indexes from 1 to 3 has been reversed.
    */
    void reverseBetween(int m, int n) {
        if (head == nullptr) return;
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;
        for (int i = 0;i < m;i++) {
            prev = prev->next;
        }
        Node* current = prev->next;
        for (int i = 0;i < n - m;i++) {
            Node* temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        head = dummy->next;
        delete dummy;
    }
};