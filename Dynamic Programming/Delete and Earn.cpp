// Manish Kumar, IIIT Allahabad
// DP, Observation

// If you clearly observe this problem reduce to-
// "Find max sum such that no two consecutive added" OR Stlicker thieve problem GFG

class Solution {
public:
    
    int deleteAndEarn(vector<int>& num) {
        int mx = *max_element(num.begin(), num.end());
        vector<int> a(mx+1, 0);
        for(int i : num){
            a[i]+=i;
        }
        int dp[mx+1];
        dp[0] = a[0];
        dp[1] = max(a[1], a[0]);
        for(int i = 2; i < mx+1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        return dp[mx];
    }
};
