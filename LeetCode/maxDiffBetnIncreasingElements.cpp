/*
Given a 0-indexed integer array nums of size n, 
find the maximum difference between nums[i] and nums[j] 
(i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.


Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6,
but i > j, so it is not valid.
*/
#include "R:\C++\Project1\lcHeader.h"

int maximumDifference(vector<int>& nums) {
    int maxdif = -1;
    for(int i = 0;i < nums.size(); i++){
        for(int j = i + 1; j < nums.size();j++){
            if(nums[i] < nums[j]){
                int sub  = nums[j] - nums[i];
                maxdif = max(maxdif,sub);
            }
        }
    }
    return maxdif;
}
//time complexity: O(n^2)

int maxDiff(vector<int>& nums){
    int xMin = nums[0], n = nums.size();
    int maxD = -1;
    for(int i = 1; i < n; i++){
        //compare the current value in index i with xmin
        //if smaller xmin becomes that
        int x = nums[i];
        if (x <= xMin){
            xMin = x;
        }
        else{
            //update the difference of it
            maxD = max(maxD, x - xMin); 
        }
    }
    return maxD;
}

//time complexity: O(n)

int main(){
    vector<int> nums = {7,1,5,4};
    cout<< maxDiff(nums)<<endl;
    cout<< maximumDifference(nums);
}