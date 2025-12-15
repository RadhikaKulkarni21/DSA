#include "R:\C++\Project1\lcHeader.h"

bool isNonTrivialRotation(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    if (s1 == s2) return false;
    int n = s1.size();
    for (int i = 0; i < n; ++i) {
      	// if current rotation is equal to s2 return true
        if (s1 == s2)
            return true;
      
      	// right rotate s1
        char last = s1.back();
        s1.pop_back();
        s1 = last + s1;
    }
    return false;
}

int main(){
    string s1 = "abcde";
    string s2 = "cdeab";

    cout<<isNonTrivialRotation(s1,s2);
}