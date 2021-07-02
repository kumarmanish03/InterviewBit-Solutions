// Manish Kumar, IIIT Allahabad
// Easy

// Sliding Window Approach

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int cnt = 0;
        int left = 0;
        int right = 0;
        int prod = 1;
        while(right < nums.size()){
            prod *= nums[right];
            
            while(prod >= k){
                prod /= nums[left];
                left++;
            }
            
            cnt += right - left + 1;
            
            right++;
        }
        
        return cnt;
    }
};