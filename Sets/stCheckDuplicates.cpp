#include "R:\C++\Project1\lcHeader.h"

bool hasUniqueChars(const string& str){
    unordered_set<char> charSet;

    //checking each character from str
    for(char ch : str){
        //Check if 'ch' is already in 'charSet' 
        if(charSet.find(ch)!= charSet.end()){
            //if its already present in the list, dups are present
            return false;
        }
        charSet.insert(ch);
    }
    return true;
}

int main(){
    string str = "abcdef";
    bool output = hasUniqueChars(str);
    cout<< (output ? "True":"False");
}