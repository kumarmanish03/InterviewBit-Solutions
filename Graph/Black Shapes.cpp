// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/black-shapes/

// Strategy:
// If 'X' found then dfs() makes all adjacent 'X' to 'O'. And result is just count of 'X' found

void dfs(int i, int j, vector<string> &A){
    int n = A.size();
    int m = A[0].size();
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
        
    if(A[i][j] == 'O')
        return;
 
    A[i][j] = 'O';
    
    dfs(i-1, j, A);
    dfs(i+1, j, A);
    dfs(i, j-1, A);
    dfs(i, j+1, A);
}

int Solution::black(vector<string> &A) {
    int count = 0;
    n = A.size();
    m = A[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'X'){
                dfs(i, j, A);
                count++;
            }
        }
    }
    return count;
}
