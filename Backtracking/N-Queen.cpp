// Manish Kumar, IIIT Allahabad
// Medium, Standard

https://www.interviewbit.com/problems/nqueens/

// A famous standard Question
// Full explaination given in CC Handbook(pg. 60)

int column[20] = {0};
int diag1[40] = {0};
int diag2[40] = {0};

void nQueen(int A, vector<string> temp, int j, vector<vector<string> > &v){
    if(j == A){
        v.push_back(temp);
        return;
    }
    
    for(int i = 0; i < A; i++){
        if(column[i] || diag1[i+j] || diag2[i-j+A-1])
            continue;
        column[i] = diag1[i+j] = diag2[i-j+A-1] = 1;
        temp[j][i] = 'Q';
        nQueen(A, temp, j+1, v);
        temp[j][i] = '.';
        column[i] = diag1[i+j] = diag2[i-j+A-1] = 0;
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> > v;
    string t1(A, '.');
    vector<string> temp(A, t1);
    nQueen(A, temp, 0, v);
    // Reinitializing all global variables so that no overlapping on multiple test cases 
    column[20] = {0};
    diag1[40] = {0};
    diag2[40] = {0};
    return v;
}
