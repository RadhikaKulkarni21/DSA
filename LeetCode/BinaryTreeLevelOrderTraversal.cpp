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
            //to store each of the element in this
            vector<int> v;
            for(int i = 0; i < s; i++){
                TreeNode *node = newQueue.front();
                newQueue.pop();

                //we traverse and push each value of node
                v.push_back(node->val);
                //we right/left exist we go again the loop for next vector
                //only one value is added
                //if left and right child exist 2 values will be added as queue size
                //would be two
                if(node->left != NULL) newQueue.push(node->left);
                if(node->right != NULL) newQueue.push(node->right);
            }
            //then store each vector into vector
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

/*
This is similar to BFS
https://github.com/RadhikaKulkarni21/DSA/blob/master/Tree%20traversal/traversalBFS.cpp
for using int s = newQueue.size()
the size changes dynamically as you push children inside the loop.
For example, if a level has 2 nodes, the loop starts with i < 2,
but after popping the first node and pushing its children, 
the size might become 3. So the loop runs more times than it should,
bleeding nodes from the next level into the current level.
*/