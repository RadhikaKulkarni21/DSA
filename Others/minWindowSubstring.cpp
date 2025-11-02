#include "header.h"

string minWindowSubstring(string s, string t){
    unordered_map<char, int> winCount;

    //count all the characters in t string
    unordered_map<char, int> tCount;

    int m = s.length();
    int tl = t.length();

    //neither exists
    if(m == 0 || tl == 0){
        return "";
    }
    
    //keeping characters count of each c in t
    for(char c : t){
        tCount[c]++;
    }
    
    //sliding window pointers
    int right = 0, left = 0;

    int counter = 0;

    int ans[3] = {-1,0,0};
    
    while(right < m){
        char c = s[right];
        winCount[c]++;

        if(tCount.find(c) != tCount.end() && winCount[c] == tCount[c]){
            counter++;
        }
        while(left <= right && counter == tCount.size()){
            c = s[left];

            if(ans[0] == -1 || right - left + 1 < ans[0]){
                ans[0] = right - left + 1;
                ans[1] = left;
                ans[2] = right;
            }

            winCount[c]--;
            if(tCount.find(c) != tCount.end() && winCount[c] < tCount[c]){
                counter--;
            }
            left++;
        }
        right++;
    }

    return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout<<minWindowSubstring(s, t);
}