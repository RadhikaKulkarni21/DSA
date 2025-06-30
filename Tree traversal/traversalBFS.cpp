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
        
        void bfs(){
            queue<Node*> newQueue;
            newQueue.push(root);

            while(newQueue.size() > 0){
                Node* currentNode = newQueue.front();//whichever is at the front of the queue ie root
                newQueue.pop();
                cout<<currentNode->value<<" ";
                if(currentNode->left){
                    newQueue.push(currentNode->left);
                }
                if(currentNode->right){
                    newQueue.push(currentNode->right);
                }
            }
        }
};

int main(){

}