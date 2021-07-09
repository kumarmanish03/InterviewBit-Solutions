// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/least-common-ancestor/

unordered_map<int, pair<int, int>> ancestor; 
 int n1;
 int n2;

void findLevel(TreeNode *A, unordered_map<int, int> &level, int l){
    if(!A)
        return;
    
    level.insert({A->val,l});

    findLevel(A->left, level, l+1);
    findLevel(A->right, level, l+1);
}

void findA(TreeNode *A, int parent){
    if(!A)
        return;

    if(A->val == n1){
        ancestor[parent].first = 1;
    }
    if(A->val == n2){
        ancestor[parent].second = 1;
    }

    if(ancestor[parent].first == 1 && ancestor[parent].second == 1)
        return;

    findA(A->left, parent);
    findA(A->right, parent);
}

void traverse(TreeNode *A){
    if(!A)
        return;

    ancestor[A->val].first = ancestor[A->val].second = -1;
    findA(A, A->val);

    traverse(A->left);
    traverse(A->right);
}

int Solution::lca(TreeNode* A, int B, int C) {
    unordered_map<int, int> level;
    findLevel(A, level, 0);
    ancestor.clear(); 
    n1 = B;
    n2 = C;
    traverse(A);

    int ans = -1;
    int depAns = INT_MIN;
    for(auto i : ancestor){
        if(i.second.first == 1 && i.second.second == 1){
            if(level[i.first] > depAns){
                ans = i.first;
                depAns = level[i.first];
            }
        }
    }
    return ans;
}
