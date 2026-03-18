/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";

        string pref = strs[0];
        int n = pref.length();

        for(int i = 1;i < strs.size();i++){
            string s = strs[i];

            while(n > s.length() || pref != s.substr(0,n)){
                n--;
                if(n == 0){
                    return "";
                }
                pref = pref.substr(0,n);
            }
        }
        return pref;
    }
};

int main(){
    vector<string> strs = {"flower","flow","flight"};
    vector<string> strs2 = {"race","car","dog"};

    Solution s;
    string result = s.longestCommonPrefix(strs2);

    (result.empty()) ? cout << "No prefix found" : cout << result; 
}