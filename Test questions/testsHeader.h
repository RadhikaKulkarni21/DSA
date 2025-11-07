using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <queue>
#include <map>
#include <array>
#include <stack>
#include <numeric>
#include <sstream>
#include <cmath>

void printVector(const vector<int> nums){
    cout << "[";
    for(size_t i = 0; i < nums.size();i++){
        cout<<nums[i];
        if(i != nums.size() - 1){
            cout<< ", ";
        }
    }
    cout<<"]"<<endl;
}

void printStringVector(vector<string> s){
    cout<< "[";
    for(size_t i = 0; i < s.size(); i++){
        cout<<s[i];
        if(i != s.size() - 1){
            cout<<",";
        }
    }
    cout << "]" << endl;
}