// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/subsets-ii/

// Using set of vectors so that permutations will arrange lexographically
// and to remove duplicate elements

void solve(int i, vector<int> A, set<vector<int> > &s, vector<int> temp){
    if(i == A.size()){
        s.insert(temp);
        return;
    }
    
    solve(i+1, A, s, temp);
    temp.push_back(A[i]);
    solve(i+1, A, s, temp);
    temp.pop_back();
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    // Sorting string makes each subset sorted
    sort(A.begin(), A.end());
    // Using set for storing each vector delete repeated subsets and sort them also
    set<vector<int> > v;
    vector<vector<int> > ans;
    vector<int> temp;
    solve(0, A, v, temp);
    ans.assign(v.begin(), v.end());
    return ans;
}
