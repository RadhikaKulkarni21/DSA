#include "R:\C++\Project1\lcHeader.h"

class Solution{
    public:
    int expressiveWords(string s, vector<string> words){
        int counter = 0;
        for(string w : words){
            if(check(s, w)) counter++;
        }
        return counter;
    }

    bool check(string s, string w){
        int n = s.size(), m = w.size(), j = 0;

        for(int i = 0; i < n;i++){
            //as long as m size, comparing each character of s and w
            //i is already being ++ in the for loop
            if(j < m && s[i] == w[j]) j++;

            //checking the freq to be more than 3
            //no return or j++ bc this is a valid case and we skip it
            else if(i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);

            else if(0 < i && i < n - 1 && s[i - 1] == s[i] && s[i] == s[i + 1]);

            else return false;
        }
        return true;
    }
};

int main(){
    string s = "heeellooo";
    vector<string> words = {"hello", "hi", "helo"};

    Solution sol;
    cout << sol.expressiveWords(s, words);
}

/*
s = "heeellooo"
words = ["hello", "hi", "helo"]

group can only be formed if the s has the character three or more than three times
*/