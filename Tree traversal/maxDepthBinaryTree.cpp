#include "R:\C++\Project1\LeetCode Google\lcHeader.h"

int maxDepth(TreeNode* root){
    //root is null reutrn 0
    if(root == nullptr) return 0;

    //we need to check if root has left or right child
    //so we use recursive fn to calculate each hops needed to perform

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    
    //(1 +) is the path itself so one hop from the child to root + whatever hops 
    //calculated from child's child
    return 1 + max(leftHeight, rightHeight);
}