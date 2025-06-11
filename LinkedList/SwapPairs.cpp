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
    int length;

public:
    //node creation
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        length = 1;
    }

    //destructor
    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    //priting entire linkedList
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

    //adding node at last
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

    /*Q: Write a method swapPairs() that swaps every two adjacent nodes in a singly linked list.
    swapping two pairs
    Example:

    Input:  1 -> 2 -> 3 -> 4
    Output: 2 -> 1 -> 4 -> 3
 
    Input:  1 -> 2 -> 3
    Output: 2 -> 1 -> 3
    */
    void swapPairs() {

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
    /*We use a dummy node so that we can easily update the head even if the first two nodes are swapped.

    The previous pointer tracks the node before the current pair.

    For each pair:

    second is first->next.

    Link previous->next to second.

    Link first->next to the node after second.

    Link second->next to first.

    Move the previous and first pointers to continue the process.

    At the end, update the real head of the list from the dummy.*/