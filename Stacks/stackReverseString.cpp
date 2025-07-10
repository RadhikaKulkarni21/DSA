#include <string>
#include <stack>
#include <iostream>
using namespace std;

using std::string; // Allows the use of 'string' instead of 'std::string'
using std::stack; // Allows the use of 'stack' instead of 'std::stack

string reverseString(const string& str) {
    /*
    Implement a function called reverseString() that reverses 
    the input string using a stack data structure.
    */
                                        
    // - Use a stack to hold each character of the string.
    // - Push each character of 'str' onto the stack.   
    // - Pop from the stack and append to 'reversedString'
    //   until the stack is empty.                      
    // - Return the reversed string.                    


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
    string input = "PASS";
    cout << "Input: \"" << input << "\"\n";
    cout << "Output: \"" << reverseString(input);
}
