#include "R:\C++\Project1\lcHeader.h"

int CountBinarySubstring(string s){
    int counter = 0;//count stringd

    int preCount = 0; //length of previous consecutive 0s and 1s
    int currCount = 1;//length current group

    for(int i = 1;i < s.length(); i++){
        if(s[i] == s[i-1]){
            //if 0==0, we add it the the length of currentGroup
            currCount++;
        }
        else{
            counter += min(preCount, currCount);
            preCount = currCount;//length of previous group
            currCount = 1;//resey the current group
        }
    }
    counter += min(preCount, currCount);
    return counter;
}

int main(){
    string s = "00110011";
    int n = CountBinarySubstring(s);
    cout<<n;
}