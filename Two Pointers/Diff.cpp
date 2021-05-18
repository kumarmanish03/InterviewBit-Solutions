// Manish Kumar, IIIT Allahabad
// Easy, Tricky
// Time Complexity : O(n)
// Space Complexity : O(1)
// https://www.interviewbit.com/problems/diffk/

// Try to select pointers where moving them handles both cases
// Ex: if we take i = 0 and j = n-1 then if i++ and j-- both cases
// decrease the difference(A[j] - A[i]), Hence it is good to take 
// i = 0 & j = 1 so that on i++, difference decreases and on j++
// difference increases and then handle the cases.
// Follow this in all Two Pointers Questions

int Solution::diffPossible(vector<int> &A, int B) {
    int ans = 0;
    if(A.size() == 1) return ans;
    int i = 0;
    int j = 1;
    while((i < A.size() || j < A.size()) && i < j) {
        int diff = A[j] - A[i];
        if(diff == B) {
            ans = 1;
            break;
        }
        else if(diff > B && j - i == 1) {
            i++;
            j++;
        }
        else if(diff > B){
            i++;
        }
        else if(diff < B){
            j++;
        }
    }
    
    return ans;
}
