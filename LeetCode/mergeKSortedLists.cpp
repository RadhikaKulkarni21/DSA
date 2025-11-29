//not functioning
#include "R:\C++\Project1\lcHeader.h"

    
ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == nullptr) return  list2;
        if(list2 == nullptr) return list1;

        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2);
            return list2;
    }
}

//TODO: add main function