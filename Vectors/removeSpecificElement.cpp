#include "R:\C++\Project1\lcHeader.h"
/*
Write a function that takes in two parameters: 
a list of numbers (nums) and a target number (val). 
The goal is to remove all occurrences of the target number 
from the list without creating a new list. After the removals, 
the list should not have any gaps between the remaining numbers. 
The function should not return the modified list since 
it will be modified in place; however, 
the function should resize the list so that the remaining 
length matches the number of items left after the removals.

Example 1:

Input:

nums: [3, 2, 3, 6, 3, 4, 5, 3]

val: 3

Output:

Modified nums: [2, 6, 4, 5]
*/

void removeSpecificElement(vector<int>& nums, int val){
    //we get a varible to replace the value with pointer
    size_t i = 0;

    //iterate through the list to find the same value
    for(size_t j = 0;j < nums.size();j++){
        //we check if the value is same or not
        if(nums[j] != val){
            //if the value is not same just add it to ith place
            //if the value we don't do anything
            nums[i] = nums[j];
            i++;
        }
    }
    nums.resize(i);
}

int main(){
    vector<int> newVect = {2,3,2,3,4};

    cout<< "Before:"<<endl;
    printVector(newVect);
    removeSpecificElement(newVect, 3);
    cout<<"After:"<<endl;
    printVector(newVect);
}
//original vector [2,3,2,3,4]
//expected vector [2,2,4]

/*
Run 1 - 
i = 0; j = 2 val = 3
i = j ..... newVect [2,3,2,3,4]
i++ = 1

Run 2
i = 1 index j = 3 val = 3
we do nothing as condn is false

Run 3 
i = 1 index j = 2 val = 3
i[1] = 2 .... newVect[2,2,2,3,4]
i++ =  2

Run 4
i = 2 index; j = 3; val = 3
do nothing....newVect[2,2,2,3,4]

Run 5
i = 2 index; j = 4; val = 4
i[2] = 4....newVect[2,2,4,3,4]
end of loop

resize(i)[i = 3] = removes the end elements which are not useful anymore 
or duplicates of whats already in the list
*/

