// Manish Kumar, IIIT Allahabad
// Medium, MCM varient

https://www.interviewbit.com/problems/evaluate-expression-to-true/

// dp[i][j][true] gives the count of solving expression from i to j index which gives true result
// dp[i][j][false] gives the count of solving expression from i to j index which gives false result


int dp[151][151][2];

int count(string A, int i, int j, bool cond){
    if(i > j)
        return 0;
    if(i == j){
        if(cond == true)
            if(A[i] == 'T') return 1;
            else return 0;
        else if(cond == false)
            if(A[i] == 'F') return 1;
            else return 0;
    }
    
    if(dp[i][j][cond] != -1)
        return dp[i][j][cond];
    
    int currCount = 0;
    for(int k = i+1; k < j; k+=2){
        int lt = count(A, i, k-1, true);
        int lf = count(A, i, k-1, false);
        int rt = count(A, k+1, j, true);
        int rf = count(A, k+1, j, false);
        if(cond == true){
            if(A[k] == '|')
                currCount += lt*rt + lf*rt + lt*rf;
            else if(A[k] == '&')
                currCount += lt*rt;
            else if(A[k] == '^')
                currCount += lt*rf + lf*rt;
        }
        
        else if(cond == false){
            if(A[k] == '|')
                currCount += lf*rf;
            else if(A[k] == '&')
                currCount += lt*rf + lf*rt + lf*rf;
            else if(A[k] == '^')
                currCount += lf*rf + lt*rt;
        }
    }
    
    return dp[i][j][cond] = currCount % 1003;
}


int Solution::cnttrue(string A) {
    memset(dp, -1, sizeof(dp));
    return count(A, 0, A.size()-1, true);
}
