/*
Given the root of a complete binary tree, return the number of the nodes in the tree.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    int countNodeQueue(TreeNode* root){
        if(root == nullptr) return 0;

        int counter = 0;

        queue<TreeNode*> q;
        q.push(root);
        counter++;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return counter;
    }
    //Time complexity = o(n);


    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;

        TreeNode* l = root, *r = root;
        int lHeight, rHeight = 0;

        while(l){
            lHeight++;
            l = l->left;
        }
        while(r){
            rHeight++;
            r = r->right;
        }
        
        //balanced binary tree
        //https://en.wikipedia.org/wiki/Binary_tree#Properties_of_binary_trees
        //perfect binary tree with height h
        if(lHeight == rHeight) return (1 << lHeight) - 1;//balanced tree
        //2^h - 1
        //-1 for 0-indexed

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(){
    Solution s;

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    root->left->left->left = new TreeNode(60);
    root->right->right->right = new TreeNode(70);

    cout << "Height: " << s.countNodes(root);  
}

/*
1 << lHeight

<< is the bitwise operator

1 << 1 = 0010 = 2
1 << 2 = 0100 = 4
1 << 3 = 1000 = 8
*/