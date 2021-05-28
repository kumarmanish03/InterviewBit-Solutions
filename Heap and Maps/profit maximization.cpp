// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(nlogn) [worst case]
// Space Complexity : O(n)

https://www.interviewbit.com/problems/profit-maximisation/

// Recall the working of priority_queue
// Remember in priority queue insertion and deletion takes logn time

int Solution::solve(vector<int> &A, int B) {
    priority_queue<long long> q;
    for(int i = 0; i < A.size(); i++){
        q.push(A[i]);
    }
    long long sum = 0;
    while(B--){
        long long t = q.top();
        sum += t;
        q.pop();
        q.push(t-1);
    }
    
    return sum;
}
