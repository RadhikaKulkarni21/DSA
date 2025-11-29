#include "R:\C++\Project1\lcHeader.h"

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
    
        void push(int value){
            stackVector.push_back(value);
        }
};


int main(){
    Stack stack;
        cout << "Pushing value of 10 to an empty stack:\n";
        stack.push(10);
        cout << "Pushing value of 20 to a stack with one element:\n";
        stack.push(20);
        cout << "Pushing value of 30 to a stack with two elements:\n";
        stack.push(30);
        cout << "Peek result: " << stack.peek() << " - EXPECTED: 30\n";
        cout << "Size: " << stack.size() << " - EXPECTED: 3\n";
        cout << (stack.peek() == 30 && stack.size() == 3 ? "PASS\n" : "FAIL\n");
}