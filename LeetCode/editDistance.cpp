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
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
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
            cache[i][j] = dp(word1, word2, i - 1, j - 1, cache);
        } else {
            cache[i][j] = 1 + min({
                dp(word1, word2, i - 1, j, cache),     // Delete
                dp(word1, word2, i, j - 1, cache),     // Insert
                dp(word1, word2, i - 1, j - 1, cache)  // Replace
            });
        }
        return cache[i][j];
    }
};