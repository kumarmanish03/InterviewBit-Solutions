// Manish Kumar, IIIT Allahabad
// Easy, Tricky
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/pair-with-given-difference/

// While loop in solution is standard loop used in these type of questions
// This loop checks all pairs, and also checks two pairs alternatively i.e, a - b and b - a also
// Hence it also checks if B negative 
// That's why while loop condition is : j < N && i < N beco'z it may possible i > j

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    while(j < A.size() && i < A.size()){
        if(A[j] - A[i] == B && i != j){
            ans = 1;
            break;
        } 
        else {
            if(A[j] - A[i] < B){
                j++;
            }
            else {
                i++;
            }
        }
    }
    
    return ans;
}
