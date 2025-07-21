#include "R:\C++\Project1\LeetCode Google\lcHeader.h"

int minDepth(TreeNode* root){
    if(root == nullptr) return 0;

    //check for existance of childs and call other of child does not exist
    if(!root->left){
        return 1 + minDepth(root->right);
    }
    if(!root->right){
        return 1 + minDepth(root->left);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));
}


//I wonder why if the if conditions are flipped what will be the outcome
int minDepth(TreeNode* root){
    if(root == nullptr) return 0;

    //check for existance of childs and call the child if it exists
    if(root->left){
        return 1 + minDepth(root->left);
    }
    if(root->right){
        return 1 + minDepth(root->right);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));
}