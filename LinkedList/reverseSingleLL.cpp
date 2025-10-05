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

    void reverseList(){
    Node* prev = NULL;
    Node* curr = head;

    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}
};

int main(){
    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.printList();
    cout<<"After reverse: "<<endl;
    list.reverseList();
    list.printList();
}