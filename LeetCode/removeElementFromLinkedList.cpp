#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        //create a new node with value 0 and head as next node
        ListNode* ans = new ListNode(0, head);
        //set the ans to dummy
        ListNode* dummy = ans;
        
        while(dummy != nullptr){//iterate till there is no next node
            //as long as next exist and value of next exist we skip the 
            //current node and move to next next
            //the outer dummy moves once  
            //inner dummy checks the next to skip or not
            while(dummy->next != nullptr && dummy->next->val == val){
                dummy->next = dummy->next->next;
            }
            //update to move forward
            dummy = dummy->next;
        }
        //we need next as ans is 0/dummy
        ListNode* result = ans->next;
        delete ans;

        return result;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    int val = 6;

    Solution sol;
    sol.removeElements(head, val);
    cout<< head->val;
}