// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/2-sum/

// Also done without using extra vector, see complete soln interviewbit

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second)
        return p1 < p2;
    else if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    
    return p1 > p2;
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> m;
    int k;
    vector<pair<int, int> > v;
    for(int i = A.size()-1; i >= 0; i--){
        k = B - A[i];
        if(m.find(k) != m.end()){
            v.push_back({i+1, m[k]});
        }
        m[A[i]] = i+1;
    }
    
    pair<int, int> p = *min_element(v.begin(), v.end(), comp);
    
    if(v.size() == 0)
        return {};
    
    return {p.first, p.second};

}
