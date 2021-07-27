// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    bool isReverse = false;
    queue<TreeNode*> q;
    vector<vector<int> > res;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        vector<int> v;
        while(sz--){
            TreeNode* temp = q.front();
            v.push_back(temp->val);
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(isReverse)
            reverse(v.begin(), v.end());
        res.push_back(v);
        isReverse = !isReverse;
    }

    return res;
}
