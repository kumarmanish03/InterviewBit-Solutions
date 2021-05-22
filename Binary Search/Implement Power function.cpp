// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(logn)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/implement-power-function/

// This ques is similar to binary exponentiation (https://cp-algorithms.com/algebra/binary-exp.html)
// In this ques the trick is, if base is -ve then the final answer is (-ans + d) % d;
// Becoz for negative no. OR Subtraction,  modulo is (-ans + M) % M

int Solution::pow(int x, int n, int d) {
    if(x == 0 || n < 0) return 0;
    if(n == 0 || x == 1) return 1;
    
    long long m = 10e9 + 7;
    long long ans = 1;
    long long temp;
    int isneg = false;
    int p = n;
    if(x < 0){
        isneg = true;
        temp = -x;
    } 
    else
        temp = x;
    while(n){
        if(n & 1){
            ans = (ans % d * temp % d) % d;
        }
        temp = (temp % d * temp % d) % d;
        n >>= 1;
    }
    
    if(isneg && (p & 1)) return (-ans + d) % d;
    else return ans % d;
}
