#include "R:\C++\Project1\lcHeader.h"
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

You must write a solution in O(log(m * n)) time complexity.
*/

class Solution{
    public:
    bool search2Dmatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        //binary search since its in sorted

        int low = 0;
        int high = (m * n) - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int midValue = matrix[mid / n][mid % n];//we need the value not the index

            if(midValue == target) return true;

            else if(midValue > target){
                high = mid - 1;
            }
            else{
                low = mid  + 1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    int target = 11;

    Solution s1;

    bool result = s1.search2Dmatrix(matrix, target);

    result == true ? cout << "Element is present" : cout<<"Element is not present";
}