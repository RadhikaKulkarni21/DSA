//not functional
#include "lcHeader.h"

/*
A path in a binary tree is a sequence of nodes where each pair of 
adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

        3
    4      -1
8      1 -2    9
*/

class Solution{
public: 
int maxSum = INT_MIN;
    int binaryTreeMaxSum(TreeNode* root){
        gainFromSubTree(root);
        return maxSum;
    }

    int gainFromSubTree(TreeNode* root){
        //if root is null
        if(root == nullptr) return 0;
        //we need recursive func to go to the left most child
        //we compare it with zero so that if the child has -ve values, it can be skipped
        int gainFromLeft = max(gainFromSubTree(root->left), 0);
        int gainFromRight = max(gainFromSubTree(root->right), 0);

        maxSum = max(maxSum, gainFromLeft+gainFromRight+root->val);
        return root->val + max(gainFromLeft,gainFromRight);
    }

};
