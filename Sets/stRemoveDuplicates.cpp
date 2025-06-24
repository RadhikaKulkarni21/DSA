#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;


string vecToString(const vector<int>& vec) {
    string str = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        str += to_string(vec[i]);
        if (i < vec.size() - 1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
}

vector<int> removeDuplicates(const vector<int>& myList){
    //since unordered_sets only store unique values, we don't need to iterate to every element to find dups
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