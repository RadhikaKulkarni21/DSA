//Given the root of a binary tree, invert the tree, and return its root.
/*
        4                      4
    2       7      =>     7           2
1      3 6      9      9     6   3       1

*/
#include "R:\C++\Project1\LeetCode Google\lcHeader.h"

//Recursive
bool inverseBinaryTreeR(TreeNode* root){
    if(root == NULL) return NULL;

    TreeNode* temp;
    //using recursion go the child nodes
    inverseBinaryTreeR(root->left);
    inverseBinaryTreeR(root->right);

    //perform a swap of elements
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

//Iterative
bool inverseBinaryTreeI(TreeNode* root){
    //we will use queue
    queue<TreeNode*> bQueue;
    while(!bQueue.empty()){
        //push the root
        TreeNode* current = bQueue.front();
        bQueue.pop();

        //swap the nodes
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;

        //put them in place
        if(current->left != nullptr) bQueue.push(current->left);
        if(current->right != nullptr) bQueue.push(current->right);
    }
}