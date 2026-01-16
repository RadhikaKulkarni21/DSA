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

        //map all the numbers with corresponding letters
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
//we need to use reference here so that the back tracking is actually working
//on the modified vector and not the copy of vector
//which will reuslt in empty vector
    void backTrack(string& digits, int i, string comb,vector<string>& result, unordered_map<char, string>& number){
        if(i == digits.size()){
            result.push_back(comb);//pushes ad,ae,af
            return;
        }

        string letters = number.at(digits[i]);
        //we force each letter through back tracking and keep adding it in comb to make
        //combination
        for(char l : letters){
            backTrack(digits, i + 1, comb + l, result, number);
        }
    }
};
/*
for i = 1 it will start with a and go and explore 3 until it reaches the end
the i++ goes to b and explores 3 again and keeps on doing it till we reach the end
backtrack(i=0, comb="")
 └─ backtrack(i=1, comb="a")
     ├─ backtrack(i=2, comb="ad") → add "ad"
     ├─ backtrack(i=2, comb="ae") → add "ae"
     └─ backtrack(i=2, comb="af") → add "af"
*/

int main(){
    Solution s;
    string digits = "23";

    printString(s.letterCombinations(digits));
}


/*
digits = "23"
Mapping:

2 → "abc"
3 → "def"

backtrack("23", 0, "", result, number);

Initially:
i = 0
comb = ""
result = []

Level 1 recursion (digit '2')
letters = "abc"
We loop over each letter.

Case 1: choose 'a'
backtrack("23", 1, "a", result, number);

State:
i = 1
comb = "a"

Level 2 recursion (digit '3')
letters = "def"
Loop again.

Choose 'd'
backtrack("23", 2, "ad", result, number);
Now:

i == digits.size()  // 2 == 2

result.push_back("ad");
Result:

["ad"]
Return to previous level.

Choose 'e'
backtrack("23", 2, "ae", result, number);
Base case → add:

["ad", "ae"]
Choose 'f'
backtrack("23", 2, "af", result, number);
Base case → add:

["ad", "ae", "af"]
Return to Level 1.

//we will keep chosing a each time as 

Case 2: choose 'b'
backtrack("23", 1, "b", result, number);
Repeat same process:

"bd", "be", "bf"
Result now:

["ad","ae","af","bd","be","bf"]
Case 3: choose 'c'
backtrack("23", 1, "c", result, number);
Adds:

"cd", "ce", "cf"
Final result
["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/