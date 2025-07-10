#include <stack>
#include <iostream>
using namespace std;
using std::stack;

/*
Implement a function called sortStack() that sorts 
a given stack of integers in ascending order using an additional stack.

Consider the following input stack:

inputStack:
5
2
7
1

After calling sortStack(inputStack), the input stack should be:

inputStack:
1
2
5
7
*/

void sortStack(stack<int>& inputStack) {
    
    // Additional stack to temporarily store and sort elements
    stack<int> additionalStack;
 
    // Iterate until the input stack becomes empty
    while (!inputStack.empty()) {
        // Store the top element of the input stack in temp
        int temp = inputStack.top();
        inputStack.pop();
 
        // Move elements from additionalStack to inputStack while
        // they are greater than temp
        while (!additionalStack.empty() && additionalStack.top() > temp) {
            inputStack.push(additionalStack.top());
            additionalStack.pop();
        }
 
        // Push temp onto the additionalStack
        additionalStack.push(temp);
    }
 
    // Move sorted elements back to inputStack
    while (!additionalStack.empty()) {
        inputStack.push(additionalStack.top());
        additionalStack.pop();
    }
}

int main(){
    {
        stack<int> s;
        s.push(5);
        s.push(5);
        s.push(5);
        sortStack(s);
        bool pass = true;
        while (!s.empty() && pass) {
            if (s.top() != 5) {
                pass = false;
            }
            s.pop();
        }
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
}