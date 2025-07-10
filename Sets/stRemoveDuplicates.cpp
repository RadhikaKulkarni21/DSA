#include "headerSets.h"

/*
This function takes a list of numbers as input and returns a 
new list that has all the duplicate numbers removed.

Input List

[1, 2, 2, 3, 3, 3, 4, 5, 5, 6]

Output List

[1, 2, 3, 4, 5, 6]
*/

vector<int> removeDuplicates(const vector<int>& myList){
    //since unordered_sets only store unique values, we don't need to 
    //iterate to every element to find dups
    unordered_set<int>uniqueSet(myList.begin(),myList.end());
    return vector<int>(uniqueSet.begin(), uniqueSet.end());
}

int main(){
    //will print in reverse because we are adding elements in filo
    vector<int> myList = {1,1,2,3};
    cout<<"Before: " << vecToString(myList) << endl;
    vector<int>reuslt = removeDuplicates(myList);
    cout<<"After: " << vecToString(reuslt) << endl;
}