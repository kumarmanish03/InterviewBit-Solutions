// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

ListNode* Solution::solve(ListNode* A) {
    
    ListNode *temp = A, *c = A;

    temp = A;
    while(temp){
        if(temp->val == 0){
            int data = c->val;
            c->val = temp->val;
            temp->val = data;
            c = c->next;
        }
        temp = temp->next;
    }
    delete temp;
    
    return A;
}
