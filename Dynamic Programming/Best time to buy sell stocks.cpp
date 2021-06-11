// Manish Kumat, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

// Simple greedy approach

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return 0;
    
    int maxProfit = INT_MIN;
    int minBuy = A[0];
    for(int i = 0; i < n; i++){
        if(A[i] - minBuy < 0)
            minBuy = A[i];
        maxProfit = max(maxProfit, A[i] - minBuy);
    }
    
    return maxProfit;
}
