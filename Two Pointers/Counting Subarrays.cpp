// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B) {
    int i = 0;
    int sum = 0;
    int count = 0;
    for(int j = 0; j < A.size(); j++){
        sum += A[j];
        
        while(sum >= B){
                sum -= A[i];
                i++;
        }
        
        count += j - i + 1;
    }
    
    return count;
}
