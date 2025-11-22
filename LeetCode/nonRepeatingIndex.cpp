#include "lcheader.h"

//First non repeating character but its index

int nonRepeatedIndex(string s){
    unordered_map<char, int> freq;

    //checking the frequency of each character
    for(char c : s){
        freq[c]++;
    }

    for(int i = 0; i < s.length(); i++){
        if(freq[s[i]] == 1){
            return i;
        }
    }
    return -1;
}

//if the string has uppercase or case sensitive is an issue
int nonRepeatedCase(string s){
    unordered_map<char, int> freqCount;

    for(char c: s){
        c = tolower(c);
        freqCount[c]++;
    }

    for(int i = 0;i < s.length();i++){
        if(freqCount[tolower(s[i])] == 1){
            return i;
        }
    }

    return -1;
}

int main(){
    string s = "hhello";
    string t = "Hhello";
    cout<< nonRepeatedIndex(s)<<endl;//exp: 2
    cout<< nonRepeatedCase(t)<<endl;//exp: 2
    return 0;
}