/*
Given string num representing a non-negative integer num,
and an integer k, return the smallest possible integer after removing k digits from num.
*/

#include "R:\C++\Project1\lcHeader.h"

string removeKdigits(string num, int k)
{
    string ans = "";
    for (char &c : num){
        while (ans.size() && ans.back() > c && k){
            ans.pop_back();
            k--;
        }
        //avoiding the zero at the end
        if (ans.size() || c != '0'){
            ans.push_back(c);
        }  
    }
    while (ans.size() && k--){
        ans.pop_back();
    }
    return (ans == "") ? "0" : ans;
}

int main(){
    string num = "10200";
    int k = 1;

    cout<<removeKdigits(num, k);//exp op: 200
}

