// By Manish Kumar (IEC2019068), IIIT Allahabad
// Easy
// https://www.interviewbit.com/problems/single-number-ii/
// See both solutions, also see second one

// Solution 1 (My soln)
int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < 32; i++){
        int k = 0;
        for(int j = 0; j < n; j++){
            if(A[j] & 1 << i)
                k++;
        }
        
        if(k % 3)
            ans += 1 << i;
    }
    
    return ans;
}

// Solution 2
int Solution::singleNumber(const vector<int> &A) {

    int ones = 0, twos = 0;
    for(int i = 0; i < A.size(); i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;

}