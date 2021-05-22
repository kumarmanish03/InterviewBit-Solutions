// Manish Kumar, IIIT Allahabad
// Easy, Standard
// Time Complexity : O(n^2)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/longest-palindromic-substring/

// This is a standard question asked in interviews
// Their are three solutions of this question
// 1. takes TC : O(n^3), simple brute force
// 2. takes TC : O(n^2) but SC : O(n^2), DP solution (refer GFG)
// 3. is the optimized soln which is written below, takes TC : O(n^2) & SC : O(1)

string Solution::longestPalindrome(string A) {
    int n = A.size();
    int start1 = 0;
    int end1 = 0;
    // Palindrome with odd size
    for(int i = 1; i < A.size() - 1; i++){
        int a = i - 1;
        int b = i + 1;
        while(a >= 0 && b <= A.size()-1){
            if(A[a] != A[b]){
                break;
            }
            else {
                if(b - a + 1 > end1 - start1 + 1){
                    start1 = a;
                    end1 = b;
                }
                a--;
                b++;
            }
        }
    }
    
    int start2 = 0;
    int end2 = 0;
    
    // Palindrome with even size
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]){
            int a = i-1;
            int b = i;
            while(a >= 0 && b <= n - 1){
                if(A[a] != A[b]){
                    break;
                }
                else {
                    if(b - a + 1 > end2 - start2 + 1){
                        start2 = a;
                        end2 = b;
                    }
                    a--;
                    b++;
                }
            }
        }
    }
    
    if(end2 - start2 + 1 > end1 - start1 + 1){
        return A.substr(start2, end2 - start2 + 1); 
    }
    else if(end2 - start2 + 1 < end1 - start1 + 1){
        return A.substr(start1, end1 - start1 + 1); 
    }
    else {
        if(start1 < start2){
            return A.substr(start1, end1 - start1 + 1);
        }
        else{
            return A.substr(start2, end2 - start2 + 1); 
        }
    }

}
