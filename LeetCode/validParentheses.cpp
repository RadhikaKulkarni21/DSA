#include "lcHeader.h"
/*
We are using stack here, so we parse through the each character in string and
check if the current stack in closing equivalent of it. If it is not a closing
equivalent but a opening bracket we will push it into the stack. 
Now we check the next character, and compare each with the top of stack
if we hit a point where the string is traversed the list is not empty -
It is an invalid string
If the list is empty it is an valid string

for a string to be valid, the brackets inside other brackets 
needs to close first before the very first bracket closes
Valid nesting
*/

bool validParentheses(string s){
    //we are creating an unordered map to map out the corresponding the brackets
    unordered_map<char, char> mappings;
    mappings[')'] = '(';
    mappings[']'] = '[';
    mappings['}'] = '{';

    //using lifo concept, so whatever bracket enters first gets removed last
    stack<char> brackets;

    for (char c: s){
        //Check if the top of the stack matches the expected opening bracket.
        if(mappings.find(c) != mappings.end()){
            char top = brackets.empty() ? '#': brackets.top();
            brackets.pop();

            //checking if the top is equal to maps brackets
            if(top != mappings[c]) return false;
        }
        //if does not match, push in the stack
        else{
            brackets.push(c);
        }
    }
    return {};
}

//different approach
bool isValid(string s) {
    //Dictionary - Map each closing bracket to its matching opening bracket
    unordered_map<char, char> mappings;
    mappings[')'] = '(';
    mappings[']'] = '[';
    mappings['}'] = '{';

    //stack to store the opening brackets and check top
    stack<char> brackets;

    for(char c : s){

        if(mappings.find(c) != mappings.end()){
        // If stack is empty OR top of stack doesn't match the expected opening bracket
            if (brackets.empty() || brackets.top() != mappings[c]) {
                return false;
            }
            //or else it matches so pop
            brackets.pop();
        }
        //if its opening brace, push on the stack
        else {
            brackets.push(c);
        }
    }
    return brackets.empty();
}


int main(){
    string s = "[{)}]";
    bool result = isValid(s);
    string op = result ? "true" : "false";
    cout<< op;
}