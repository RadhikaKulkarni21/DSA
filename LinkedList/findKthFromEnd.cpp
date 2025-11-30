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

    //   +======================================================+
    /*
    Implement the findKthFromEnd member function for the LinkedList class, 
    which returns the k-th node from the end of the linked list WITHOUT USING THE LENGTH of the list.
    
    If the value of k is greater than the length of the list, the function should return nullptr.
    */
    //   +======================================================+
    Node* findKthFromEnd(int k) {
        Node* slow = head;
        Node* fast = head;
        for (int i = 0;i < k;i++) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

};