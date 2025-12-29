/*You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.*/

#include "R:\C++\Project1\lcHeader.h"

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    int top = 0;
    int bot = n - 1;

    //first we reverse the array
    //[0][0] will be at [3][0]
    //this will put the left diagnal elements in place
    while(top < bot){
        for(int i = 0; i < n ;i++){
            int temp = matrix[top][i];
            matrix[top][i] =  matrix[bot][i];
            matrix[bot][i] = temp;
        }
    }
    top++;
    bot--;

    //then we swap the rows and columns to get proper 90 rotation
    //[0][2] will be at [2][0]
    //now we need to put the right diagonal in place as well
    //and other non diagonal elements
    for(int i = 0;i < n;i++){
        for(int j = i +1; j < n;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

//time complexity O(n^2)
//space complexity O(1)

int main(){
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    printVector(matrix[0]);
    printVector(matrix[1]);
    printVector(matrix[2]);
    cout<<"rotated: "<< endl;
    rotate(matrix);
    printVector(matrix[0]);
    printVector(matrix[1]);
    printVector(matrix[2]);
}

/*
input:
1  2  3  
4  5  6  
7  8  9

reverse:
7  8  9  
4  5  6  
1  2  3

Transpose:
7  4  1  
8  5  2  
9  6  3  
*/