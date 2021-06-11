https://www.interviewbit.com/problems/maximum-path-in-triangle/

// In triangle we have to add prefix from bottom right to top left
// Becoz' adjacent elements A[i][j] are A[i+1][j] & A[i+1][j+1]

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    for(int i = n-2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            A[i][j] += max(A[i+1][j+1], A[i+1][j]);
        }
    }
    
    return A[0][0];
}
