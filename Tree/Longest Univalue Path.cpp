// 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    
    int fun(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int left = fun(root->left);
        int right = fun(root->right);
        
        int temp = 1;
        if(root->left && root->val == root->left->val && root->right && root->val == root->right->val){
            ans = max(ans, left + right + 1);
            return max(left, right) + 1;
        }
        else if(root->right && root->val == root->right->val){
            ans = max(ans, right+1);
            return right + 1;
        }
        else if(root->left && root->val == root->left->val){
            ans = max(ans, left+1);
            return left+1;
        }
        else{
            ans = max(ans, 1);
            return 1;
        }
    }
    
    
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        fun(root);
        return ans == 0 ? 0 : ans-1;
    }
};