#include "headerHashTables.h"

/*
Implement a function called findDuplicates() that finds and returns 
all the duplicate elements in a given vector of integers.
*/

vector<int> findDuplicates(const vector<int>& nums){
    unordered_map<int, int> numCounts;
    vector<int> duplicates;
    //putting each number from vector
    //Inside the for loop, the count of the current number (num) 
    //in the numCounts map is incremented by 1.
    for(int i : nums){
        numCounts[i]++;
    }

    for(const auto& value: numCounts){
        if(value.second > 1){//second will be value {key,value}
            duplicates.push_back(value.first);
        }
    }
    return duplicates;
} 

int main(){
    auto printVector = [](const vector<int>& v) {
        cout << "(";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << ", ";
        }
        cout << ")";
    };
  
        vector<int> nums = {1, 2, 3, 1, 5, 2};

        vector<int> result = findDuplicates(nums);

        cout << "RETURNED: ";
        printVector(result);
}