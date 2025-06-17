#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This constructor initializes a new node.          |
        //   | - Sets the 'value' and initializes 'left' and       |
        //   |   'right' pointers to nullptr.                      |
        //   | - Return type: N/A (constructor)                    |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Use 'this->value' to set the value of the node.   |
        //   | - Set 'left' and 'right' pointers to nullptr.       |
        //   | - This constructor is part of the Node class.       |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        Node(int value){
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
        
};

int main(){
    BinarySearchTree* bst = new BinarySearchTree();
    cout<< "Root:" << bst->getRoot()<<endl;
    Node node(10);
    cout << "Node value: " << node.value ;
}
