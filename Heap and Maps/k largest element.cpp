// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(nlogk) [worst case]
// Space Complexity : O(n)

https://www.interviewbit.com/problems/k-largest-elements/

// You need not to sort the whole array

// TC: nlogk becoz, n for traversing whole array and for each iteration logk for insertion

vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> q;
    for(int i = 0; i < A.size(); i++){
        q.push(A[i]);
        if(q.size() > B)
            q.pop();
    }
    
    vector<int> v(B);
    while(B--){
        v.push_back(q.top());
        q.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}
