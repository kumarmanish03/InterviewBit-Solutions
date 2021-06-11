// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/paint-house/

// ==========

// Bottom UP (memoization + Recursion)

vector<vector<int> > cost; 
int dp[100001][3];
int minCost(int n, int c){
    if(n == 0)
        return 0;
        
    if(dp[n][c] != -1)
        return dp[n][c];
    
    int mn = INT_MAX;
    for(int i = 0; i < 3; i++){
        if(i != c){
            mn = min(minCost(n-1, i) + cost[n-1][i], mn);
        }
    }
    dp[n][c] = mn;

    return mn;
}

int Solution::solve(vector<vector<int> > &A) {
    memset(dp, -1, sizeof(dp));
    cost.clear();
    cost = A;
    int n = A.size();
    int mn = INT_MAX;
    for(int i = 0; i < 3; i++){
        mn = min(minCost(n-1, i) + cost[n-1][i], mn);
    }
    
    return mn;
}


// =============

// Top Down (Itrative)

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int dp[n+1][3];
    int i,j;
    for(i=0;i<=2;i++)
    dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=A[i-1][0]+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=A[i-1][1]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=A[i-1][2]+min(dp[i-1][0],dp[i-1][1]);
    }
    
    return min(dp[n][0],min(dp[n][1],dp[n][2]));
}