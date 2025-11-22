#include "lcHeader.h"

//if array is not sorted
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>numMap;
    for(int i = 0;i < nums.size();i++){ 
        int num = nums[i];
        //we find the complement of each number in the vector
        int complement = target - nums[i];
        
        //try to find the compliment in the map
        //if it not present add it and keep iterating
        //once we find,return
        if(numMap.find(complement) != numMap.end()){
            //we need the addition so complement makes sense
            return{numMap[complement],i};
        }
        
        //update to add next value in map
        numMap[num] = i;
    }
    return{};
}

//if array is sorted in ascending order
vector<int> twoSum(vector<int>& numbers, int target) {
    int low = 0;
    int high = numbers.size() - 1;

    while(low < high){
        int sum = numbers[low] + numbers[high];

        if(sum == target){
            return{low + 1, high + 1};
        }

        //if sum is smaller than target  than we increase the lower number
        else if(sum  < target){
            low++;
        }

        //if sum is larger than target  than we decrease the higher number
        else if(sum > target){
            high--;
        }
    }
    return{-1,-1};
}


