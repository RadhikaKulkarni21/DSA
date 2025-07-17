#include "lcHeader.h"
//sliding window solution
//we create a window of certain length and once the condn to keep the length k
//surpasses we move the window forward while removing the elements
//so to move the window to right we remove the elements from left

class Solution{
    public:
    int totalFruits(vector<int> fruits){
        //hash to store the values of each unique fruit
        unordered_map<int, int> uniqueFruits;
        int left = 0;
        //for space complexity so at any given time in the window there are only 2 unique
        //elements
        int maxPicked = 0;

        for(int right = 0; right < fruits.size(); right++){
            //adding into the map
            uniqueFruits[fruits[right]]++;
            //if we get size more than 2 so we drop the left elements
            if(uniqueFruits.size() > 2){
                uniqueFruits[fruits[left]]--;//this is removing from the map
                //if there are 0 fruits than we can just remove that entirely
                if(uniqueFruits[left] == 0){
                    uniqueFruits.erase(left);
                }
                left++;//this is moving the index forward
            }
            maxPicked = max(maxPicked, right - left + 1);
        }
        return maxPicked;
    }
};

int main(){
    vector<int> fruits = {1,2,1};
    Solution newSolution;
    int result = newSolution.totalFruits(fruits);
    cout<<result;
}

/*
You are visiting a farm that has a single row of fruit trees 
arranged from left to right. The trees are represented by 
an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. 
However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.

Starting from any tree of your choice, 
    -you must pick exactly one fruit from every tree (including the start tree) 
    while moving to the right. The picked fruits must fit in one of your baskets.
    -Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:

Input: fruits = [1,2,3,2,2]
Output: 
Explanation: We can pick from  trees.
*/