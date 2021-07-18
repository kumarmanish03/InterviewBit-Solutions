// Manish Kumar, IIIT Allahabad
// Medium

// Simple DFS

https://www.interviewbit.com/old/problems/word-search-board/

bool dfs(int i, int j, int k, vector<string> &A, string &B){
    int n = A.size();
    int m = A[0].size();
    
    if(k == B.size())
        return true;
    if(i < 0 || i >= n || j < 0 || j >= m || A[i][j] != B[k])
        return false;
 
    if(dfs(i+1, j, k+1, A, B) || dfs(i-1, j, k+1, A, B) || dfs(i, j-1, k+1, A, B) || dfs(i, j+1, k+1, A, B)){
        return true;
    }
    return false;
}
 
int Solution::exist(vector<string> &A, string B) {
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            if(A[i][j] == B[0] && dfs(i, j, 0, A, B)){
                return true;
            }
        }
    }
    return false;
}
