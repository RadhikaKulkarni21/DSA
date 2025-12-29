/*
Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
You cannot add consecuitve houses
*/
#include "R:\C++\Project1\lcHeader.h"

//dynamic programming
int totalMoney(vector<int> nums){
    int n = nums.size();

    if(n == 1){
        return nums[0];
    }

    vector<int>dp (n, 0);
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[2]);

    for(int i = 2;i < n;i++){
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        //it needs to be -2 as we do not want consecutive houses
    }

    return dp[n -1];
}
//time complexity O(n)
//Space complexity O(n) - additional data structure used89


//space optimization
int totalMoneyS(vector<int> nums){
    int prev = 0;
    int maxRob = 0;

    for(int money : nums){
        int temp = max(maxRob, prev + money);
        prev = maxRob;
        maxRob = temp;
    }
    return maxRob;
}
//time complexity O(n)
//Space complexity O(1)

int main(){
    vector<int> nums = {2,7,9,3,1};

    int result = totalMoney(nums);
    int maxRobbed = totalMoneyS(nums);
    cout<<"Total Money stolen: "<< result <<endl;
    cout<<"Total Money robbed: "<< maxRobbed <<endl;
}

/*
p =0, m= 0
temp = max(0,0+2) = 2
temp = 2, prev = 0; max = 2

temp = max(2, 0 + 7)
temp = 7, prev = 2, max = 7

temp = max(7, 2 + 9)
temp = 11, prev = 7, max = 11

temp = max(11, 7 + 3) - this will skip a house
temp = 11, prev = 11, max = 11

temp = max(11, 11 + 1)
temp = 12, prev = 11, max = 12
*/