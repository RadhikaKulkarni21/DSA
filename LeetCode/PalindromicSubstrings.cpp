/*Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.*/

#include "R:\C++\Project1\lcHeader.h"

int palindromicSubstrings(string s){
    int n = s.size();
    int c;
    for(int i = 0;i < s.size();i++){
        int l = i, r = i;
        //odd length palindorme eg aaa
        //it will check for each l and r till while loop is false
        //once l is out of bounds we move to next i++
        while(l >= 0 && r < n && s[l] == s[r]){
            c++;
            l--;
            r++;
        }

        l = i;
        r = i + 1;
        //even length palindrom like abba
        //same as above
        while(l >= 0 && r < n && s[l] == s[r]){
            c++;
            l--;
            r++;
        }
    }
    return c;
}

//O(n^2) bc of two expansions we are using
//the for runs twice for odd and even palindrome
//n centers, we may expand up to n steps.

int main(){
    string s = "aaa";
    cout << palindromicSubstrings(s);
}