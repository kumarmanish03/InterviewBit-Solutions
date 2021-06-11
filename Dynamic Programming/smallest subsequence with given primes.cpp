// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

// Easy using sets

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    while(res.size() < D){
        int temp = *s.begin();
        s.erase(s.begin());
        res.push_back(temp);
        s.insert(temp*A);
        s.insert(temp*B);
        s.insert(temp*C);
    }
    
    return res;
}
