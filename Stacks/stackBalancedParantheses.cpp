#include <string>
#include <stack>
#include <iostream>
using namespace std;


/*
Implement a function called isBalancedParentheses() that 
checks if the input string contains balanced parentheses.
Examples:

Consider the following input string:
parentheses: "()"
After calling isBalancedParentheses(parentheses), the result should be:
true

Consider the following input string:
parentheses: "(()))"
After calling isBalancedParentheses(parentheses), the result should be:
false

*/
bool isBalancedParentheses(const string& parentheses) {
    // Stack to store the opening parentheses
    stack<char> charStack;
 
    // Iterate through the input string
    for (char p : parentheses) {
        // If the current character is an opening parenthesis, push it onto the stack
        if (p == '(') {
            charStack.push(p);
        } else if (p == ')') { // If the current character is a closing parenthesis
            // Check if the stack is empty or the top of the stack 
            // is not an opening parenthesis
            if (charStack.empty() || charStack.top() != '(') {
                return false;
            }
            // Pop the matching opening parenthesis from the stack
            charStack.pop();
        }
    }
 
    // Return true if the stack is empty, indicating balanced parentheses
    return charStack.empty();
}

int main(){
    cout << "\n----- Test: Empty Parentheses -----\n";
    {
        string input = "(()";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
    }
}

/*
For each foreach iteration it is going to check '(' equivalent ')'

1)1st foreach iteration => charstack = '(' - no elif will be executed

2)2nd foreach iteration => charstack = '(' ->'(' - no elif will be executed

3)3rd foreach iteration => charstack = '(' ->'(' - no if will be executed
we move to elif - charStack.empty() || charStack.top() != '(' - both false so skip
pop out '(' - becasue we found equivalent ')'

4) there is no 4th iteration so '(' is still left in the stack so hence this is unbalanced
*/