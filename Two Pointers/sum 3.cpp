// Manish Kumar, IIIT Allahabad
// Easy, Must try
// Time Complexity : O(nlog(n))
// Space Complexity : O(1)

https://www.interviewbit.com/problems/3-sum/

// In this Question test cases are such that soln is overflowing, Hence use long long 
// Make cases carefully, you may struck if you don't make cases carefully

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    if(A.size() < 3){
        return -1;
    }
    // if(v == A && B == 0){
    //     return 0;
    // }
    
    int sum;
    int minDiff = INT_MAX;
    for(int i = 0; i < A.size() - 2; i++){
        int j = i + 1;
        int k = A.size() - 1;
        
        while(k > j){
            long long newDiff = abs((long long)A[i] + (long long)A[j] + (long long)A[k] - (long long)B);
            if(newDiff <= minDiff){
                minDiff = newDiff;
                sum = A[i] + A[j] + A[k];
                // cout << "a." << sum << " ";
            }
            if((long long)A[i] + (long long)A[j] + (long long)A[k] > B){
                k--;
            }
            else {
                j++;
            }
        }
    }
    
    return sum;
}
