// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

// See below Algo, can be useful in many questions

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *slow = A, *fast = A;

    while(fast){
        if(slow->val != fast->val){
            slow = slow -> next;
            slow->val = fast->val;
        }
        fast = fast->next;
    }
    slow->next = NULL;
    delete(slow->next);
    return A;
}
