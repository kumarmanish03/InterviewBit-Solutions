// By Manish Kumar (IEC2019068), IIIT Allahabad
// Medium
// https://www.interviewbit.com/problems/rearrange-array/
// https://www.youtube.com/watch?v=XAbG2Bjs6NA
// you learn Encoding  i.e, - how to save two no. in one number, and then decode it


void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i < A.size(); i++){
        A[i] += (A[A[i]]%n)*n;
    }
    for(int i = 0; i < n; i++) A[i] = A[i]/n;
}
