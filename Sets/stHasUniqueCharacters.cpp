#include "R:\C++\Project1\lcHeader.h"
/*
Write a function named hasUniqueChars.

The function checks if all the characters in a given text are unique or not.

If they are unique, the function will return true. 
If even one character is repeated, the function will return false.

Input Text :"hello"
Output false

In the word "hello," the letter 'l' appears twice. So, the output is false.

Input Text "world"

Output true

In the word "world," all the letters are different from each other. So, the output is true.
*/

bool hasUniqueChars(const string& str){
    unordered_set<char> charSet;

    //checking each character from str
    for(char ch : str){
        //Check if 'ch' is already in 'charSet' 
        if(charSet.find(ch)!= charSet.end()){
            //if its already present in the list, dups are present
            return false;
        }
        //enter the unique in set
        charSet.insert(ch);
    }
    return true;
}

int main(){
    string str = "abcdef";
    bool output = hasUniqueChars(str);
    //this will respond in 0 or 1, hence adding string
    cout<< (output ? "True":"False");
}