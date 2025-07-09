#include "helperFunction.h"

int removeDuplicates(vector<int>& nums){
    //0th index will always be unique so we start from 1st index
    int writePointer = 1;
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