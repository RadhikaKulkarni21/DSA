//not operational
#include "lcHeader.h"

/*
We got two sorted linkedlist we combine them by sorting

1->3->4->nullptr
1->2->5->nullptr

we will take a -1 node and point it to list1, we compare each node value
and proceed further
each time the prevNode is pointed to an element in either of the list
we move the prev pointer forward and keep on comparing
*/

class Solution{
    ListNode* mergeTwoSortedList(ListNode* list1, ListNode* list2){
        //create a dummy node
        //since a node, no need of pointer *
        ListNode prevNode(-1);

        //point to the node
        ListNode* prev = &prevNode;
        
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                //we point the next of prev node to l1
                prev->next = list1;
                //update the pointer and move forward in list1
                list1 = list1->next;
            }
            else{
                //we do opposite
                prev->next = list2;

                list2 = list2->next;
            }
            //once the first value is checked and assigned
            //we assign the prev pointer to whatever value of list1/list2
            prev = prev->next;
        }

        //there might be a case where list1 or list2 will be null
        //but there will still be values in other list
        //we need to push those values in LL irrespective
        prev->next = list1 == nullptr ? list1 : list2;

        //we are checking if prev->next which is pointing at list1 is == Null
        //if list1 is null the prev->next will continue with list2
        //if list2 is null the prev->next will continue with list1

        //we need the next node as prev was dummy
        return prevNode.next;
    }
};