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
};

int main(){
    BinarySearchTree* newBst = new BinarySearchTree();

    newBst->insert(47);
    newBst->insert(21);
    newBst->insert(76);
    newBst->insert(18);
    newBst->insert(27);
    newBst->insert(52);
    newBst->insert(58);

    cout<<newBst->rContains(27)<<endl;
    cout<<newBst->rContains(17)<<endl;
}
