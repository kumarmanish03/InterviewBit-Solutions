// Manish Kumar, IIIT Allahabad
// Easy, Tricky
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/remove-element-from-array/

// Use of erase() creates undetectable problems, hence use this solution

int Solution::removeElement(vector<int> &A, int B) {
    int i = 0;
    int j = 0;
    for(; i < A.size() && j < A.size(); i++) {
        if(A[i] != B){
            A[j] = A[i];
            j++;
        }
    }
    
    return j;
}
