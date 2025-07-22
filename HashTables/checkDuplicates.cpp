#include "R:\C++\Project1\LeetCode Google\lcHeader.h"

//Method 1: Linear search - traverse through the whole vector to find two nums
//O(n^2) two for loops and if condn

//Method 2: Sorted vector - sort the vector, check if two adjacent values are same
//O(nlogn) for loop and if condn

//Method 3: Hash - unordered_maps - by counting freq of each int
//O(n) 2 foreach

bool checkDuplicates(vector<int>& nums){
    //we use an unordered map for counting the frequecy of each number
    unordered_map<int, int> freq;
    for(int n : nums){
        //add freq of each number
        freq[n] += 1;
    }
    for(auto i : freq){
        //if the value of each key[number] is > 1 
        if(i.second > 1){
            return true;
        }
    }
    return false;
}

//there's another way of doing this using hashmaps
bool checkDups(vector<int>& nums){
    unordered_map<int, int> seen;

    for(int n : nums){
        if(seen[n] >= 1){
            return true;
        }
        seen[n]++;//this is adding the freq of the said n if the 'if' is false
    }

    return false;
}

int main(){
    vector<int> newVec = {1, 2, 3, 4, 8, 2};
    bool result1 = checkDups(newVec);
    bool result2 = checkDuplicates(newVec);
    cout<< result1 << endl << result2;
}