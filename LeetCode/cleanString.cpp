#include "R:\C++\Project1\lcHeader.h"

/*
Given the string "William Henry Douglas", make all of the letters lowercase, 
remove spaces, 
remove duplicate letters, 
and put the remaining letters in alphabetical order
*/


string cleanString(string s){
    string lower;

    for(char c : s){
        if(c != ' ') lower += tolower(c);
    }

    set<char> removeDups(lower.begin(), lower.end());

    string result(removeDups.begin(), removeDups.end());

    return result;
}

string cleanStringOpt(string s){
    //When we find a letter in the input (say 'w'), we set that slot to true.
    bool present[26] {false};

    for(char c: s){
        if(isalpha(c)){
            c = tolower(c);
            present[c - 'a'] = true;
        }
    }

    //checking every alphabet 
    //so if 'a' is marked true in the array it will be automatically apended
    //in the string hence sorting it out instead of sort
    string result;
    for (char c = 'a' ; c < 'z'; c++){
        if(present[c - 'a']){//this outputs to if present[c - 'a'] = true
            result += c;     //present[a] = true? if yes append, if false move next
        }
    }
    return result;
}

int main(){
    string s = "William Henry Douglas";
    string so = "William Henry Douglas";
    cout<< cleanString(s) << endl;
    cout<< cleanStringOpt(so) <<  endl;
}