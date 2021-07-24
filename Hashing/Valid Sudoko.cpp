// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/valid-sudoku/

bool col[9][10];
bool row[9][10];
bool box[3][3][10];

int Solution::isValidSudoku(const vector<string> &A) {
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    memset(box, 0, sizeof(box));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(A[i][j] != '.'){
                int k = A[i][j] - '0';
                if(col[j][k] || row[i][k] || box[i/3][j/3][k])
                    return 0;
                else
                    col[j][k] = row[i][k] = box[i/3][j/3][k] = true;
            }
        }
    }
    return 1;
}
