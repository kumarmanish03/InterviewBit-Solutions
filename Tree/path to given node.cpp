// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/path-to-given-node/

// Try to rewrite first the soln again

bool path(TreeNode *A, vector<int> &v, int B){
    if(!A){
        return false;
    }

    if(A->val == B){
        v.push_back(A->val);
        return true;
    }
    
    bool ans1 = path(A->left, v, B);
    bool ans2 = path(A->right, v, B);
    
    if(ans1 || ans2){
        v.push_back(A->val);
        return true;
    }
    
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    path(A, v, B);
    reverse(v.begin(), v.end());
    return v;
}
