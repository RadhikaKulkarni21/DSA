/*LOCAL COMMON HEADER*/
//#include "R:\C++\Project1\lcHeader.h"

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
#include <climits>
#include <limits>
#include <deque>
#include <functional>

//For linkedlist - Single and double
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//for tree traversing
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//numeric vector printing
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

//char vector print
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

//used somewhere
void printString(const vector<string>& strings){
    cout<<"[";
    for (const auto& str : strings) {
        cout << "\"" << str << "\" ";
    }
    cout << "]"<<endl;
}

//hash tables
void printGroups(const vector<vector<string>>& groups) {
    cout << "{ ";
    for (const auto& group : groups) {
        cout << "( ";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << ") ";
    }
    cout << "}\n";
};

//Sorting Algorithms
void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]"<<endl;
}

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

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

//new size to print resized vector
void printVectorNewSize(const vector<int>& nums, int newSize = -1) {
    cout << "[";
    int sizeToPrint = (newSize == -1) ? nums.size() : newSize;
    for (int i = 0; i < sizeToPrint; i++) {
        cout << nums[i];
        if (i < sizeToPrint - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}
