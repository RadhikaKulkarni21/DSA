#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> stackVector;
    
    public:
        vector<int>& getStackVector() {
            return stackVector;
        }
    
        void printStack() {
            for (int i = stackVector.size() - 1; i >= 0; i--) {
                cout << stackVector[i] << endl;
            }
        }
    
        bool isEmpty() {
            return stackVector.size() == 0;
        }
    
        int peek() {
            if (isEmpty()) {
                return int();
            } else {
                return stackVector[stackVector.size() - 1];
            }
        }
    
        int size() {
            return stackVector.size();
        }
    
        void push(int value) {
            stackVector.push_back(value);
        }
    
        void pop(){
            if(!isEmpty()){
            stackVector.pop_back();
            }
        } 
};

int main(){
    
    Stack stack;
    cout << "Pushing values 10, 20, and 30:\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Popping all values until stack is empty:\n";
    stack.pop();
    stack.pop();
    stack.pop();
    cout << "Size: " << stack.size() << " - EXPECTED: 0\n";
    cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << " - EXPECTED: empty\n";
    cout << "Popping from empty stack (should still be empty):\n";
    stack.pop(); // Should still be empty
    cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << " - EXPECTED: empty\n";
    cout << (stack.isEmpty() && stack.size() == 0 ? "PASS\n" : "FAIL\n");

}