// Manish Kumar, IIIT Allahabad
// Medium, Important
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/maximum-ones-after-modification/

// Try to implement this once more

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int zero = 0;
    int maxone = 1;
    if(!A[0]) zero++;
    for(int i = 1; i < n; i++){
        if(!A[i]) zero++;
    }
    
    if(zero <= B) return n;
    
    int k = B;
    int i = 0;
    int j = 0;
    int curr = 0;
    int maxm = INT_MIN;
    while(1) {
        if(A[j] == 0){
            k--;
            curr++;
            j++;
        }
        else if(A[j] == 1){
            j++;
            curr++;
        }
        
        if(k == 0){
            maxm = max(curr, maxm);
        }
    }
}
