/*
Given a binary string s ​​​​​without leading zeros, 
return true​​​ if s contains at most one contiguous segment of ones. 
Otherwise, return false.
*/

#include "R:\C++\Project1\lcHeader.h"

bool checkOnesSegment(string s){
    for(int i = 1; i <  s.size();i++){
        if(s[i - 1] == '0' && s[i] == '1'){
            //even if there are multiple 1 1 in the segment, it will give false
            return false;
        }
    }
    return true;
}

int main(){
    string s = "1011";
    string res = checkOnesSegment(s)? "True" :"False";
    cout<<res;
}

/*
Check for any occurrence of '0' followed immediately by '1'.
If found, return false (more than one segment of 1s).
If no such pattern exists, return true.
*/