// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int max(int &a, int &b){
    if(a > b)
        return a;
    else
        return b;
}

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> sum(n, 0);
    if(n >= 1)
        sum[0] = max(A[0][0], A[1][0]);
    if(n >= 2)
        sum[1] = max(sum[0], max(A[0][1], A[1][1]));
    for(int i = 2; i < n; i++){
        sum[i] = max(sum[i-1], sum[i-2] + max(A[0][i], A[1][i]));
    }

    return sum[n-1];
}
