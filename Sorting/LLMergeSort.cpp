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

		void merge(LinkedList& otherList){
            //other linkedList similar to subarray
		    Node* otherHead = otherList.getHead();
            //main array to store the sorted nodes
		    Node* dummy = new Node(0);
		    Node* current = dummy;
            //compare value and add to the LL
		    while(head != nullptr && otherHead != nullptr){
		        if(head->value < otherHead->value){
		            current->next = head;
		            head = head->next;
		        }
		        else{
		            current->next = otherHead;
		            otherHead = otherHead->next;
		        }
		        current = current->next;
		    }
            //When one list gets nullptr, add remaining items to main list
		    if(head != nullptr){
		        current->next = head;
		        while(current->next != nullptr){
		        current = current->next;
		        }
		    }
		    else{
		        current->next = otherHead;
		        while(current->next != nullptr){
		        current = current->next;
		        }
		    }
        //clean up
		tail = current;//update the tail of unsorted to current main array
		head = dummy->next;//update head
		delete dummy;//delete the dummy
		length += otherList.getLength();
		
		otherList.head = nullptr;//sine no use null everything
		otherList.tail = nullptr;
		otherList.length = 0;
	}
};


int main(){
     LinkedList list1(2);
        LinkedList list2(1);
        list2.append(3);
        list2.append(4);

        cout << "List1: ";
        list1.printList();

        cout << "List2: ";
        list2.printList();

        list1.merge(list2);

        cout << "Merged: ";
        list1.printList();
}