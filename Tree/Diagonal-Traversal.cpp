// Manish Kumar, IIIT Allahabad
// Medium

// https://interviewbit.com/problems/diagonal-traversal/

vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    vector<int> res;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        while(temp){
            if(temp->left)
                q.push(temp->left);
            res.push_back(temp->val);
            temp = temp->right;
        }
    }
    return res;
}
