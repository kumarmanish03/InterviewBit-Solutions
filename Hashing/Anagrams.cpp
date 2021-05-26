// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n*(slog(s) + logn))
// Space Complexity : O(n*n)

https://www.interviewbit.com/problems/anagrams/

// The 'compute_hash' function is the standard function used for hashing string
// but string should be same, although for anagrams i first sorted the string and then calculated its hash
// Read more about at : https://cp-algorithms.com/string/string-hashing.html#toc-tgt-0 


string hsh(string s){
    sort(s.begin(), s.end());
    
    return s;
}

// Standard Hash Function used for string hashing 
long long compute_hash(string s) {
    sort(s.begin(), s.end());
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    //stringstream s(A);
    string word;
    vector<vector<int> > v;
    map<string, int> m; // {hash, index in vector}
    int i = 0;
    //int j = 0;
    for(int k = 0; k < A.size(); k++){
        word = A[k];
        i++;
        string h = hsh(word);
        if(m.find(h) == m.end()){ // not found
            v.push_back({i});
            m[h] = v.size();
           // j++;
        }
        else{  // Found
            v[m[h]-1].push_back(i);
        }
    }
    
    return v;
}
