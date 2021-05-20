// Manish Kumar, IIIT Allahabad
// Medium, Must retry
// Time Complexity : O(logn)
// Space Complexity : O(1)

// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int lo = 0;
    int hi = A.size() - 1;
    vector<int> v(2, -1);
    
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(A[mid] < B){
            lo = mid + 1;
        }else {
            hi = mid;
        }
    }
    
    if(A[lo] == B){
        v[0] = lo;
    }else if(A[hi] == B){
        v[0] = hi;
    }
    
    lo = 0;
    hi = A.size() - 1;
    while(hi - lo > 1){
        int mid = (hi + lo) / 2;
        if(A[mid] <= B){
            lo = mid;
        }else {
            hi = mid - 1;
        }
    }
    
    if(A[hi] == B){
        v[1] = hi;
    }else if(A[lo] == B){
        v[1] = lo;
    }
    
    return v;
}
