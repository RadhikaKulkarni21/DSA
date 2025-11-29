#include "R:\C++\Project1\lcHeader.h"

//we need to check for anagrams, which are jumbled formed of words

//*DO NOT CONFUSE THIS WITH PALINDROME*

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true*/

bool isAnAnagram(string s, string t){
    if(s.length() != t.length()) return false;

    unordered_map<char, int> freqCounter;
    //we'll count the frequency of each character in the strings
    //one foreach will add to the char count from s string
    //other foreach will remove the corresponding char count
    //so if the values of all the chars is 0, we have anagram 
    //if not it returns false;

    for(char ch : s){
        freqCounter[ch] += 1;
    }

    for(char ch : t){
        freqCounter[ch] -= 1;
    }

    for(auto ch : freqCounter){
        if(ch.second != 0){
            return false;
        }
    }

    return true;
}

int main(){
    string s = "anagram";
    string t = "nagamar";

    bool result = isAnAnagram(s,t);
    cout<< (result == 1) ? "True":"False";
}