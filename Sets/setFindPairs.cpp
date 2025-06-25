#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
    //   | - 'mySet' stores numbers from 'arr1'.                   |
    //   | - 'pairs' will store the pairs that meet the target.    |
    //   | - Loop through 'arr1' to populate 'mySet'.              |
    //   | - Loop through 'arr2' to find pairs.                    |
    //   | - Use 'find' method for quick look-up in set.           |
    //   +=========================================================+
    unordered_set<int> unSet;
    //vector to store two values
    vector<vector<int>> pairs;

    //setting into a array 
    for(int i : arr1){
        unSet.insert(i);
    }

    //it calculates the complement of num by subtracting it from target.
    for(int j :  arr2){
        int complement = target - j;
        //find the adjacent pair
        if(unSet.find(complement) != unSet.end()){
            pairs.push_back({complement,j});
        }
    }
    return pairs;
}

int main(){
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {4, 5, 6};
    int target = 8;
    vector<vector<int>> output = findPairs(arr1, arr2, target);

    cout << "arr1: ";
    for (int num : arr1) cout << num << " "<< endl;
    cout << "arr2: ";
    for (int num : arr2) cout << num << " "<<endl;
    cout << "Target: " << target << '\n';
    cout << "RETURNED: Pairs found = " << output.size() << '\n';
}