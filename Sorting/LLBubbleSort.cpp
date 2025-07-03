#include <iostream>
#include <vector>
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
            } else {
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

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

		void bubbleSort(){
		    if(length < 2) return;//if just 1 element, list is already sorted

            //create this to mark which node is already visited and/or swapped
		    Node* sortedUntil = nullptr;
		    while(sortedUntil != head->next){
		        Node* current = head;//we need to set it to head current
		        while(current->next != sortedUntil){
		            Node* nextNode = current->next;
                    //check and swap
		            if(current->value > nextNode->value){
		                int temp = current->value;
		                current->value = nextNode->value;
		                nextNode->value = temp;
		            }
                    ////moving forward till we reach the marker
		            current =  current->next;
		        }
		        sortedUntil = current;//if sorted set current
		    }
		}
};

int main(){
    LinkedList list(5);
    list.append(3);
    list.append(8);
    list.append(1);

    cout << "Before: ";
    list.printList();

    list.bubbleSort();

    cout << "After: ";
    list.printList();
}
