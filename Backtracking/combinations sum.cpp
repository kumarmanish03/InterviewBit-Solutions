// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/combination-sum-ii/

void targetSum(vector<int> A, int sum, int i, vector<int> temp, set<vector<int> > &v){
    if(sum == 0){
        v.insert(temp);
        return;
    }
    else if(i == A.size() || sum < 0){
        return;
    }
    
    // Excluding element
    targetSum(A, sum, i+1, temp, v);
    
    // Including element
    temp.push_back(A[i]);
    targetSum(A, sum-A[i], i+1, temp, v);
    temp.pop_back(); // backtrack
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<int> temp;
    set<vector<int> > v;
    targetSum(A, B, 0, temp, v);
    vector<vector<int> > ans;
    ans.assign(v.begin(), v.end());
    return ans;
}
