// Manish Kumar, IIIT Allahabad
// Medium, DP on Trees

https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
https://www.youtube.com/watch?v=Osz-Vwer6rw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=49


 int sum(TreeNode* A, int& res){
    // Base condn :-
    if(A == NULL)
        return 0;

    // Hypothesis :-
    int l = sum(A->left, res);
    int r = sum(A->right, res);
    
    // Induction :-
    // temp chooses maximum from this two, becoz it may happen that 
    //left/right produces negative, then its better to ignore left/right 
    //and just pass its value only as we can choose max sum from any node
    // (Notice the difference of code when max path sum asked to leaf to leaf node only, not from any node to any node)
    int temp = max(max(l, r) + A->val, A->val);
    //int temp2 = max(A->val, max(A->val + r, A->val + l));
    int ans = max(temp, A->val + l + r);
    res = max(res, ans);
    
    return temp;
 }
 
int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    sum(A, res);
    return res;
}