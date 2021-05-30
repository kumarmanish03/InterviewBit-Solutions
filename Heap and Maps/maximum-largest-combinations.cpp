// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    priority_queue<pair<int, pair<int, int> > > maxHeap;
    set<pair<int, int>> s;
    vector<int> ans;
    maxHeap.push({A[n-1] + B[n-1], {n-1, n-1}});
    s.insert({n-1, n-1});
    // Run until we get C combinations
    while(C--){
        // copy first element (greater sum) to p
        pair<int, pair<int, int>> p = maxHeap.top();
        maxHeap.pop();
        
        // Adding sum to answer
        ans.push_back(p.first);
        
        int i = p.second.first;
        int j = p.second.second;
        
        // Add A[i-1] + A[j] 
        int sum = A[i-1] + A[j];
        if(s.find({i-1, j}) == s.end()){
            maxHeap.push({sum, {i-1, j}});
            s.insert({i-1, j});
        }
        
        // Add A[i] + A[j-1]
        sum = A[i] + A[j-1];
        if(s.find({i, j-1}) == s.end()){
            maxHeap.push({sum, {i, j-1}});
            s.insert({i, j-1});
        }
    }
    
    return ans;
}
