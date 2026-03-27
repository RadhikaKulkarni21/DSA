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