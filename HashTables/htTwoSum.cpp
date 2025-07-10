#include "headerHashTables.h"

/*
Implement a function called twoSum() that finds two numbers in a 
given vector of integers that add up to a specific target number.

If there are two pairs of numbers that sum to the target it is 
assumed that you're looking for the first pair of numbers
that sum to the target, based on their position in the array 
Consider the following input vector and target:

nums: {1, 3, 4, 2, 5};
target: 6;
There are two combinations that add up to 6 which are:

{2, 3} and {0, 4}
After calling twoSum(nums, target), 
the result should be the first pair of numbers that sum to the target:

{2, 3}

*/

vector<int> twoSum(const vector<int>& nums, int target) {
	//   | - 'numMap' stores numbers and their indices.        |
	//   | - 'complement' is the value needed to reach target. |
	//   | - Use 'find' method for quick look-up in map.       |
    
	unordered_map<int, int> numMap;
    for(int i = 0;i< nums.size();i++){
        //assiging the value to num
        int num = nums[i];

        int complement = target - num;

        //we are storing each 'not found' value in the unordered map, 
        //hence we can use the find here. So each loop which doesnt contain 
        //the pair will be stored and once we find the complement in this, 
        //we will be thrown out with return.
        if(numMap.find(complement) != numMap.end()){

        // If we found the complement, this means 'num' 
            // and 'complement' are the pair of numbers we 
            // are looking for. So, we'll return their 
            // positions from the list as our answer.
            return {nums[complement],i};
        }

        // If we haven't found the pair, we save the current 
        // number 'num' and its position 'i' into 'numMap' 
        // for future checks. This means, "Hey map, remember 
        // that I've seen this number at this position!"
        numMap[num] = i;
    }
	return {};
}

int main(){
        vector<int> nums{3, 3, 4, 4};
        int target = 6;
        vector<int> result = twoSum(nums, target);
        //ternary operator if(result is empty) then "" else send result[0]
    cout << "("<<(result.empty() ? "" : to_string(result[0])) << ", " << (result.empty() ? "" : to_string(result[1])) << ")\n";
}