#include "helperFunction.h"
/*
 Write a function that accepts a list of strings
and returns the longest string from the list.
Example 1:

Input:

stringList: ["apple", "banana", "kiwi"]

Output:

"banana" (since it has 6 characters, which is more than the others)

*/
string longestStringFunction(vector<string>& stringList){
    string longestString = "";
    for(string str: stringList){
        if(str.length() > longestString.length()){
            longestString = str;
        }
    }
    return longestString;
}

int main(){
    vector<string> stringList = {"cow", "ant", "cat"};
    printString(stringList);
    string result = longestStringFunction(stringList);
    cout<<result;
}
