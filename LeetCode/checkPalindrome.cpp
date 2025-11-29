#include "R:\C++\Project1\lcHeader.h"
/*
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/
bool checkPalindrome(string s){
    if(s.length() == 0) return true;
    string filtered;
    for(auto ch : s){
        if(isalnum(ch)) filtered += tolower(ch);
    }

    // we take two pointers and iterate through the list
    int left = 0;
    int right = filtered.size() - 1;

    while(left < right){
        if(filtered[left] != filtered[right]) return false;
        left++;
        right--;
    }

    return true;
}

int main(){
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";

    bool result1 = checkPalindrome(s1);
    bool result2 = checkPalindrome(s2);

    cout << result1 << endl << result2;
}