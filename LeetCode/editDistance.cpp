/*
Given two strings word1 and word2, 
return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
    public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        //creating a 2d matirx
        //of size m+1 and each vector inside is n + 1  and of value -1
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        //this will return the grid value that will contain the answer
        return dp(word1, word2, m, n, cache);
    }

    private:
    //the first i characters of word1
    //to the first j characters of word2

    int dp (string word1, string word2, int i, int j, vector<vector<int>> &cache){
        if(i == 0) return j;
        if(j == 0) return i;

        if(cache[i][j] != -1) return cache[i][j];

        if(word1[i - 1] == word2[j - 1]){
            cache[i][j] = dp(word1, word2, i - 1, j - 1, cache);//words match, we move next
        } else {
            cache[i][j] = 1 + min({//letters dont match we do this
                dp(word1, word2, i - 1, j, cache),     // Delete
                dp(word1, word2, i, j - 1, cache),     // Insert
                dp(word1, word2, i - 1, j - 1, cache)  // Replace
            });
        }
        //this returns single value in the grid
        return cache[i][j];
    }
};

int main(){
    string word1 = "horse";
    string word2 = "ore";

    Solution s;
    cout << "Min changes: " << s.minDistance(word1,word2);
}

/*
i will be the amount of letters in word 1 
j will be the amount of letters in word 2
   i j
dp(3,3)	"cat" → "cut"
dp(2,2)	"ca" → "cu"
dp(1,1)	"c" → "c"
dp(0,2)	"" → "cu"

we take the minimum cost required to fix the word
here the replacing of a with u takes min cost

we go matching each of the last character and when we hit a mismatch we 
either insert, delete or replace the character
if we delete it becomes i - 1, j
if we insert it becomes i, j - 1
replace will be i - 1, j - 1


cat      cut
t is same for both so
ca  cu

now we have three operations
delete   insert   replace
c => cu  ca => c  c => c

we need to think out of all the tree which would require the least
cost next time the problem runs
hence here it would be replace

        ""  e  x  e  c  u  t  i  o  n
     --------------------------------
"" |    0  1  2  3  4  5  6  7  8  9
i  |    1  1  2  3  4  5  6  6  7  8
n  |    2  2  2  3  4  5  6  7  7  7
t  |    3  3  3  3  4  5  5  6  7  8
e  |    4  3  4  3  4  5  6  6  7  8
n  |    5  4  4  4  4  5  6  7  7  7
t  |    6  5  5  5  5  5  5  6  7  8
i  |    7  6  6  6  6  6  6  5  6  7
o  |    8  7  7  7  7  7  7  6  5  6
n  |    9  8  8  8  8  8  8  7  6  5

Check image folder for more detailed long explanation
*/