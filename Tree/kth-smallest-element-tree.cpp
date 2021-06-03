// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

// Read soln approach InterviewBit

bool kSmall(TreeNode *A, int &res, int &B){
    if(!A)
        return false;
        
    if(kSmall(A->left, res, B)){
        return true;
    }
    if(--B == 0){
        res = A->val;
        return true;
    }
    if(kSmall(A->right, res, B)){
        return true;
    }
    
    return false;
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    int res;
    kSmall(A, res, B);
    return res;
}