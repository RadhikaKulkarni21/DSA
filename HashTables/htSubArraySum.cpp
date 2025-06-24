#include <unordered_map>
#include <vector>
#include <array>
#include <iostream>
#include <string> 
using namespace std;


vector<int> subarraySum(const vector<int>& nums, int target) {
    //   | - 'sumIndex' stores cumulative sums and their       |
	//   |   indices.                                          |
	//   | - 'currentSum' keeps track of the sum up to index i.|
	//   | - Use 'find' method for quick look-up in map.       |
	//   | - Check output from Test.cpp in "User logs".        |
    unordered_map<int, int> sumIndex;
    //we need to set the intial value of sum to {0,-1} so when we iterate through the loop it will auto change the value to {value, 0}
    sumIndex[0] = -1;
    
    //store sum
    int currentSum = 0;

    for(int i = 0; i<nums.size();i++){
        //adding the first to current
        currentSum += nums[i];

        //iterate till this is true and return the array
        if(sumIndex.find(currentSum - target) != sumIndex.end()){
            return {sumIndex[currentSum - target]+1,i};
        }
        //if the above if is false we just keep adding i in sumIndex
        sumIndex[currentSum] = i;
    }
    return {};
}

int main(){

    vector<int> nums{1, 2, 3, 4, 5};
    int target = 10;
    vector<int> result = subarraySum(nums, target);
    //need the ternary operator because we are producing two different ints
    cout << "RETURNED: Indices (" << (result.empty() ? "" : to_string(result[0])) << "," 
             << (result.empty() ? "" : to_string(result[1])) << ")\n";
}