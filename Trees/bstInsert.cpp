#include "R:\C++\Project1\lcHeader.h"

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
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
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

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This method inserts a new value into the tree.    |
        //   | - A new node is created for the value.              |
        //   | - Starts at root and finds the correct location.    |
        //   | - Return type: bool                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - If the tree is empty (root == nullptr), set root  |
        //   |   to the new node and return true.                  |
        //   | - Use a while loop to find the correct location.    |
        //   | - If the value already exists, return false.        |
        //   | - Insert the new node at the correct position.      |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        bool insert(int value){
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true){
                if(newNode == temp)return false;
                if(newNode->value < temp->value){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }
                else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
};


int main(){
    BinarySearchTree tree;
        tree.insert(10);
        tree.insert(5);
        cout << "Root value: " << tree.getRoot()->value<<endl;
        cout << "Left child value: " << tree.getRoot()->left->value;
}

/*The member function should perform the following tasks:

Create a new Node with the provided value:

Allocate memory for a new Node object, passing the value to its constructor.

Check if the tree is empty:

If the root pointer is nullptr, set the root pointer to the new Node and return true.

Traverse the tree to find the appropriate position for the new Node:

Create a temporary pointer temp pointing to the root Node of the BST.

Enter a loop that continues until a suitable position for the new Node is found or the value is found to be already present in the tree.

If the new Node's value is equal to the current Node's value, exit the loop and return false (duplicate values are not allowed).

If the new Node's value is less than the current Node's value:

If the current Node's left child pointer is nullptr, set the left child pointer to the new Node and return true.

Otherwise, update the temporary pointer temp to point to the left child Node.

If the new Node's value is greater than the current Node's value:

If the current Node's right child pointer is nullptr, set the right child pointer to the new Node and return true.

Otherwise, update the temporary pointer temp to point to the right child Node.
*/