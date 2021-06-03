// Manish Kumar, IIIT Allahabad
// Medium, Must try

https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

// Catch:
// Be carefull of passing vector by reference as it cause less memory usage
// If not passing by reference, it makes another copy of itself and hence use large memory

// Strategy:
// This question is similar to Binary Search(recursion)

TreeNode* makeTree(int start, int end, const vector<int> &A){
    if(start > end)
        return NULL;
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(A[mid]);
    if(start == end)
        return root;
    else{
        root->left = makeTree(start, mid-1, A);
        root->right = makeTree(mid+1, end, A);
    }

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode *root = makeTree(0, A.size()-1, A);
    return root;
}
