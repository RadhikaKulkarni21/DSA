#include "R:\C++\Project1\lcHeader.h"

/*
Write a function that, given a sorted list of integers, 
removes all consecutive duplicates and returns the length of the modified list. 
The function should perform the operation in-place, 
which means you shouldn't use an additional list to store the result.

Example 1:

Input:

nums: [1,1,2,2,2,3,4,4]

Output:

5

Modified nums:

[1,2,3,4,X,X,X,X] (wher+e X can be any number since it's beyond the new length)
*/

int removeDuplicates(vector<int>& nums){
    //0th index will always be unique so we start from 1st index
    int writePointer = 1;//this is a index thats why '1'
    if(nums.size() == 0) return 0;

    for(int readPointer = 1; readPointer < nums.size();readPointer++){
        if(nums[readPointer] != nums[readPointer - 1]){
            //we need the values here not the indices so pass the vector
            //writePointer = readPointer;
            nums[writePointer] = nums[readPointer];
            //move  the pointer to next index as new value is added each time
            writePointer++;
        }
    }
    return writePointer;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4};
    cout << "Before: "; printVector(nums); cout << "\n";
    int newSize = removeDuplicates(nums);
    cout << "After: "; printVectorNewSize(nums,newSize); cout << "\n";
}