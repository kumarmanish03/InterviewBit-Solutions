// Manish Kumar, IIIT Allahabad
// Easy, Standard Question
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/sort-by-color/

// See InterviewBit Solution

void Solution::sortColors(vector<int> &A) {
    int zero = -1;
    int two = A.size();
    int i = 0;
    int j = A.size() - 1;
    while(i < A.size()){
        if(A[i] == 0 && zero + 1 == i) zero++;
        if(A[i] == 0 && zero + 1 < i) {
            zero++;
            swap(A[i], A[zero]);
        }
        i++;
    }
    
    while(j >= 0) {
        if(A[j] == 2 && two - 1 == j) two--;
        if(A[j] == 2 && two - 1 > j) {
            two--;
            swap(A[j], A[two]);
        }
        j--;
    }
}
