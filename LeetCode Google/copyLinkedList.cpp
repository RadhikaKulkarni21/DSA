/*Basically the question is to deep copy the linked list, 
that is make an exact copy.(replicate the random nodes too)
If it was simple single linked list, it was simple.
Just make a copy on the go and connect the nodes.
But if the random element is present we have to replicate it to, 
just imagine you made a new node and the random of this node points
 to a node which is not yet created ?What will you do? 
 How will you Point to that node, thats what we have to solve here*/
 #include "lcHeader.h"

class Solution{
    public:
    unordered_map<Node*, Node*> visited;
    //Iterative
    Node* getClonedNodeI(Node* node){
        if(node){
            if(visited.find(node) != visited.end()){
                return visited[node];
            }
            else{
                visited[node] = new Node(node->val);
                return visited[node];
            }
        }
        return NULL;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        this->visited[oldNode] = newNode;

        while(oldNode != NULL){
            newNode->random = this->getClonedNodeI(oldNode->random);
            newNode->next = this->getClonedNodeI(oldNode->next);

            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return this->visited[head];
    }

//Recursive
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        if(this->visited.find(head) != this->visited.end()){
            //already visited and in the hash unordered_map
            //if we are already at the end that means this value is added
            //nothing is left to traverse
            return this->visited[head];
        }

        Node* node = new Node(head->val);

        //this is our copied list
        this->visited[head] = node;
        // Get the clones of the nodes referenced by random and next
        // pointers.
        node->next = this->copyRandomList(head->next);
        node->random = this->copyRandomList(head->random);
        return node;
    }
};


