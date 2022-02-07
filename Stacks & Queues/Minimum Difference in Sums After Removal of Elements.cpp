// Manish Kumar, IIIT Allahabad
// Hard-Medium, priority_queue
// TC: O(NlogN), SC: O(N)

// first<> stores curr min sum of n elements at ith index from left
// second<> stores curr max sum of n elements at ith index from right
// Then final answer is just min(first[i] - second[i+1]) for all possible indexes

class Solution {
public:
    #define ll long long
    
    long long minimumDifference(vector<int>& nums) {
        int sz = nums.size();
        int n = sz/3;
        vector<ll> first(sz, 0), second(sz, 0);
        
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        
        first[0] = (ll)nums[0];
        pq1.push(nums[0]);
        for(int i = 1; i < 2*n; i++){
            if(i < n){
                first[i] = (ll)nums[i] + first[i-1];
                pq1.push(nums[i]);
            }
            else{
                pq1.push(nums[i]);
                first[i] = first[i-1] + (ll)nums[i] - (ll)pq1.top();
                pq1.pop();
            }
        }
        
        second[sz-1] = (ll)nums[sz-1];
        pq2.push(nums[sz-1]);
        for(int i = sz-2; i >= 0; i--){
            if(i >= 2*n){
                second[i] = (ll)nums[i] + second[i+1];
                pq2.push(nums[i]);
            }
            else{
                pq2.push(nums[i]);
                second[i] = second[i+1] + (ll)nums[i] - (ll)pq2.top();
                pq2.pop();
            }
        }
        
        ll ans = LLONG_MAX;
        for(int i = n-1; i < 2*n; i++)
            ans = min(ans, first[i] - second[i+1]);
        
        return ans;
    }
};
