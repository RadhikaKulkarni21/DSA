#include <string>
#include <stack>
#include <iostream>
using namespace std;

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack

string reverseString(const string& str) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function reverses the input string 'str'.    |
    //   | - Uses a stack to hold the characters.              |
    //   | - Pops from stack and appends to 'reversedString'.  |
    //   | - Return type: string                               |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold each character of the string. |
    //   | - Push each character of 'str' onto the stack.      |
    //   | - Pop from the stack and append to 'reversedString' |
    //   |   until the stack is empty.                         |
    //   | - Return the reversed string.                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

        string reversedString;
        stack<char> charStack;
        for(char c: str){
            charStack.push(c);
        }
        while(!charStack.empty()){
         reversedString += charStack.top();
         charStack.pop();
        }
        return reversedString;
}

int main(){
    cout << "\n----- Test: Reverse Empty String -----\n";
    {
        string input = "PASS";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: \"" << reverseString(input);
    }
}
