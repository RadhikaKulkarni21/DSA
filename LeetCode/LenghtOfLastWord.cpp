/*
Given a string s consisting of words and spaces,
return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    int lengthOfLastWord(string s){
        int len = 0;
        stringstream ss(s);
        vector<string> words;

        while(ss >> s){
            words.push_back(s);
        }

        int n = words.size();

        len = words[n - 1].size();

        return len;
    }
};