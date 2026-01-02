#include "R:\C++\Project1\lcHeader.h"

void moveZeroes(vector<int>& nums){
    //we'll use two pointers 
    //the reader will read through the vector to find zero
    //the writer will traverse and write the zero with non zero

    int writer = 0;
    for(int reader = 0; reader < nums.size(); reader++){
        //we will check if the value is 0 or not, if it is not we move to next value
        if(nums[reader] != 0){
            nums[writer++] = nums[reader];
            //this is nums[writer++] = nums[reader];writer++;
        }
    }

    //to add zeros to the rest of the vector
    //reader will be out of bounds at one point 
    //so we will still need to fit rest of the vector
    for(int i = writer; i < nums.size();i++){
        nums[i] = 0;
    }
}

int main(){
    vector<int> newVec = {0, 2, 0, 3, 0};
    printVector(newVec);
    moveZeroes(newVec);
    printVector(newVec);
}