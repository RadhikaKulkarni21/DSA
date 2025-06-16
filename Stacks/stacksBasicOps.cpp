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

class Stack {
    private:
        Node* top;//equivalent to head
        int height;
        
    public:
    //constructor
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
    
    //Push items
        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

    //pop items
        int pop(){
            if(height == 0){
                return INT_MIN;//need to print an int so int_min so that value can never be found
            }
            else{
                Node* temp = top;
                int poppedValue = top->value;
                top = top->next;
                delete temp;
                height--;

                return poppedValue;
            }

        }
    
        ~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }
    
        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
    
        Node* getTop() {
            return top;
        }
    
        int getHeight() {
            return height;
        }
    
};

int main(){
    Stack* newStack = new Stack(5);
    newStack->push(6);
    newStack->printStack();
    cout<<"first pop"<<endl;
    newStack->pop();
    newStack->printStack();
    cout<<"second pop"<<endl;
    newStack->pop();
    newStack->printStack();
}