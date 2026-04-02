/*
Given two strings s and part, perform the following operation on s 
until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    string removeOccurrences(string s, string part){
        //find where the first occurance of part occurs
        size_t index = s.find(part);
        //repeatedly remove till we reach the end of the string
        while(index != string::npos){
            //modify the string
            s.erase(index, part.length());
            //update index each time we remove it
            index = s.find(part);
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s = "axxxxyyyyb";
    string part = "xy";
    cout << sol.removeOccurrences(s, part);//expected: ab
}