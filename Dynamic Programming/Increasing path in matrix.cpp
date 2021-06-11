// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/increasing-path-in-matrix/

// Strategy :
// There is only one possible answer n+m-1(as we have only two ways go right or go down) else -1

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    dp[0][0] = 1;
    for(int i = 1; i < m; i++){
        if(A[0][i] > A[0][i-1])
            dp[0][i] = dp[0][i-1] + 1;
        else
            dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++){
        if(A[i][0] > A[i-1][0])
            dp[i][0] = dp[i-1][0] + 1;
        else
            dp[i][0] = 1;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(A[i][j] > A[i-1][j] || A[i][j] > A[i][j-1])
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            else
                return -1; // Becoz if above if condn not satisfy then it is not possible to move forward in any dirn
        }
    }

    return (dp[n-1][m-1] == n+m-1) ? n+m-1 : -1;
}
