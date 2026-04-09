/*
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).
*/
#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> newQueue;
        newQueue.push(root);
        while(!newQueue.empty()){
            int s = newQueue.size();
            vector<int> v;
            for(int i = 0; i < s; i++){
                TreeNode *node = newQueue.front();
                newQueue.pop();

                v.push_back(node->val);
                if(node->left != NULL) newQueue.push(node->left);
                if(node->right != NULL) newQueue.push(node->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> answer = sol.levelOrder(root);
    printVectOfVect(answer);
}