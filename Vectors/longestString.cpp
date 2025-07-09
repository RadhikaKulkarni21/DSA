#include "helperFunction.h"

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
    vector<string> stringList = {"elephant", "cow", "rhino"};
    printString(stringList);
    string result = longestStringFunction(stringList);
    cout<<result;
}
