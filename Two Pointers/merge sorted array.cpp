// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(m + n)
// Space Complexity : O(m + n)

https://leetcode.com/problems/merge-sorted-array/submissions/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        }
        
        vector<int> v(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m || j < n){
            if(i < m && j < n){
                if(nums1[i] < nums2[j]){
                    v[k++] = nums1[i];
                    i++;
                }
                else{
                    v[k++] = nums2[j];
                    j++;
                }
            }
            else if(i >= m && j < n){
                v[k++] = nums2[j];
                j++;
            }
            else if(j >= n && i < m){
                v[k++] = nums1[i];
                i++;
            }
                
        }
        nums1 = v;
    }
};