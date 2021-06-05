// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/inorder-traversal/
https://www.interviewbit.com/problems/preorder-traversal/
https://www.interviewbit.com/problems/postorder-traversal/

// 1. Inorder

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> v;
    stack<TreeNode*> s;
    while(A){
        s.push(A);
        A = A->left;
    }
    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        v.push_back(temp->val);
        TreeNode* trav = temp->right;
        while(trav){
            s.push(trav);
            trav = trav->left;
        }
    }
    
    return v;
}


// 2. Preorder

// Strategy :
// push root, then
// until stack is empty
// 1. push current to vector
// 2. push its right to stack
// 3. Move to left

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> v;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        while(temp){
            v.push_back(temp->val);
            if(temp->right) s.push(temp->right);
            temp = temp->left;
        }
    }
    
    return v;
}


// 3. PostOrder

// Strategy :
// Preorder is root-left-right. So change preorder code such that it becomes root-right-left
// and then reverse the vector. Hence postorder(left-right-root)

vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        while(temp){
            v.push_back(temp->val);
            if(temp->left) s.push(temp->left);
            temp = temp->right;
        }
    }
    reverse(v.begin(), v.end());
    return v;
}
