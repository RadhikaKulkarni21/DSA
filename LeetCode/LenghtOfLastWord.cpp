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

    int lengthOfLastWord2(string s) {
        int end = s.length() - 1;

        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }

        return end - start;        
    }
};

int main(){
    Solution so;
    string s = "   fly me   to   the moon  ";

    cout<< so.lengthOfLastWord(s);
}

/*
First solution
Time: O(n) space: O(n)
stringstream to remove all the spaces and store each word in a vector
lenght of last element in vector

second optimized solution(space only)
Time: O(n) Space: O(1) 
iterating from end of the string

end will iterate to check if its a char or space
char is hit set that as the end point

set start = end
iterate backwards to find char/space
when it hits space, thats where the word starts
set as start

subtract start and end to get length
*/