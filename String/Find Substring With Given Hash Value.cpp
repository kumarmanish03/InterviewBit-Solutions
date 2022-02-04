// Manish Kumar, IIIT Allahabad
// Medium
// TC: O(n)

// Rolling Hash, Rabin karp algo

class Solution {
public:
    string subStrHash(string s, int pow, int mod, int k, int hashValue) {
        int n = s.size();
        reverse(s.begin(), s.end());
        long long pk = 1;
        long long hsh = 0;
        vector<long long> h(n, 0);
        for(int i = 0; i < n; i++){
            if(i < k)
                pk = (pk * pow) % mod;
            hsh = (hsh * pow + (s[i] - 'a' + 1)) % mod;
            if(i >= k){
                hsh = (hsh - (s[i-k] - 'a' + 1) * pk % mod + mod)%mod;
            }
            if(i >= k-1)
                h[i] = hsh;
        }
        reverse(h.begin(), h.end());
        reverse(s.begin(), s.end());
        for(int i = 0; i < n-k+1; i++){
            if(h[i] == hashValue)
                return s.substr(i, k);
        }
        
        return "-1";
    }
};
