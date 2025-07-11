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

class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:
    //Constructor
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

    //Enqueue
        void enqueue(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                first = newNode;
                last = newNode;
            }
            else{
                last->next = newNode;
                last = newNode;
            }
            length++;
        }
        
        int dequeue(){
            if(length == 0) return INT_MIN;
            Node* temp = first;
            int dequeuedValue = first->value;
            if(length == 1){
                first = nullptr;
                last = nullptr;
            }
            else{
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }

        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        void printQueue() {
            if (length == 0) {
                cout << "Queue: empty" << endl;
                return;
            }
            Node* temp = first;
            cout << "Queue: ";
            while (temp) {
                cout << temp->value;
                temp = temp->next;
                if (temp) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }


        Node* getFirst() {
            return first;
        }

        Node* getLast() {
            return last;
        }

        int getLength() {
            return length;
        }

        bool isEmpty() {
            if (length == 0) return true;
            return false;
        }
        
};

int main(){
    Queue* newQueue = new Queue(7);
    newQueue->enqueue(8);
    newQueue->dequeue();
    newQueue->printQueue();
    newQueue->dequeue();
    newQueue->printQueue();
}

