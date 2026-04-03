/*
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue
red = 0 
white = 1
blue = 2
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    void sortColors(vector<int>& nums){
        int r = 0;
        int b = nums.size() - 1;
        int w = 0;

        while(w <= b){
            if(nums[w] == 0){
                swap(nums[w], nums[r]);
                r++;
                w++;
            }
            else if(nums[w] == 2){
                swap(nums[w], nums[b]);
                b--;
            }
            else{
                w++;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,0,1};
    cout << "Unsorted Array:" << endl;
    printVector(nums);
    sol.sortColors(nums);
    cout << "Sorted Array: " << endl;
    printVector(nums);
}