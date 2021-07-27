// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/old/problems/sum-root-to-leaf-numbers/

int m = 1003;

void getSum(TreeNode* A, int n, int &sum){
    if(!A->left && !A->right){
        n = n*10 + A->val;
        sum = (sum % m + n % m) % m;
        return;
    }

    if(A->left)
        getSum(A->left, (n*10 + A->val) % m, sum);
    if(A->right)
        getSum(A->right, (n*10 + A->val) % m, sum);
}

int Solution::sumNumbers(TreeNode* A) 
 {
    int sum = 0;
    getSum(A, 0, sum);

    return sum % m;
}