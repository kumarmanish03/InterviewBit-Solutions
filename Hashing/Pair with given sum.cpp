// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/pairs-with-given-xor/

// Strategy:
// Xor has a property i.e, If A ^ B = C then A ^ C = B and B ^ C = A
// Hence we insert A[i] in set and if A[i]^B present in set already then it means we have find a pair A[i]^A[j] = B

int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> s;
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        if(s.find(A[i]^B) != s.end())
            count++;
        s.insert(A[i]);
    }
    
    return count;
}
