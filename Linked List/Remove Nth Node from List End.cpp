// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

int length(ListNode* A){
    int l = 0;
    while(A){
        A = A->next;
        l++;
    }
    return l;
}

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int len = length(A);
    int k = len - B;
    if(len == 0) return NULL;
    if(k < 0)
        k = 0;
    
    ListNode *pre = NULL, *head = A, *ans;
    if(k == 0) return A->next;
    ans = A;
    while(k--){
        pre = head;
        head = head->next;
    }
    pre->next = head->next;
    return A;
}
