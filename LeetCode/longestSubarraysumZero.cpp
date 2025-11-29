/*
https://www.geeksforgeeks.org/dsa/find-the-largest-subarray-with-0-sum/

Given an integer array, find length of longest contiguous subarray
whose sum equals zero.
nums = 15 -2 2 -8 1 7 10 23
longest
*/

#include "R:\C++\Project1\lcHeader.h"

int longestSubarray(vector<int>& nums){
    int n = nums.size();
    
    int len = 0;

    for(int i = 0; i < n;i++){
        int currSum = 0;
        for(int j = i; j < n; j++){
            currSum += nums[j];

            if(currSum == 0){
                len = max(len, j-i+1);
            }
        }
    }
    return len;//O(n^2)
}

int htLongestSubarray(vector<int>& nums){
    int n = nums.size();
    int currSum = 0;
    int maxLen = 0;

    unordered_map<int,int> lastSeen;
    lastSeen[0] = -1;

    for(int i = 0; i < n; i++){
        currSum += nums[i];

        if(lastSeen.find(currSum) != lastSeen.end()){
            int index = lastSeen[currSum];
            int len = i - index;
            maxLen = max(maxLen, len);
        }
        else{
            lastSeen[currSum] = i;
        }
    }
    return maxLen;//O(n)
}

int main(){
    vector<int> nums = {15,-2,2,-8,1,7,10,23};
    printVector(nums);
    cout<<longestSubarray(nums)<<endl;
    cout<<htLongestSubarray(nums)<<endl;
}

