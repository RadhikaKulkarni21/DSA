#include "lcHeader.h"
/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces 
between two words. 
The returned string should only have a single space separating the words. 
Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
*/

//basic reverse string
void reverseString(vector<char>& s) {
    int i  = 0;
    int j = s.size() - 1;

    while(i < j){
        char temp = s[i];
        s[i] =  s[j];
        s[j] = temp;
        i++;
        j--; 
    }
}

string reverseWords(string s){
    string reverse;
    string word;
    stringstream ss(s);
    vector<string> words;

    while(ss >> word){
        words.push_back(word);
    }

    for(int i = words.size() - 1;i >= 0; i--){
        reverse += words[i];
        if(i != 0){
            reverse += " ";
        }
    }
    return reverse;
}

string reverseWordsTwo(string s) {
    istringstream iss(s);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    int left = 0, right = words.size() - 1;
    while (left < right) {
        swap(words[left], words[right]);
        left++;
        right--;
    }

    string result;
    for (const string& w : words) {
        if (!result.empty()) {
            result += " ";
        }
        result += w;
    }

    return result;
}

int main(){
    string s = "The sky is   red";
    cout<<reverseWords(s)<<endl;
    cout<<reverseWordsTwo(s);
}