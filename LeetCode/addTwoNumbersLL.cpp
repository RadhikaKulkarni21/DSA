#include "R:\C++\Project1\lcHeader.h"

//max carry will be 1 or 0

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        int carry = 0;//this will store the carry over
        ListNode* current = dummyNode;//current iterationn at head

        //using while instead for traversing 
        while(l1 != NULL || l2 != NULL|| carry != 0){
            //for l1 and l2, either the node will have value or null = 0 
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;//carry if any

            carry = sum / 10;//giving the carry if any
            //this is to create a new  node 
            current->next = new ListNode(sum % 10);
            current = current->next;

            l1 = l1 ? l1->next:nullptr;
            l2 = l2 ? l2->next:nullptr;
        }
        return dummyNode->next;
    }
};

int main(){
    Solution newSolution;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    newSolution.addTwoNumbers(l1,l2);
}


/*
Initialize current node to dummy head of the returning list.
Initialize carry to 0.
Loop through lists l1 and l2 until you reach both ends and carry is 0.
Set x to node l1's value. If l1 has reached the end of l1, set to 0.
Set y to node l2's value. If l2 has reached the end of l2, set to 0.
Set sum=x+y+carry.
Update carry=sum/10.
Create a new node with the digit value of (summod10) and 
set it to current node's next, then advance current node to next.
Advance both l1 and l2.
Return dummy head's next node.


l1 = 2  4  3
l2 = 5  6  4

first iteration:
x = 2 y = 5 carry = 0 
curr.next 7 % 10
sum = x + y + carry

dummy = 0 7 _ _

second iteration:
x = 4 y = 6 prev carry = 0 
carry = 10/10 = 1
curr.next = 10 % 10 = 0
sum = x + y + carry

dummy = 0 7 0 _
carry = 1

third iteration:
x = 3 y = 4 prev carry = 1 
carry = 0/10 = 1

sum = x + y + carry = 3 + 4 + 1 = 8
curr.next = 8 % 10 = 8

dummy = 0 7 0 8
carry = 0
*/