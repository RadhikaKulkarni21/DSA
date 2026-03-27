/*
The power of an integer x is defined as the number of steps needed to transform x
into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 
because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. 
The task is to sort all integers in the interval [lo, hi] 
by the power value in ascending order, 
if two or more integers have the same power value sort them by ascending order.

Return the kth integer in the range [lo, hi] sorted by the power value.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public: 
    int solve(int n){
        unordered_map<int, int> dp;
        if(n == 1) return 0;

        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        if(n % 2 == 0) return dp[n] = 1 + solve(n/2);

        return dp[n] = 1 + solve(3 * n + 1);
    }
    
    //recursive
    int getKth(int lo, int hi, int k){
        vector<pair<int, int>> ans;
        for(int i = lo; i < hi; i++){
            ans.push_back({solve(i), i});
        }

        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }

    int getKthIt(int lo, int hi, int k){
        vector<pair<int, int>> v;

        for(int i = lo; i <=hi; i++){
            int ans = 0;
            int x = i;

            while(x != 1){
                if(x % 2){
                    x = 3 * x + 1;
                }
                else{
                    x = x / 2;
                }
                ans++;
            }
            v.push_back({ans, i});
        }
        sort(v.begin(), v. end());
        return v[k - 1].second;
    }
};

int main(){
    Solution s;
    int lo = 12;
    int hi = 15;
    int k = 2;

    cout << s.getKth(lo, hi, k);
}