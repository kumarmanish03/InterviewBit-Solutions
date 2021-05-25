// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

// Initially LL is : 1 -> 2 -> 3 -> 4 -> 5
 // prev->val = 1, temp->val = 1;
 // After First Iteration:
 // LL is : 2 -> 1 -> 3 -> 4 -> 5
 // prev->val = 1, temp->val = 3 
 
 
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *temp = A;
    bool first = true;
    ListNode *prev = A;
    while(temp && temp->next){
        ListNode *t = temp->next;
        temp->next = temp->next->next;
        t->next = temp;
        if(first){
            A = t;
            first = false;
        }
        else{
            prev->next = t;
        }
        prev = t->next;
        temp = temp->next;
    }
    //delete temp;
    
    return A;
}
