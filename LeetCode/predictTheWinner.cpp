//https://leetcode.com/problems/predict-the-winner/description/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
    //21 bc limit is >=20
    int dp[21][21];

    bool checkWin(int ans, int total){
        //ans is player1
        //total is player 2
        return ans >= total - ans;
    }

    int maxScore(vector<int>& a, int total, int i, int j){
        //i is the start element of array
        //j is the last element of array
        //total = sum of array
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        //i- j is used a boundary
        //both the players can only take from start or end of array
        //the total in max score will be of remainig  elements in array not main array
        dp[i][j] =  total - min(maxScore(a, total- a[i], i + 1, j), maxScore(a, total - a[j], i, j - 1));

        return dp[i][j];
    }
    public:
    bool predictTheWinner(vector<int>& nums){
        int total = 0;
        //making the dp matrix
        for(int i = 0; i < 21; i++){
            for(int j = 0; j < 21; j++){
                dp[i][j] = -1;
            }
        }
        //total sum of all the nums in array
        for (auto n : nums){
            total+= n;
        }
        return checkWin(maxScore(nums, total, 0, nums.size() -1), total);
    }
};

int main(){
    vector<int> nums = {3,9,1,2};
    Solution s;
    bool result = s.predictTheWinner(nums);
    string res = s.predictTheWinner(nums) ? "True" : "False";
    // if(result == 1){
    //     cout<< "True";
    // }
    // else{
    //     cout<< "False";
    // }
   cout << res;
}

/*
Array
[1, 5, 2]

maxScore([1,5,2], total=8, i=0, j=2)

Option 1: Take left (1)

Remaining array:
[5, 2]

Remaining total:
8 - 1 = 7

Opponent now plays
maxScore([5,2], 7, 1, 2) = 5
Opponent can guarantee 5 points

Option 2: Take right (2)

Remaining array:
[1, 5]

Remaining total:
8 - 2 = 6

Opponent plays 

maxScore([1,5], 6, 0, 1) = 5
Opponent can guarantee 5 points

The opponent wants to maximize their score
You want to minimize the opponent’s score

min(5, 5) = 5

Compute current player’s score
dp[0][2] = total - opponent_score
dp[0][2] = 8 - 5 = 3

Current player can guarantee 3 points

we compare checkwin(3,5)
player 2 wins hence false
*/