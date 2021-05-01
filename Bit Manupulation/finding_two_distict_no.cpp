// By Manish Kumar (IEC2019068), IIIT Allahabad
// Hard
//https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#
//https://youtu.be/u5-ss5kKy7g

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }
        
        int set_bit = ans & -ans;
        
        for(int i = 0; i < nums.size(); i++){
            if(set_bit & nums[i])
                v[0] ^= nums[i];
            else
                v[1] ^= nums[i];
        }
        
        if(v[0] > v[1])
            swap(v[0], v[1]);
        
        return v;
    }
};
