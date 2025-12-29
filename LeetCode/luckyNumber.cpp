/*Given an m x n matrix of distinct numbers, 
return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the 
minimum element in its row and maximum in its column.

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row 
and the maximum in its column.*/

#include "R:\C++\Project1\lcHeader.h"

vector<int> luckyNumbers(vector<vector<int>> matrix) {
    vector<int> resultNumber;

    //get the dimensions for rows and columns
    int n = matrix.size();
    int m = matrix[0].size();

    //store the min in rows and max in columns by comparing
    vector<int> rowMin(n, INT_MAX);
    vector<int> colMax(m, INT_MIN);

    for(int i = 0; i < n; i++){
        for(int j = 0; j  < m; j++){
            rowMin[i] = min(rowMin[i], matrix[i][j]);
            colMax[j] = max(colMax[j], matrix[i][j]);
        }
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(rowMin[i] == colMax[j]){
                resultNumber.push_back(rowMin[i]);
            }
        }
    }
    return resultNumber;
}

int main(){
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};

    vector<int> luckyNumber = luckyNumbers(matrix);
    printVector(matrix[0]);
    printVector(matrix[1]);
    printVector(matrix[2]);
    //cout<<luckyNumber.size();
    for(int i : luckyNumber){
        cout<< i;
    }
}

/*
3   7  8
9  11 13
15 16 17

time complexity O(n x m)
Space complexity O(n+m)
*/