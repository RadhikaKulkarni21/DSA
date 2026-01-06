/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
*/
#include "R:\C++\Project1\lcHeader.h"

vector<vector<int>> generate(int numRows){
    vector<int> prevRow;
    vector<vector<int>> result;

    for(int i = 0; i < numRows; i++){
        vector<int> currRow(i+1, 1);//size i+1 and all elements are 1
        //we need 1,x,x,1 kinda formation
        
        for(int j = 1; j < i;j++){
            currRow[j] = prevRow[j - 1] + prevRow[j];
            //adding the elements from one row above
        }

        result.push_back(currRow);
        //change the prev to the one just made
        prevRow = currRow;
    }
    return result;
}

int main(){
    int numRows = 5;

    generate(numRows);
}