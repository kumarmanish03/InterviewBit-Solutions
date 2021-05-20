// Manish Kumar, IIIT Allahabad
// Medium, Must try
// Time Complexity : O(logn)
// Space Complexity : O(1)

// https://www.interviewbit.com/problems/search-in-bitonic-array/

// Bionic Array is firstly increases then decreases strictly
// Thinking Process : 
// 1. Try to find the bitonic point
// 2. Then this problem is divided into two problems
// 3. Then find element in first increasing array using binary search
// 4. Then same in second half of the array which is decreasing

int Solution::solve(vector<int> &A, int B) {
    int btn;
    int lo = 0;
    int hi = A.size() - 1;
    
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(A[mid] < A[mid + 1]){
            lo = mid + 1;
        }
        else if(A[mid] > A[mid + 1]){
            hi = mid;
        }
        else if(A[mid-1] < A[mid]){
            lo = mid;
        }
        else if(A[mid-1] > A[mid]){
            hi = mid - 1;
        }
    }
    
    if(A[lo] > A[hi]) btn = lo;
    else btn = hi;
    // Bitonic point index found
    
    lo = 0;
    hi = btn;
    while(hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if(A[mid] < B) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    
    if(A[lo] == B)
        return lo;
    if(A[hi] == B)
        return hi;
    
    lo = btn;
    hi = A.size() - 1;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(A[mid] > B){
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    
    if(A[lo] == B){
        return lo;
    }
    if(A[hi] == B){
        return hi;
    }
    
    return -1;
}
