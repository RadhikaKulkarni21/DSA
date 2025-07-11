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

/*
1)Check if List is Already Sorted

 -If the list length is less than 2, exit the function.

2) Initialize a 'Sorted Until' Marker

 -Set a marker that will keep track of where the list is sorted until.

 -Initialize this marker to nullptr.

3)Start Outer Loop to Sort the List

  Loop until the 'sorted until' marker is the second node in the list.

  Initialize Current Node for Inner Loop

    Start at the head of the list.

  Start Inner Loop to Compare Adjacent Nodes

    Loop from the head to where the list is sorted until 
    (as indicated by the 'sorted until' marker).

    Get the Next Node

        Store the next node relative to the current node.

    Compare Current and Next Node Values

        If the value of the current node is greater than that of the next node:

            Swap the Values

                Swap the values of the current node and the next node.

    Move to the Next Node in List

        Set the current node to its next node.

    End of Inner Loop

  Update 'Sorted Until' Marker

    Move the 'sorted until' marker back by one node.

End of Outer Loop
*/