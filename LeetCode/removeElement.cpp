/*
remove element from an array in place and return the length of the array
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    int removeElement(vector<int>& nums, int val){
        int k = 0;
        for(int i= 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main(){
    vector<int> nums = {2,3,3,2};
    int val = 2;
    Solution sol;
    cout<< sol.removeElement(nums, val);
}