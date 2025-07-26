//Honestly such a confusing question and so poorly worded
/*
You are given an integer array arr. From some starting index, 
you can make a series of jumps. 
The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, 
and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps.
Note that the jumps are numbered, not the indices.

You may jump forward from index i to index j (with i < j) in the following way:

During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j 
such that arr[i] <= arr[j] and arr[j] is the smallest possible value. 

If there are multiple such indices j,
you can only jump to the smallest such index j.

During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j 
such that arr[i] >= arr[j] and arr[j] is the largest possible value. 

If there are multiple such indices j, 
you can only jump to the smallest such index j.

It may be the case that for some index i, there are no legal jumps.
A starting index is good if, starting from that index, 
you can reach the end of the array (index arr.length - 1) 
by jumping some number of times (possibly 0 or more than once).

Return the number of good starting indices.
*/

#include "lcHeader.h"

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        vector<pair<bool,bool>> dp = {arr.size(), {0, 0}};

        map<int, int> indexMap;

        dp[arr.size() - 1] = {1,1};
        int ans = 1;

        for(int i = (arr.size() - 1); i >= 0;i--){
            auto itr = indexMap.lower_bound(arr[i]);

            if(itr != indexMap.end()){
                ans += dp[i].first =  dp[itr->second].second;
            }

            if(itr->first == arr[i]) itr++;

            if(itr != begin(indexMap)){
                dp[i].second = dp[prev(itr)->second].first;
            }
            indexMap[arr[i]] = i;
        }
        return ans;
    }
};