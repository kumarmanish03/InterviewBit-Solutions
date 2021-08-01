// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/old/problems/cousins-in-binary-tree/

vector<int> Solution::solve(TreeNode* A, int B) {
    queue<pair<TreeNode*, int>> q;
    vector<int> ans;
    q.push({A, -1});
    if(A->val == B){
        return ans;
    }

    while(!q.empty()){
        int flag = -1;
        int size = q.size();
        while(size--){
            TreeNode* node = q.front().first;
            q.pop();
            if(node->left){
                q.push({node->left, node->val});
                if(node->left->val == B)
                    flag = node->val;
            }
            if(node->right){
                q.push({node->right, node->val});
                if(node->right->val == B)
                    flag = node->val;
            }
        }
        if(flag != -1){
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                if(u.second != flag)
                    ans.push_back(u.first->val);
            }
            break;
        }
    }
    return ans;
}
