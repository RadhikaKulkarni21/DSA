#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

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