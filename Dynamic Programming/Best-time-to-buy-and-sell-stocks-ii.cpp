// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/old/problems/best-time-to-buy-and-sell-stocks-ii/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/

// Solution 1
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int fb = INT_MIN, sb = INT_MIN;
        int fs = 0, ss = 0;
        for(int i = 0; i < A.size(); i++){
            fb = max(fb, -A[i]);
            fs = max(fs, fb + A[i]);
            sb = max(sb, fs - A[i]);
            ss = max(ss, sb + A[i]);
        }
        return ss;
    }
};

// Solution 2
int Solution::maxProfit(const vector<int> &A) {
    if(A.size() < 2)
        return 0;
    
    int buy = A[0];
    int profit = 0;
    for(int i = 1; i < A.size(); i++){
        if(A[i] < buy)
            buy = A[i];
        else{
            profit += A[i] - buy;
            buy = A[i];
        }
    }

    return profit;
}
