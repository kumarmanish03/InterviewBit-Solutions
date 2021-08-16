// Manish Kumar, IIIT Allahabad
// Hard
// TC: O(B * N)

https://www.interviewbit.com/old/problems/best-time-to-buy-and-sell-stock-atmost-b-times/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(n == 0 || n == 1) return 1;
    if(2 * B > n){
        B = n;
    }
    
    int dp[B+1][A.size()];

    for(int i = 0; i < B+1; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < A.size(); i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i < B+1; i++){
        int prevDiff = INT_MIN;
        for(int j = 1; j < A.size(); j++){
            prevDiff = max(prevDiff, dp[i-1][j-1] - A[j-1]);
            dp[i][j] = max(dp[i][j-1], prevDiff + A[j]);
        }
    }

    return dp[B][A.size()-1];
}