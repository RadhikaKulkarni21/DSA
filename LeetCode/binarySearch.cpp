/*
Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.

 You must write an algorithm with O(log n) runtime complexity.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    int binarySearch(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }

    int linearSearch(vector<int>& nums, int target){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    int target = 7;
    vector<int> nums = {-1,0,3,5,9,12};

    cout<< "Binary Search: " << s.binarySearch(nums, target) 
    << endl;
    cout<< "Linear Search: " << s.linearSearch(nums, target);
}