// Manish Kumar, IIIT Allahabad
// Medium, Tricky
// Greedy

https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &A) {
    if(A.size() < 2)
        return 0;

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
