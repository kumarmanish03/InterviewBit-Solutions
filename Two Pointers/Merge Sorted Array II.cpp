// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(m + n)
// Space Complexity : O(1)


https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int i = m-1;
    int j = n-1;
    A.resize(m+n);
    int k = m + n - 1;
    while(i >= 0 && j >= 0){
        if(A[i] > B[j]){
            A[k] = A[i];
            i--;
            k--;
        }
        else {
            A[k] = B[j];
            j--;
            k--;
        }
    }
    while(j >= 0){
        A[k] = B[j];
        j--;
        k--;
    }
}
