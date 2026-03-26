/*
You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, 
starting with word1.
If a string is longer than the other, 
append the additional letters onto the end of the merged string.

Return the merged string.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    string mergeAlternately(string word1, string word2){
        int n = word1.length();
        int m = word2.length();
        int i,j = 0; 

        string result;

        while(i < n || j < m){
            if(i < n){
                result.push_back(word1[i]);
                i++;
            }
            if(j < m){
                result.push_back(word2[j]);
                j++;
            }
        }
        return result;
    }
};

int main(){
    string word1 = "abc";
    string word2 = "def";

    Solution s;
    string result;
    result = s.mergeAlternately(word1, word2);
    cout << "Merged String: " << result;
}

