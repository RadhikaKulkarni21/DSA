using namespace std;
#include <iostream>
#include <queue>
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
        
        //this may or maynot be for testing
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
    
        void DFSPreOrder(Node* currentNode){
            cout<<currentNode->value<<" ";
            if(currentNode->left){
                DFSPreOrder(currentNode->left);
            }
            if(currentNode->right){
                DFSPreOrder(currentNode->right);
            }
        }

        void DFSPreOrder(){ DFSPreOrder(root); }
};

int main(){
    BinarySearchTree* newBFS = new BinarySearchTree();  
    newBFS->insert(47);
    newBFS->insert(21);
    newBFS->insert(76);
    newBFS->insert(18);
    newBFS->insert(27);
    newBFS->insert(52);
    newBFS->insert(82);

    //we are overloading the original one with value passed as root is private
    newBFS->DFSPreOrder();    
}