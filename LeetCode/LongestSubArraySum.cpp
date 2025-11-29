#include "R:\C++\Project1\lcHeader.h"

int longestSubarrayWithSum(vector<int>& nums, int target) {
    unordered_map<long, int> firstIndex;
    firstIndex[0] = -1;            // prefix sum = 0 appears before the array

    long prefix = 0;
    int maxLen = 0;

    for (int i = 0; i < (int)nums.size(); ++i) {
        prefix += nums[i];//adding the first i in prefix

        long needed = prefix - target;//checkout fow  mant values are needed

        // If we've seen prefixSum(j) = needed, then j+1..i is a valid subarray
        //if needed is already in array, just end the length there
        if (firstIndex.count(needed)) {
            maxLen = max(maxLen, i - firstIndex[needed]);
        }

        //if needed is not present we store the needed in it
        // Only store the earliest index of each prefix sum
        if (!firstIndex.count(prefix)) {
            firstIndex[prefix] = i;
        }
    }

    return maxLen;
}

//O(n) time and O(n) space
