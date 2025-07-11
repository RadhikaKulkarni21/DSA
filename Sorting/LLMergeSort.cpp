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

/*
Initialize Pointers and Dummy Node

    Get the head of the otherList and call it otherHead.

    Create a dummy node with value 0.

    Initialize current to point to the dummy node.

Start Merging

    Loop while head and otherHead are not nullptr.

    Compare Node Values

        If the value at head is smaller than the value at otherHead:

            Attach Node from Original List

                Set current->next to head.

                Move head to the next node in the original list.

        Otherwise:

            Attach Node from Other List

                Set current->next to otherHead.

                Move otherHead to the next node in the otherList.

    Advance Current Pointer

        Move current to its next node.

    End of Loop

Handle Remaining Nodes in Original List

    If head is not nullptr:

        Attach the remaining nodes from the original list to current.

        Traverse to the end of the list.

Handle Remaining Nodes in Other List

    If otherHead is not nullptr:

        Attach the remaining nodes from the otherList to current.

        Traverse to the end of the list.

Update Tail

    The tail of the merged list is the node where current is pointing.

Update Head and Clean Up

    The head of the merged list is dummy->next.

    Delete the dummy node.

Update Length

    Add the length of otherList to the length of the merged list.

Reset Other List
    Set the head, tail, and length of otherList to nullptr and 0, respectively.
*/