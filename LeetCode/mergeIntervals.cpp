/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, 
and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

Similar to: 
https://github.com/RadhikaKulkarni21/DSA/blob/master/Others/arrayConcurrentEvents.cpp
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
    public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){ return a[0] < b[0]; });

        vector<vector<int>> merged;

        //the first vector will be present no matter what
        vector<int> prev = intervals[0];

        //we are comparing last element in vector 1 with first element in vector2
        for(int i = 1; i < intervals.size();i++){
            vector<int> interval = intervals[i];

            if(interval[0] <= prev[1]){
                prev[1] = max(prev[1], interval[1]);
            }
            else{
                merged.push_back(prev);
                //interval is intervals[i]
                prev =  interval;
            }
        }
        //to add the last interval
        //the interval gets updated in for loop
        //so prev will be prev++
        merged.push_back(prev);
        return merged;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    printVectOfVect(s.mergeIntervals(intervals));
}