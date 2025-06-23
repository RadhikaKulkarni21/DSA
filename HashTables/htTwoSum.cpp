#include <unordered_map>
#include <vector>
#include <array>
#include <iostream>
#include <string> 
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
	//   | - 'numMap' stores numbers and their indices.        |
	//   | - 'complement' is the value needed to reach target. |
	//   | - Use 'find' method for quick look-up in map.       |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
	unordered_map<int, int> numMap;
    for(int i = 0;i< nums.size();i++){
        //assiging the value to num
        int num = nums[i];
        int complement = target - num;
        //we are storing each 'not found' value in the unordered map, hence we can use the find here. So each loop which doesnt contain the pair will be stored and once we find the complement in this, we will be thrown out with return.
        if(numMap.find(complement) != numMap.end()){
            return {nums[complement],i};
        }
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