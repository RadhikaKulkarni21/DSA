#include "lcHeader.h"

/*
Given an integer array nums, return an array answer such that 
answer[i] is equal to the product of all the elements of nums except nums[i].

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

vector<int> productExceptSelf(vector<int> nums){
    int n = nums.size();
    //n = size of answers vector 
    vector<int> answers(n,1);

    int left = 1, right = 1;

    for(int i = 0;i < n ;i++){
        answers[i] *= left;
        left *= nums[i];
    }

    for(int i = n - 1; i >= 0; i--){
        answers[i] *= right;
        right *= nums[i];
    }
    return answers;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> answer = productExceptSelf(nums);
    for(int n : answer){
        cout<<n<<" ";
    } 
}

/*
In the prefix loop, we save the product before multiplying by nums[i].

In the suffix loop, we multiply by suffix before multiplying by nums[i].


So in both loops, nums[i] never enters its own result.
That’s why each answer[i] ends up being product of all the other elements.

Prefix = product of all elements before i → skips nums[i] automatically.

Suffix = product of all elements after i → skips nums[i] automatically.

Multiplying answer[i] *= suffix gives product of everything except nums[i].

output = [24,12,8,6]
          1  0  0 0
          2  2  1 1
          3  3  3 2

At index 0, we don't use index 0.
At index 1, we don't use index 1.
At index 2, we don't use index 2.
At index 3, we don't use index 3.
*/