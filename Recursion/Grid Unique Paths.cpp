// By Manish Kumar (IEC2019068), IIIT Allahabad
// Easy
// https://www.interviewbit.com/problems/grid-unique-paths/
// Asked in Google, Amazon, Microsoft, Adobe

int countpath(int A, int B, int x, int y){
    if(x == A - 1 && y == B - 1) return 1;
    if(x > A - 1 || y > B - 1) return 0;
    return countpath(A, B, x + 1, y) + countpath(A, B, x, y + 1);
}

int Solution::uniquePaths(int A, int B) {
   return countpath(A, B, 0, 0);
}