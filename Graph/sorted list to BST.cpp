// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

// slow and fast pointer technique

ListNode* getMid(ListNode* &head){
    ListNode *slow = head, *fast = head, *pre = nullptr;

    while(fast and fast->next){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // separate list from mid
    if(pre)
        pre->next = nullptr;

    // this slow ptr points to mid element of the list
    return slow;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(!A)
        return nullptr;
    
    ListNode* mid = getMid(A);
    TreeNode* root = new TreeNode(mid->val);
    // when only one node
    if(mid == A)
        return root;
    root->left = sortedListToBST(A);
    root->right = sortedListToBST(mid->next);

    return root;
}



// Using vectors

void fun(int lo, int hi, vector<int> &v){
    if(lo > hi)
        return NULL;
    
    int mid = (lo + hi) / 2;
    TreeNode* node = new TreeNode(v[mid]);
    node->left = fun(lo, mid-1, v);
    node->right = fun(mid+1, hi, v);
    
    return node;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> v;
    while(A){
        v.push_back(A->val);
        A = A->next;
    }
    return fun(0, v.size()-1, v);
}
