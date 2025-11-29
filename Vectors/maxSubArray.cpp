#include "R:\C++\Project1\lcHeader.h"
/*
Title: Maximum Subarray Sum

Introduction: In computer science, one of the frequently encountered problems is 
determining the subarray (a contiguous portion of an array) that has the largest sum. 
This problem can be found in various applications, from image processing to 
financial analysis.

Objective: Given a list of integers, nums, find the contiguous subarray 
(which could contain at least one number) which has the largest sum, 
and return that sum.

Detailed Requirements:

Input:

A list of integers, nums, representing the array. 
The list can be of any length, including being empty.

Output:

An integer value representing the sum of the contiguous subarray with the largest sum.

Example 1:

Input:

nums: [-2,1,-3,4,-1,2,1,-5,4]

Output: 6

Explanation:
The contiguous subarray [4,-1,2,1] has the largest sum, which is 6.
*/

//this is being solved by Kadane's algorithm
//we take each value from the vector and add into current sum
//we check the prev values if they're less we discard them and start anew with next value
int maxSubarray(vector<int>& nums) {
	if(nums.empty())return 0;
	int maxSum = nums[0];//we put these at first value
	int currentSum = nums[0];
	for(int i = 1;i < nums.size();i++){//starting at 1 because [0] value is alread stored 
	        currentSum = max(nums[i], currentSum + nums[i]);
	        maxSum = max(maxSum, currentSum);
	}
	return maxSum;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int returnedResult = maxSubarray(nums);
    cout << "Input Vector: "; 
    printVector(nums); 
    cout << "RETURNED: " << returnedResult << "\n";
}

/*
{-2, 1, -3, 4, -1, 2, 1, -5, 4}

currSum = -2
maxSum = -2

1>-2 so -2 is not worth keeping
currSum = 1
maxSum = 1

next is -3 so we start over as -3 can be discarded
currSum = 4
maxSum = 4 
4+-1+2+1
currSum = 6
maxSum = 6
-5 breaks this array and we start again ar 4
currSum = 4
maxSum = 6
hence the ans is {4,-1,2,1}
*/