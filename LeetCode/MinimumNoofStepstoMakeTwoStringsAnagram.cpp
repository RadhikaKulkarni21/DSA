/*
You are given two strings of the same length s and t.
In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    int minSteps(string s, string t){
        vector<int> sFreq(26,0);
        vector<int> tFreq(26,0);

        for(char c : s){
            sFreq[c - 'a']++;
        }
        for(char c : t){
            tFreq[c - 'a']++;
        }

        int counter = 0;
        for(int i = 0; i < 26;i++){
            counter += abs(sFreq[i] - tFreq[i]);
        }
        return counter/2;
    }
};

int main(){
    Solution sol;
    string s = "bab", t = "aba";

    cout << sol.minSteps(s,t);
}

/*
We take 2 arrays to store the frequency of each strings here
then we store the frequencey as per the number of each alphabet
subtract the each occurance from each arrays and abs will give us positive answer

But since the substraction will take place for both the arrays we will divide it by 2

example: s = bab t = aba 
s = a/1 freq = 1  t = a/1 frq = 2
s = b/2 freq = 2  t = b/2 freq = 1
    1 2 3
s   1 2
t   2 1
abs 1 1

divide by 2 and the answer is 1
*/