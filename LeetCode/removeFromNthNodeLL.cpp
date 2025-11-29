//no main class - focus on algorihtm and concept
#include "R:\C++\Project1\lcHeader.h"

ListNode* removeNthFromEnd(ListNode* head, int n) { 
    //create a dummy node to assign before the head
    ListNode dummy(0);
    dummy.next = head;

    //we take two pointers
    ListNode* first = &dummy;
    ListNode* second = &dummy;

    //for loop to initiate and move the first poniter
    //the first pointer will exactly be at n steps away from 2nd pointer
    for(int i = 0;i <= n + 1;i++){
        first= first->next;
    }

    //we have distanced the first pointer
    //now we itertate till first hits null
    //so the element between second and first is to be removed
    while(first != NULL){
        first = first->next;
        second = second->next;
    }

    //we assign the next of 'current' to 'next' of 'next'
    second->next = second->next->next;
    return dummy.next;
}

int main(){
    ListNode nodeOne(1);
}

/*Instead of one pointer, we could use two pointers. 
The first pointer advances the list by n+1 steps from the beginning, 
while the second pointer starts from the beginning of the list. 
Now, both pointers are exactly separated by n nodes apart. 
We maintain this constant gap by advancing both pointers together 
until the first pointer arrives past the last node. 
The second pointer will be pointing at the nth node counting from the last.
We relink the next pointer of the node referenced by the second pointer 
to point to the node's next next node.*/