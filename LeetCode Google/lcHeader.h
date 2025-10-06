//#include "R:\C++\Project1\LeetCode Google\lcHeader.h"
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
