// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/old/problems/two-out-of-three/

// Handle cases carefully, since in a array no. are repeating and we have to consider them once only
// So we give map value to each array as m[i] = 1, 2, 3 and m[i] = 4 for elements recurring

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int, int> m;
    vector<int> res;
    for(auto i : A){
        m[i] = 1;
    }

    for(auto i : B){
        if(m.count(i)){
            if(m[i] == 1)
                m[i] = 4;
        }
        else m[i] = 2;
    }

    for(auto i : C){
        if(m.count(i)){
            if(m[i] == 1 || m[i] == 2)
                m[i] = 4;
        }
        else
            m[i] = 3;
    }

    for(auto k : m){
        if(k.second == 4)
            res.push_back(k.first);
    }
    sort(res.begin(), res.end());
    return res;
}
