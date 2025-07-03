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
        
		//   +=====================================================+
		//   |                WRITE YOUR CODE HERE                 |
		//   | Description:                                        |
		//   | - This method sorts the linked list using           |
		//   |   the Insertion Sort algorithm.                     |
		//   | - Divides the list into sorted and unsorted parts.  |
		//   | - Iterates through unsorted part and inserts each   |
		//   |   node into the sorted part at the right position.  |
		//   |                                                     |
		//   | Return type: void                                   |
		//   |                                                     |
		//   | Tips:                                               |
		//   | - Uses two sub-lists to divide original list.       |
		//   | - Uses while loops for list traversal.              |
		//   | - Check output from Test.cpp in "User logs".        |
		//   +=====================================================+
		void insertionSort(){
		    if(length < 2) {return;}
		   
		    Node* sortedList = head;
		    Node* unsortedList = head->next;
		    sortedList->next = nullptr;
		    
		    while(unsortedList != nullptr){
		        Node* current = unsortedList;
		        unsortedList = unsortedList->next;
		        
		        if(current->value < sortedList->value){
		            current->next = sortedList;
		            sortedList = current;
		        }
		        else{
		            Node* searchPoint = sortedList;
		            while(searchPoint->next != nullptr && current->value > searchPoint->next->value){
		                searchPoint = searchPoint->next;
		            }
		            current->next = searchPoint->next;
		            searchPoint->next = current;
		        }
		    }
		    
		    head = sortedList;
		    Node* temp = head;
		    while(temp->next != nullptr){
		        temp = temp->next;
		    }
		    tail = temp;
		}
};


int main(){
    LinkedList list(2);
    list.append(6);
    list.append(3);
    list.append(5);
    list.append(1);

    cout<<"Before:";
    list.printList();

    list.insertionSort();
    cout<<"After:";
    list.printList();
}