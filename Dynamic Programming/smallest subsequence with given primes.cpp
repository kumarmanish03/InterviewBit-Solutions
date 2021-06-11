// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

// Easy using priority queue

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(A);
    pq.push(B);
    pq.push(C);
    while(res.size() < D){
        int temp = pq.top();
        pq.pop();
        res.push_back(temp);
        pq.push(temp*A);
        pq.push(temp*B);
        pq.push(temp*C);
    }
    
    return res;
}
