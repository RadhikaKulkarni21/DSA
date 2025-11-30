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
    /*
        Implement the partitionList member function for the LinkedList class, 
        which partitions the list such that all nodes with values less than x come before nodes with values greater than or equal to x.
    */
    //   +======================================================+

    void partitionList(int x) {
        if (head == nullptr) return;
        Node dummy1(0);
        Node dummy2(0);
        Node* prev1 = &dummy1;
        Node* prev2 = &dummy2;
        Node* current = head;

        while (current != nullptr) {
            if (current->value < x) {
                prev1->next = current;
                prev1 = current;
            }
            else {
                prev2->next = current;
                prev2 = current;
            }
            current = current->next;
        }
        prev2->next = nullptr;
        prev1->next = dummy2.next;
        head = dummy1.next;
    }
};

/*if (head == nullptr) return;: This line checks if the linked list is empty (i.e., the head is nullptr). 
//If it's empty, there is nothing to partition, so the method returns immediately.

//Node dummy1(0); and Node dummy2(0);: Two dummy nodes are created with values of 0. 
// These dummy nodes will help in keeping track of the heads of two sublists: 
// one for nodes with values less than x and another for nodes with values greater than or equal to x.

/*Node* prev1 = &dummy1; and Node* prev2 = &dummy2;: Two pointers, prev1 and prev2,
//are created and initialized to the addresses of the dummy nodes.
//These pointers will be used to traverse and build the two sublists.

//Node* current = head;: A pointer to a Node object named current is created and initialized to the head of the linked list. 
// It will be used to traverse the list.

//while (current != nullptr) { ... }: This while loop iterates through the linked list until the current node is nullptr, 
// indicating the end of the list.

//if (current->value < x) { ... }: This condition checks if the value of the current node is less than x. 
//If it is, the code block within the condition will execute.

//prev1->next = current;: The next pointer of the prev1 node is updated to point to the current node, adding the node to the first sublist.

//prev1 = current;: The prev1 pointer is updated to point to the current node, moving the iteration forward.

//else { ... }: If the value of the current node is greater than or equal to x, 
//the code block within the else statement will execute.

//prev2->next = current;: The next pointer of the prev2 node is updated to point to the current node,
// adding the node to the second sublist.

//prev2 = current;: The prev2 pointer is updated to point to the current node, moving the iteration forward.

//current = current->next;: The current pointer is updated to point to the next node in the linked list, moving the outer loop iteration forward.

//prev2->next = nullptr;: The next pointer of the last node in the second sublist (pointed to by prev2) is set to nullptr, 
// indicating the end of the sublist.

//prev1->next = dummy2.next;: The next pointer of the last node in the first sublist (pointed to by prev1) is 
//updated to point to the head of the second sublist (i.e., the node after the dummy2 node). This action connects the two sublists.

//head = dummy1.next;: The head of the entire linked list is updated by pointing it to the node after the dummy1 node, 
// ensuring that the modified linked list is properly connected.*/