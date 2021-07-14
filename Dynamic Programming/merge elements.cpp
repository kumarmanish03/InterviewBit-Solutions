// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/old/problems/merge-elements/

int dp[201][201];

int fun(int st, int en, vector<int> &A){
    if(st == en)
        return 0;
    if(st > en)
        return 0;
        
    if(dp[st][en] != -1)
        return dp[st][en];

    int minCost = INT_MAX;
    int sum = 0;
    for(int k = st; k <= en; k++)
        sum += A[k];
    for(int k = st; k < en; k++){
        int left = fun(st, k, A);
        int right = fun(k+1, en, A);
        minCost = min(left+ right + sum, minCost);
    }

    return dp[st][en] = minCost;
}

int Solution::solve(vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    return fun(0, A.size()-1, A);
}
