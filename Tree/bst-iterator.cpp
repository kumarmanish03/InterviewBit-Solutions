// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/bst-iterator/


// Solution 1

vector<int> minm;
int point = 0;

// this function saves minimum values in minm vector
void getMin(TreeNode *root){
    if(!root)
        return;
    getMin(root->left);
    minm.push_back(root->val);
    getMin(root->right);
}

BSTIterator::BSTIterator(TreeNode *root) {
    getMin(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return point < minm.size();
}

/** @return the next smallest number */
int BSTIterator::next() {
    return minm[point++];    
}



// Solution 2
// Efficient Solution 

stack<TreeNode*> s;
// this function saves minimum values in minm vector
void getMin(TreeNode* root){
    while(root!=NULL){
        s.push(root);
        root->left;
    }
}


BSTIterator::BSTIterator(TreeNode *root) {
    getMin(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* temp = s.top();
    s.pop();
    getMin(temp->right);
    return temp->val;
}
