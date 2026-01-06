/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
#include "R:\C++\Project1\lcHeader.h"

int climbingStairs(int n){
    if(n <= 3)return n;

    //till 3 steps it will have n different ways
    int prev = 3;
    int prev2 = 2;
    int curr = 0;

    for(int i = 3; i < n; i++){
        //we count the three prev and move to 2 prev
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main(){
    int n = 4;
    cout<< climbingStairs(n);
}