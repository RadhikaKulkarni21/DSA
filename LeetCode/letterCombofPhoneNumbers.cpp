/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.
Return the answer in any order.
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;

        unordered_map<char, string> number = {
            {'2',"abc"}, 
            {'3', "edf"}, 
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        backTrack(digits, 0, "", result, number);
        return result;
    }

private:
    void backTrack(string& digits, int i, string comb,vector<string>& result, unordered_map<char, string>& number){
        if(i == digits.size()){
            result.push_back(comb);
            return;
        }

        string letters = number.at(digits[i]);

        for(char l : letters){
            backTrack(digits, i + 1, comb + l, result, number);
        }
    }

};

int main(){
    Solution s;
    string digits = "23";

    printString(s.letterCombinations(digits));
}
