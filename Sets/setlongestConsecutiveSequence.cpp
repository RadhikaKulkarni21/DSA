#include "R:\C++\Project1\lcHeader.h"

/*
Write a function called longestConsecutiveSequence.

This function takes a list of numbers as input and finds the length 
of the longest sequence of numbers that can be arranged in order.

For example, if the list is [2, 1, 6, 9, 4, 3], 
the longest sequence in order is [1, 2, 3, 4], 
and the length is 4.
*/


int longestConsecutiveSequence(vector<int>& nums){
    unordered_set<int> numSet(nums.begin(),nums.end());
    int longestStreak = 0;
    for(int num : numSet){
        //check if the num is not already in the set
        if(numSet.find(num - 1) == numSet.end())
        {
            int current = num;
            //1 bc no matter what the next character there will always be one in set
            int currentStreak = 1;
            //need to check it there is a number after current  number
            while(numSet.find(current + 1) != numSet.end()){
                //if there is a number after current
                current++;
                currentStreak++;
            }
            longestStreak = max(longestStreak,currentStreak);            
        }
    }
     return longestStreak;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};    
    cout << "\nInput vector: ";
    for (int num : nums) cout << num << " ";
    cout<<'\n';
    int output = longestConsecutiveSequence(nums);
    cout << "Longest consecutive sequence = " << output;
}