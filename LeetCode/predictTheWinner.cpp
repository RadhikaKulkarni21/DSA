//https://leetcode.com/problems/predict-the-winner/description/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
    int dp[21][21];

    bool checkWin(int ans, int total){
        return ans >= total - ans;
    }

    int maxScore(vector<int>& a, int total, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] =  total - min(maxScore(a, total- a[i], i + 1, j), maxScore(a, total - a[j], i, j - 1));
        return dp[i][j];
    }
    public:
    bool predictTheWinner(vector<int>& nums){
        int total = 0;
        for(int i = 0; i < 21; i++){
            for(int j = 0; j < 21; j++){
                dp[i][j] = -1;
            }
        }
        for (auto n : nums){
            total+= n;
        }
        return checkWin(maxScore(nums, total, 0, nums.size() -1), total);
    }
};

int main(){
    vector<int> nums = {1,5,233,7};
    Solution s;
    bool result = s.predictTheWinner(nums);
    cout<< result ? "True" : "False";
}