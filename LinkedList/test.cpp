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
};

int main(){
    LinkedList* newList = new LinkedList(5);
    newList->printList();
}