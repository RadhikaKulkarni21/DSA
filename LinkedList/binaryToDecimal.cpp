#include "R:\C++\Project1\lcHeader.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
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

    void makeEmpty() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
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
    }

    //   +======================================================+
    /*
    You have a linked list where each node represents a binary digit (0 or 1). 
    The goal of the binaryToDecimal function is to convert this binary number, 
    represented by the linked list, into its decimal equivalent.
    */
    //   +======================================================+
    int binaryToDecimal() {
        Node* current = head;
        int num = 0;
        while (current != nullptr) {
            num = num * 2 + current->value;
            current = current->next;
        }
        return num;
    }

};
//   | - Use a single pointer : 'current' 
//   | - Initialize an integer 'num' to 0                   
//   | - Loop through the list                              
//   | - Use the formula: num = num * 2 + current->value
//   | - Return 'num' as the decimal value         
int main(){
    LinkedList* newLL = new LinkedList(1);
    newLL->append(2);
    newLL->printList();
    cout<<newLL->binaryToDecimal();
}
