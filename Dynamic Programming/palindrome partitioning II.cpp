// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/palindrome-partitioning-ii/

https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=36

// Bottom-Up Approach (Recursion + memorization)

int dp[502][502];

bool isPalin(string s, int i, int j){
    if(i == j) return true;
    if(i > j) return true;
    while(i < j){
        if(s[i] != s[j])
            return false;
        else {
            i++;
            j--;
        }
    }
    return true;
}

int bottomUp(string s, int i, int j){
    if(i > j)
        return 0;
        
    if(isPalin(s, i, j) == true)
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int left, right, mn = INT_MAX;
    for(int k = i; k <= j-1; k++){
      // we also check if dp[i][k] already calculated, (thats why it is optimised)
        if(dp[i][k] != -1)
            left = dp[i][k];
        else
            left = bottomUp(s, i, k);
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else
            right = bottomUp(s, k+1, j);
        
        mn = min(left + right + 1, mn);
    }
    dp[i][j] = mn;
    
    return dp[i][j];
}

int Solution::minCut(string A) {
    memset(dp, -1, sizeof(dp));
    return bottomUp(A, 0, A.size()-1);
}
