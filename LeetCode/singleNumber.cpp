/*
Given a non-empty array of integers nums, 
every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity - O(n)
and use only constant extra space O(n)
*/

#include "R:\C++\Project1\lcHeader.h"

int singleNumber(vector<int>& nums){
    unordered_map<int, int> freq;

    for(int n : nums){
        freq[n]++;
    }
    for(int n : nums){
        if(freq[n] == 1) return n;
    }
    return 0;
}

/*
The ^ (bitwise XOR) in C takes two numbers as operands 
and does XOR on every bit of two numbers. 
The result of XOR is 1 if the two bits are different. 
*/
int singleNumberXOR(vector<int>& nums){
    int XOR=0;
        for(int i=0;i<nums.size();i++){
            XOR=XOR^nums[i];
        }
        return XOR;
}

int main(){
    vector<int> nums = {4,1,2,1,2};
}