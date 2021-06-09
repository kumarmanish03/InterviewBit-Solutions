// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/distinct-subsequences/

// Observe conditions carefully

int dp[710][710];

int recur(string A, string B, int n, int m){
  // for m = 0, add 1 to answer i.e, one subsequence detected
    if(m == 0)
        return 1;
    if(n == 0)
        return 0;
        
    if(dp[n][m] != -1)
        return dp[n][m];
        
    if(A[n-1] == B[m-1]){
        dp[n][m] = recur(A, B, n-1, m) + recur(A, B, n-1, m-1);
    }
    else{
        dp[n][m] = recur(A, B, n-1, m); 
    }
    
    return dp[n][m];
}

int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    memset(dp, -1, sizeof(dp));
    return recur(A, B, n, m);
}
