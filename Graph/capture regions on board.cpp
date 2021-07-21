// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/old/problems/capture-regions-on-board/

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j, vector<vector<char> > &A){
    if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
        return false;
    return true;
}

void capture(int i, int j, vector<vector<char> > &A){
    if(!isValid(i, j, A))
        return;

    if(A[i][j] == 'X')
        return;

    A[i][j] = 'X';
    for(int k = 0; k < 4; k++){
        capture(i + dx[k], j + dy[k], A);
    }
}

bool isCapture(int i, int j, vector<vector<char> > &A, vector<vector<bool> > &vis){
    if(!isValid(i, j, A))
        return false;

    if(vis[i][j])
        return true;

    if(A[i][j] == 'X')
        return true;

    bool check = true;
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        check &= isCapture(i + dx[k], j + dy[k], A, vis);
    }

    return check;
}

void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'O' && !vis[i][j] && isCapture(i, j, A, vis)){
                capture(i, j, A);
            }
        }
    }
    return;
}
