// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

// Strategy:
// If you notice carefully in the flattened tree, each node’s right child points to the next node of a pre-order traversal.
// Now, if a node does not have left node, then our problem reduces to solving it for the node->right.
// If it does, then the next element in the preorder traversal is the immediate left child. But if we make the immediate left child as the right child of the node, then the right subtree will be lost.
// So we figure out the rightmost element in the left subtree, and attach the right subtree as its right child. We make the left child as the right child now and move on to the next node.

void flat(TreeNode* A){
    if(!A)
        return;
        
    if(!A->left)
        flat(A->right);
    else{
        flat(A->left);
        TreeNode* temp = A->right;
        A->right = A->left;
        A->left = NULL;
        TreeNode *trav = A->right;
        while(trav->right) trav = trav->right;
        trav->right = temp;
        flat(trav->right);
    }
}

TreeNode* Solution::flatten(TreeNode* A) {
    flat(A);
    return A;
}
