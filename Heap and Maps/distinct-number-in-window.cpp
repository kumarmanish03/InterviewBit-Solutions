// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/distinct-numbers-in-window/

// This problem can only be done with unordered_maps in O(1) TC

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    if(B > n)
        return {};
        
    unordered_map<int, int> m;
    vector<int> ans;
    for(int i = 0; i < B; i++){
        m[A[i]]++;
    }
    
    ans.push_back(m.size());
    for(int i = 0; i < n-B; i++){
        if(m[A[i]] == 1)
            m.erase(A[i]);
        else
            m[A[i]]--;
        m[A[i+B]]++;
        ans.push_back(m.size());
    }
    
    return ans;
}
