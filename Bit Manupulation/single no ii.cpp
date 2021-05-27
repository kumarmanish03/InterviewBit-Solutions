// Manish Kumar, IIIT Allahabad
// Easy, Catch
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/single-number-ii/

// Strategy :
// storing bits of all values at each posn in 32 size array(int size)
// Hence, posn of bits of integer(occurs one) should not a multiple of 3

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
