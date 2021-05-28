// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(nlogn) [worst case]
// Space Complexity : O(n)

https://www.interviewbit.com/problems/k-largest-elements/

// You need not to sort the whole array
// Just use priority_queue and sttore all elements
// elements are arranged in decreasing order, hence extract top B elements

// If we want to create a priority queue that supports finding and removing the
// smallest element, we can do it as follows:
// priority_queue<int,vector<int>,greater<int>> q;

// In this, Insertion and removal take O(logn) time, and retrieval takes O(1) time.

vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> q;
    for(int i = 0; i < A.size(); i++){
        q.push(A[i]);
    }
    
    vector<int> v;
    while(B--){
        v.push_back(q.top());
        q.pop();
    }
    return v;
}
