// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/old/problems/subarray-with-given-xor/

// Strategy : [In Comments]
// prerequisite : No. of unique pairs whose Xor is B
// If arr[i] ^ arr[j] = B then also arr[i] ^ B = arr[j]

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    // stores all subarrays from start
    // Ex: A = {1, 2, 3};
    // v = {1, 1^2, 1^2^3};
    vector<int> v;
    int result = 0;
    
    int curr = 0;
    for(auto i : A){
        curr ^= i;
        v.push_back(curr);
        m[curr]++;
    }
    
    // Checking if tagert present in v
    if(m.count(B))
        result += m[B];
    
    // clearing m
    m.clear();

    // Now xor of any two from v makes all unique sub-arrays
    // So, now problem reduced to check pair from v whose xor is B
    for(int i = 0; i < v.size(); i++){
        if(m.count(v[i]^B)){
            result += m[v[i]^B];
        }
        m[v[i]]++;
    }
    
    return result;
}
