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


    void selectionSort(){
            if(length < 2)return;
            
            Node* current = head;
            while(current->next != nullptr){
               //considering head is smallest rn
                Node* smallestNode = current;
                Node* nextNode = current->next;
                
                while(nextNode != nullptr){
                    if(nextNode->value < smallestNode->value){
                        smallestNode = nextNode;
                    }
                    //we need to loop through the whole thing to find the smallest value
                    //then only we swap
                    nextNode = nextNode->next;
                }
                //once the smallest element is found we swap it with current
                if(smallestNode != current){
                    int temp = current->value;
                    current->value = smallestNode->value;
                    smallestNode->value = temp;
                }
            //Once the swao is complete we start again with the next element
            current = current->next;
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

    list.selectionSort();

    cout << "After: ";
    list.printList();
}

/*
Check if List is Already Sorted

    If the list has less than 2 elements, it's already sorted, so exit the function.

Initialize 'Current' Node

    Start at the head of the list.

Begin Outer Loop

    Loop while the 'current' node's next is not nullptr.

    Initialize 'Smallest' Node

        Start by assuming the 'current' node holds the smallest value.

    Initialize 'Inner Current' Node

        Start at the node next to 'current'.

    Begin Inner Loop

        Loop while the 'inner current' node is not nullptr.

        Find the Smallest Value

            If the value at 'inner current' is smaller than the value at 'smallest':

                Update 'smallest' to be 'inner current'.

        Move 'Inner Current' Node

                Go to the next node in the list.

        End of Inner Loop

    Check If Swap is Needed

        If 'smallest' is not equal to 'current':

    Swap the Values

        Swap the values of 'smallest' and 'current' nodes.

    Move 'Current' Node

        Go to the next node in the list.

    End of Outer Loop
*/