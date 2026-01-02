/*
Given an unsorted array of integers nums, 
return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/
#include "R:\C++\Project1\lcHeader.h"

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> freq(nums.begin(), nums.end());
    int longest = 0;
    int len = 0;

    for(int n : freq){
        if(freq.find(n - 1) == freq.end()){
            len = 1;
        }
        //we are finding n + 1 here
        //so 1 + 1, 1 + 2, 1 + 3
        //similarly for each number
        while(freq.find(n + len) != freq.end()){
            len++;
        }
        longest = max(longest, len);
    }
    return longest;
}

int main(){
    vector<int> nums = {100,1,4,200,2};
    cout<<longestConsecutive(nums);
}