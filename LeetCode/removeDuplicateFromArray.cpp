/*
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​.
After removing duplicates, return the number of unique elements k.
*/
#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
    if(nums.empty()) return 0;

    //first number will always be unique as list is sorted
    //hence we move to 1 position
    int i = 1;

    //we will compare each element at j wiht [i - 1],
    //if the element is same we do nothing and i++ j++
    //If the elements are same we replace the i with j value
    //Now all the unique elements are the start
    //once J is out of range the loop stops and we are left with sole 
    //unique item
    for(int j = 1;j <  nums.size(); j++){
        if(nums[j] != nums[i - 1]){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
};

int main(){
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    cout<< "Unique elements: "<< s.removeDuplicates(nums)<<endl;
    //expected OP: 0 1 2 3 4 - 5 unique elements
}

//This is a in place question, if we want to return an array, it would require
//another data structure to store it
//either use another vector or simply add the vector in set to solve it