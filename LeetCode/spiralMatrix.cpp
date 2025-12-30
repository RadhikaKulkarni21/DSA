/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/
#include "R:\C++\Project1\lcHeader.h"

vector<int> spiralOrder(vector<vector<int>> matrix) {
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    
    int top = 0;//first row
    int bot = m;//last row
    int left = 0;//first col
    int right = n;//last col

    vector<int> res;

    while(top <= bot && left <= right){
        //top row
        for (int i = left;i <= right; i++){
            res.push_back(matrix[top][i]);//1,2,3
        }
        top++;

        //right col
        for(int j = top; j <= bot; j++){
            res.push_back(matrix[j][right]);//3,6,9
        }
        right--;

        //bottom row
        if(top<=bot){//so that we dont reach out of bounds while --
            for(int k = right; k >= left; k--){
                res.push_back(matrix[bot][k]);//8,7
            }
        }
        //after first pass, it will break out of the loop
        //-- will secure us the next value = 7
        bot--;

        //left col
        if(left<=right){
            for(int l = bot; l >= top;l--){
                res.push_back(matrix[l][left]);//4,5
            }
        //after first pass, it will break out of the loop
        //++ will secure us the next value = 5
            left++;
        }
        
    }
    return res;
}

/*
Traverse the top row from left to right and add elements to res. 
Increment top to move the boundary downward.

Traverse the right column from top to bottom and add elements to res. 
Decrement right to move the boundary inward.

If top <= bottom, traverse the bottom row from right to left in reverse order 
and add elements to res. Decrement bottom to move the boundary upward.

If left <= right, traverse the left column from bottom to top in reverse order 
and add elements to res. Increment left to move the boundary inward.
*/

int main(){
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
    printVector(spiralOrder(nums));
}

/*
first pass
[0,0][0,1][0,2] - 1 2 3
top = 0 bot = 2 left = 0 right = 2

second pass
[1,2][2,2] - 6 9
top = 1, bot = 2, left = 0 right = 2

third pass
[2,1][2,0]
top 1 bot = 1 left = 0 right = 1

fourth pass 
[1,0][1,1]
top = 1 bot = 1 left = 1 right = 1
*/