#include "lcHeader.h"

/*
	Given an alphanumeric string
	- Remove all the alphabets
	- Sort the numbers
	- Print eg 2 3 4 5

*/

string printNumbers(string s){
    string filter;
    string result;
    string output;

    for(char c : s){
        if(isdigit(c)){
            filter += c;
        }
    }
    
    //sort(filter.begin(), filter.end());//TC: O(NLogN)

    //to replace this we use sets DS
    set<char> numbers;

    for(char n: filter){
        numbers.insert(n);
    }

    for(char n: numbers){
        result += (n);
    }
    
    for (int i = 0; i < result.length(); i++){
        output += result[i];
        if(i < result.size() - 1){
            output += ' ';
        }
    }
    
    return output;
}

int main(){
    string s = "C5HU9S37HS2";
    cout<<printNumbers(s);
}