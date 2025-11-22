#include "lcHeader.h"

void moveZeroes(vector<int>& nums){
    //we'll use two pointers 
    //the reader will traverse through the vector to find zero
    //the writer will traverse and change the zero with non zero

    int writer = 0;
    for(int reader = 0; reader < nums.size(); reader++){
        if(nums[reader] != 0){
            nums[writer++] = nums[reader];
        }
    }

    for(int i = writer; i < nums.size();i++){
        nums[i] = 0;
    }
}

int main(){
    vector<int> newVec = {1, 2, 0, 3, 0};
    printVector(newVec);
    moveZeroes(newVec);
    printVector(newVec);
}