// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/chain-of-pairs/

// Similar as Longest Increasing Subsequence (only minor change in if statement)
// inc[i] denotes the length of longest subsequence end on index i

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int inc[n];
    
    for(int i = 0; i < n; i++){
        inc[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i][0] > A[j][1])
                inc[i] = max(inc[i], inc[j] + 1);
        }
    }
    
    return *max_element(inc, inc + n);
}
