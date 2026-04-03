/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', 
assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a 
non-digit character is encountered
or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
then round the integer to remain in the range. 
Specifically, integers less than -231 should be rounded to -231,
and integers greater than 231 - 1 should be rounded to 231 - 1.
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
//Read the question wrong so this solution is irrelevant to the question part
    string myAtoi(string s){
       string filterd;
       string result;
       int num = 0;
       
       //remove all the spaces
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
public:
    int myAtoi(string s){
        if(s.size() == 0){
            return 0;
        }

        //last point of range
        //[-231, 231 - 1]
        const long long maxInt = INT_MAX;
        const long long minInt = INT_MIN;

        int sign = 1;
        long long res = 0;
        
        //whitespace
        int i = 0;
        //check for white space and move forward
        while(i  < s.size() && s[i] == ' '){
            i++;
        }

        //sign -/+
        //positives sign move forward
        if(s[i] == '+'){
            i++;
        }
        //if its negative
        //set sign = -1 as we later need this to multiply and get final output
        else if(s[i] == '-'){
            sign = -1;
            i++;
        }

        //digits only
        while(i < s.size() && isdigit(s[i])){
            //bc the return type is integer and we are given a string
            //we subtract from '0' to get the actual integer value
            //direct conversion will give us ASCII value
            //this will return the actual digit value
            int digit = s[i] - '0';
            //moving to tens place, then moving to hundreds place
            res = res * 10 + digit;

            if(sign * res >= maxInt) return maxInt;
            if(sign * res <= minInt) return minInt;

            i++;
        }

        return static_cast<int>(res * sign);
    }
};

int main(){
    Solution sol;
    Solution2 sol2;
    string s = "-42ppo";
    //cout<<sol.myAtoi(s);
    cout<<sol2.myAtoi(s);
}
