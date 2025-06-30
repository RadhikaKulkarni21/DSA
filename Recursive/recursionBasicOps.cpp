#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree() { root = nullptr; }

    void destroy(Node *currentNode)
    {
        if (currentNode == nullptr)
            return;
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    Node *getRoot() {return root;}

    Node* rInsert(Node* currentNode, int value){
        if(currentNode == nullptr) return new Node(value);

        if(value < currentNode->value){
            currentNode->left = rInsert(currentNode->left, value);
        }
        
        else if(value > currentNode->value){
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }

    void rInsert(int value){
        //to cover edge case where tree is empty
        if(root == nullptr)  root = new Node(value);
        rInsert(root, value);
    }

    // this is just to find the value
    bool rContains(Node *currentNode, int value){
        if (currentNode == nullptr)
            return false;

        if (currentNode->value == value)
            return true;

        // This will always be less than because the value has to be less than the top
        if (value < currentNode->value)
        {
            return rContains(currentNode->left, value);
        }
        else{
            return rContains(currentNode->right,value);
        }
    }

    // func overloading
    // return actual true/false from the above func
    bool rContains(int value){
        return rContains(root, value);
    }

    int minValue(Node* currentNode){
        while(currentNode->left != nullptr){
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }

    Node* deleteNode(Node* currentNode, int value){
        if(currentNode == nullptr) return nullptr;
        //traversing left and right till we find the value we are looking for
        if(value < currentNode->value){
            currentNode->left = deleteNode(currentNode->left, value);
        }

        else if(value > currentNode->value){
            currentNode->right = deleteNode(currentNode->right, value);
        }

        else{
            //open on the left and right
            if(currentNode->left == nullptr && currentNode->right == nullptr){
                delete (currentNode);
                return nullptr;
            }
            //open on the left and have a node on the right
            else if(currentNode->left == nullptr){
                Node* temp = currentNode->right;
                delete(currentNode);
                return temp;
            }
            //open on the right and have a node on the left
            else if(currentNode->right == nullptr){
                Node* temp = currentNode->left;
                delete(currentNode);
                return temp;
            }
            //have node on both left and right
            else{
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }

        return currentNode;
    }

    void deleteNode(int value){
        root = deleteNode(root, value);
    }
};

int main(){
    BinarySearchTree* newBst = new BinarySearchTree();

    // newBst->rInsert(47);
    // newBst->rInsert(21);
    // newBst->rInsert(76);
    // newBst->rInsert(18);
    // newBst->rInsert(27);
    // newBst->rInsert(52);
    // newBst->rInsert(58);

    newBst->rInsert(2);
    newBst->rInsert(1);
    newBst->rInsert(3);

    //cout<<newBst->rContains(27)<<endl;
    //cout<<newBst->rContains(17)<<endl;
    cout<<"Before:\n";
    cout<< "Root:"<<newBst->getRoot()->value<<endl; 
    cout<< "Root->left:"<<newBst->getRoot()->left->value<<endl;
    cout<< "Root->right:"<<newBst->getRoot()->right->value<<endl;

    newBst->deleteNode(2);

    cout<<"After:\n";
    cout<< "Root:"<<newBst->getRoot()->value<<endl; 
    cout<< "Root->left:"<<newBst->getRoot()->left->value<<endl;
    cout<< "Root->right:"<<newBst->getRoot()->right<<endl;

    // cout<<newBst->minValue(newBst->root)<<endl;
    // cout<<newBst->minValue(newBst->root->right);
}
