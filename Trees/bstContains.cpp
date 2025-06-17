#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  This is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode == nullptr) return;
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }

        Node* getRoot() {
            return root;
        } 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This method checks if the tree contains a value.  |
        //   | - Starts at root and goes left or right based on    |
        //   |   value comparison.                                 |
        //   | - Return type: bool                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - If the tree is empty (root == nullptr), return    |
        //   |   false immediately.                                |
        //   | - Traverse down the tree based on value comparison. |
        //   | - If value is found, return true.                   |
        //   | - If reached the end, return false.                 |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        bool contains(int value){
            Node* temp = root;
            while(temp){
                if(value < temp->value){
                    temp = temp->left;
                }
                else if(value > temp->value){
                    temp = temp->right;
                }
                else{
                    return true;
                }
            }
            return false;
        }
};

int main(){
    BinarySearchTree* bst = new BinarySearchTree();
    
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(89);

    cout<<"Contains 27:"<<bst->contains(27)<<endl;
    cout<<"Contains 17:"<<bst->contains(17);

}

/*The member function should perform the following tasks:

Check if the tree is empty:

If the root pointer is nullptr, return false.

Traverse the tree to find the target value:

Create a temporary pointer temp pointing to the root Node of the BST.

Enter a loop that continues until the target value is found or the end of the tree is reached.

If the target value is less than the current Node's value, update the temporary pointer temp to point to the left child Node.

If the target value is greater than the current Node's value, update the temporary pointer temp to point to the right child Node.

If the target value is equal to the current Node's value, return true (the value is present in the tree).

Return false if the target value is not found in the tree.

*/