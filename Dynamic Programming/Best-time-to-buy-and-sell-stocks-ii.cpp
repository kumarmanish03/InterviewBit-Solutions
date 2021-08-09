// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/old/problems/best-time-to-buy-and-sell-stocks-ii/

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
