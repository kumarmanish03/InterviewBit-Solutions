// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/maximum-sum-triplet/

// *(--it) < A[i] < nextGreater[i]
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> nextGreater(n, 0); // For storing greater element that A[i]
    for(int i=n-2; i>=0; i--) {
        int mx = max(nextGreater[i+1], A[i+1]);
        if(mx>A[i]) nextGreater[i]=mx;
    }
    int sum = INT_MIN;
    set<int> s;
    s.insert(A[0]);
    for(int i = 1; i < n; i++){
        s.insert(A[i]);
        auto it = s.find(A[i]);
        // Excluding 'it' for first and last element
        if(it!=s.begin() && i != n-1)
        sum = max(sum , A[i] + *(--it) + nextGreater[i]);
        // *(--it) < A[i] < nextGreater[i]

    }

    return sum;
}
