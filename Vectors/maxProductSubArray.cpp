#include "R:\C++\Project1\lcHeader.h"

/*
Given an integer array nums, find a subarray that has the largest product, 
and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
//this is extention of Kadane's algorithm

int maxProduct(vector<int>& nums){
    int maxP = nums[0];
    int minP = nums[0];
    int res = maxP;

    for(int i = 1;i < nums.size();i++){
        int curr = nums[i];

        int temp = max(curr, max(curr * maxP, curr * minP));
        minP = min(curr, min(curr * maxP, curr * minP));

        maxP = temp;
        res = max(res, maxP);
    }
    return res;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int returnedResult = maxProduct(nums);
    cout << "Input Vector: "; 
    printVector(nums); 
    cout << "RETURNED: " << returnedResult << "\n";
}