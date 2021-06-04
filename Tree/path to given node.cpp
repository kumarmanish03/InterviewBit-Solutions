// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/remove-half-nodes/

// First try yourself

TreeNode* removeHalf(TreeNode *A){
    if(!A)
        return A;

    A->left = removeHalf(A->left);
    A->right = removeHalf(A->right);
    
    if(A->left && !A->right){
        return A->left;
    }
    if(!A->left && A->right){
        return A->right;
    }
    
    return A;
}

TreeNode* Solution::solve(TreeNode* A) {
    TreeNode *temp = removeHalf(A);
    return temp;
}