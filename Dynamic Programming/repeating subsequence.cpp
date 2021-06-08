// Manish Kumar, IIIT Allahabad
// Easy, using LCS

https://www.interviewbit.com/problems/repeating-subsequence/

// This function counts the longest repeating subsequence
// watch video for more explaination
https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=30

// Since in this ques we have to give ans for more or equal to 2 length subsequence
// that's why just samll change in return statement

// Using top down approach
int Solution::anytwo(string A) {
    int n = A.size();
    string B = A;
    int dp[n+1][n+1];
    for(int i = 0; i < n+1; i++)
        dp[0][i] = dp[i][0] = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(A[i-1] == B[j-1] && i!=j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    // Since in this ques we have to give ans for more or equal to 2 length subsequence
    // that's why just samll change in return statement
    return dp[n][n] >= 2 ? 1 : 0;
}
