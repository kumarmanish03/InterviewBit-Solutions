// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/


// Returns pair with maximum difference and lowest first index
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second-p1.first > p2.second-p2.first){
        return false;
    }else if(p1.second-p1.first == p2.second-p2.first){
        if(p1.first < p2.first)
            return false;
    }
    
    return true;
}

vector<int> Solution::lszero(vector<int> &A) {
    vector<int> temp = A;
    for(int i = 1; i < A.size(); i++){
        A[i] = A[i] + A[i-1];
    }
    map<int, set<int> > m;
    for(int i = 0; i < A.size(); i++){
        m[A[i]].insert(i);
    }
    vector<pair<int, int> > v;
    for(auto i:m){
        if(i.first == 0){
            auto it = i.second.end();
            it--;
            v.push_back({0, *it});
        }
        else {
            if(i.second.size() >= 2){
            auto start = i.second.begin();
            auto end = i.second.end();
            end--;
            v.push_back({(*start)+1, *end});
            }
        }
    }
    
    // For no sum zero
    if(v.size() == 0)
        return {};
    

    // Returns pair with maximum difference and lowest first index(see 'comp' function)
    pair<int, int> p = *max_element(v.begin(), v.end(), comp);

     vector<int> ans;
     int start = p.first;
     int end = p.second;
    for(int i = start; i <= end; i++){
        ans.push_back(temp[i]);
    }
    
    return ans;
}
