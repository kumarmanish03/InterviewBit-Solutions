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
