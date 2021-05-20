// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(logn)
// Space Complexity : O(1)

// https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B) {
    int lo = 0;
    int hi = A.size() - 1;
    int ans;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(A[mid] < B){
            lo = mid + 1;
        }else {
            hi = mid;
        }
    }
    
    if(A[lo] >= B){     // First check low 
        ans = lo;    
    }else if(A[hi] >= B){
        ans = hi;
    }else {
        ans = hi + 1;   // When B is greater than last elemnent of array
    }
    
    return ans;
    
}
