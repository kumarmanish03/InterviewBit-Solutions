// Manish Kumar, IIIT Allahabad
// Easy, Standard

https://www.interviewbit.com/problems/0-1-knapsack/

// SPACE OPTIMIZED SOLUTION of Knapsack Problem

// Refer Video : https://www.youtube.com/watch?v=7C_FIc7PytA

// space optimized soln of dp soln having need only of onlu previous row in recurrence relation

// Just change dp[i][j] to dp[i%2][j], dp[i-1][j] to dp[(i+1)%2][j], dp[n][C] to dp[n%2][C]
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    int dp[2][C+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < C+1; j++){
            if(B[i-1] <= j){
                dp[i%2][j] = max(dp[(i+1)%2][j], A[i-1] + dp[(i+1)%2][j - B[i-1]]);
            }
            else{
                dp[i%2][j] = dp[(i+1)%2][j];
            }
        }
    }

    return dp[n%2][C];
}

// recur() is using Memorization(recursion)

int dp[1001][1001];

int recur(vector<int> &A, vector<int> &B, int n, int wt){
    if(n == 0 || wt == 0){
        return 0;
    }
    
    if(dp[n][wt] != -1)
        return dp[n][wt];
    
    if(B[n-1] <= wt){
        dp[n][wt] = max(A[n-1] + recur(A, B, n-1, wt-B[n-1]), recur(A, B, n-1, wt));
    }
    else{
        dp[n][wt] = recur(A, B, n-1, wt);
    }
    
    return dp[n][wt];
}



// topDown() is topDown/bottomup Approach(itrative)

int topDown(vector<int> &A, vector<int> &B, int n, int wt){
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < wt+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
                
            else if(B[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], A[i-1] + dp[i-1][j-B[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][wt];
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    memset(dp, -1, sizeof(dp));
    int ans = topDown(A, B, n, C);
    return ans;
}


