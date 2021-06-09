
// For Explaination of how to calculate longest increasing subsequence
// read CC handbook pg 80

// inc[i] stores longest increasing subsequence till index i
// dec[i] stores longest decreasing subsequence from index i to n
// Do notive the changes in dec iteration

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    
    if(n == 0)
        return 0;
    
    int dec[n];
    int inc[n];
    
    for(int i = 0; i < n; i++){
        inc[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[j] < A[i])
                inc[i] = max(inc[i], inc[j]+1);
        }
    }
    
    for(int i = n-1; i >= 0; i--){
        dec[i] = 1;
        for(int j = n-1; j >= i; j--){
            if(A[j] < A[i])
                dec[i] = max(dec[i], dec[j]+1);
        }
    }
    
    int largest = INT_MIN;
    for(int i = 0; i < n; i++){
        largest = max(largest, inc[i]+dec[i]-1);
    }
    
    return largest;
}
