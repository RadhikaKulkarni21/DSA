#include "lcHeader.h"

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

//solution one with hash sets
vector<vector<int>> threeSum(vector<int>& nums){
    set<vector<int>> res;
    unordered_map<int, int> seen;//store complement
    unordered_set<int>dups;//check if we've already seen complement

    for(int i = 0; i <nums.size();i++){
        if(dups.insert(nums[i]).second){
            for(int j = i + 1;j < nums.size();++j){
                //nums[i] + nums[j] + complement = 0
                int comp = -nums[i] - nums[j];
                
                auto it = seen.find(comp);
                //Check if the complement was seen earlier in the same outer loop iteration
                //ensures that the complement was seen after i started
                if(it != end(seen) && it->second == i){
                    //Sort the triplet so that [a, b, c] and [b, c, a] are treated 
                    //as duplicates and eliminated by the set.
                    vector<int> triplet = {nums[i], nums[j], comp};
                    sort(begin(triplet), end(triplet));
                    res.insert(triplet);
                }
                seen[nums[j]] = i;
            }
        }
        return vector<vector<int>> (begin(res), end(res));
    }
}

/*
Iterate through nums, using each number once as the first element of the triplet.

For each first number, use a seen map to track complements.

When a valid complement is found, store the sorted triplet.

Use a set to automatically eliminate duplicate triplets.
*/

//easier solution using two pointers approach
//check twoSum
//https://github.com/RadhikaKulkarni21/DSA/blob/master/LeetCode%20Google/twoSumSortedArray.cpp

vector<vector<int>> threeSumPointer(vector<int> nums){
    vector<vector<int>> res;
    //sort those so we get the iden values next to eo
    sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i -1]) continue;
        //two pointers
        int l = i + 1, r = nums.size() - 1;

        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];

            if(sum > 0) r--; 

            else if(sum < 0) l++;

            else{
                res.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while(l < r && nums[l] == nums[l-1]) l++;
            }
        }
    }
    return (res);
}