// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/old/problems/maximum-size-square-sub-matrix/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    // dp[i][j] is the max size submatrix including A[i][j] to leftmost to topmost
    vector<vector<int> > dp(n, vector<int>(m, 0));
    for(int i = 0; i < m; i++)
        dp[0][i] = A[0][i];
    for(int i = 0; i < n; i++)
        dp[i][0] = A[i][0];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(A[i][j] == 1)
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            else
                dp[i][j] = 0;
        }
    }

    int maxSize = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            maxSize = max(maxSize, dp[i][j]);
    }

    return maxSize*maxSize;
}
