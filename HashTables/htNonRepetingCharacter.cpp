#include "R:\C++\Project1\lcHeader.h"

/*
Implement a function called firstNonRepeatingChar() that finds and 
returns the first non-repeating character in a given string.

Consider the following input string:
input_string: "programming"

After calling firstNonRepeatingChar(input_string), the result should be:
'p'

Consider the following input string:
input_string: "truetalent"

After calling firstNonRepeatingChar(input_string), the result should be:
'r'
*/

char firstNonRepeatingChar(const string& input_string){
    if(input_string.length() == 0) return 0;
    unordered_map<char, int> charCounts;
    //increase the count of each character
    for(char i : input_string){
        charCounts[i]++;
    }
    // Check if the character count is 1
    for(char c: input_string){
        if(charCounts[c] == 1)return c;
    }
    return 0;
}

int main(){
        string input = "aabbccdd";
        char result = firstNonRepeatingChar(input);
        cout<<result;
}