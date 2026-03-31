/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', 
assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a 
non-digit character is encountered
or the end of the string is reached. If no digits were read, then the result is 0.

Example 1:

Input: s = "42"

Output: 42

Input: s = " -042"

Output: -42

Input: s = "words and 987"

Output: 0
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
//Read the question wrong so this is irrelevant to the question part
    string myAtoi(string s){
       string filterd;
       string result;
       int num = 0;
       
       for(char c: s){
        if(c != ' '){
            filterd.push_back(c);
        }
       }

       if(filterd[0] == '-' || filterd[0] == '+' || isdigit(filterd[0])){
        result.push_back(filterd[0]);
       }

       for(int i = 1; i < filterd.size(); i++){
        if(isalpha(filterd[i])){
            break;
        }
        result.push_back(filterd[i]);
       }
        return (result.size() == 0)?  "0" :  result;
    }
};

//correct solution
class Solution2{
    int myAtoi(string s){
        
    }
};

int main(){
    Solution sol;
    string s = "-42ppo";
    cout<<sol.myAtoi(s);
}
