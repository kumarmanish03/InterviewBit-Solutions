// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

void sum(TreeNode* A, vector<vector<int>> &res, int s, vector<int> &path, int B){
    if(!A->left && !A->right){
        s += A->val;
        path.push_back(A->val);
        if(s == B)
            res.push_back(path);
        path.pop_back();
        return;
    }

    path.push_back(A->val);
    if(A->left)
        sum(A->left, res, s + A->val, path, B);
    if(A->right)
        sum(A->right, res, s + A->val, path, B); 
    path.pop_back(); 
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> path;
    int s = 0;
    sum(A, res, s, path, B);
    return res;
}
