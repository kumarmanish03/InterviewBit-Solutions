// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/region-in-binarymatrix/


int dfs(int i, int j, vector<vector<int> > &A){
    if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] == 0)
        return 0;
    
    int count = 1;
    A[i][j] = 0;     // Mark visited
    count += dfs(i-1, j, A);
    count += dfs(i+1, j, A);
    count += dfs(i-1, j-1, A);
    count += dfs(i+1, j+1, A);
    count += dfs(i, j-1, A);
    count += dfs(i, j+1, A);
    count += dfs(i-1, j+1, A);
    count += dfs(i+1, j-1, A);
    
    return count;
}

int Solution::solve(vector<vector<int> > &A) {
    int mx = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] == 1){
                int count = dfs(i, j, A);
                mx = max(mx, count);
            }
        }
    }
    return mx;
}
