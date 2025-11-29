#include "R:\C++\Project1\lcHeader.h"

int maxArea(vector<int>& height) {
    //we get the maxArea
    int maxArea = 0;
    //left pointer to start from 0
    int left = 0;

    //second pointer to traverse from end
    int right = height.size() - 1;

    //we need to make sure there are two ends
    while(left < right){

        //area will require height * wide
        int wide = right - left;//no +1 as the size is already -1

        //depending upon what side the pointer is smaller into 
        
        maxArea = max(maxArea, min(height[left], height[right]) * wide);

        //if left is big, we move in from the right and vice versa
        //we move the shorter area inward to maximize the surface

        if(height[left] <= height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxArea;
}

int main(){
    vector<int> height1 ={1,8,6,2,5,4,8,3,7};
    vector<int> height2  = {1,1};
    int area = maxArea(height2);
    cout<< area;
}

/*
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the 
ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.
*/