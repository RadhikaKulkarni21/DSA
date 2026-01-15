/*
Given string num representing a non-negative integer num,
and an integer k, return the smallest possible integer after removing k digits from num.
*/

#include "R:\C++\Project1\lcHeader.h"

string removeKdigits(string num, int k)
{
    string ans = "";
    for (char &c : num){
        //ans.size() to check if the ans is empty
        //ans.bacl alst element in string
        while (ans.size() && ans.back() > c && k){
            ans.pop_back();
            k--;
        }
        //avoiding the zero at the end
        //since this is or, does not matter either one is true
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

/*
ex: 1432219

c = 1 while skip if(c != 0) ans = "1" k = 3
c = 4 while skip if(c != 0) ans = "14" k = 3
c = 3 while 4>3 pop 4 if(c != 0) ans = "13" k = 2
c = 2 while 3 > 2 pop 3 if(c != 0) ans = "12" k = 1
c = 2 while skip if(c != 0) ans = "122" k = 1
c = 1 while 2>1 pop 2 if(c != 0) ans = "121" k = 0
c = 1 while skip k = 0 if(c != 0) ans = "1219"

No second while as k = 0
*/

