// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/merge-two-binary-tree/

TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(A && B){
        A->val = A->val + B->val;
        A->left = solve(A->left, B->left);
        A->right = solve(A->right, B->right);
        return A;
    }else if(!A && B){
        A = new TreeNode(B->val);
        A->left = solve(NULL, B->left);
        A->right = solve(NULL, B->right);
        return A;
    }else if(A && !B){
        A->left = solve(A->left, NULL);
        A->right = solve(A->right, NULL);
        return A;
    }
    else{
        return NULL;
    }
}

