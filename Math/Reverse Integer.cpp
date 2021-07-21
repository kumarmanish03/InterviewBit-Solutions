// Manish Kumar, IIIT Allahabad
// Easy

// Overflow condition

https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    int sign = (A > 0) ? 1 : -1;
    A = abs(A);
    int ans = A % 10;
    A/=10;
    while(A){
      // Overflow condition
        if(ans > (INT_MAX - A%10) / 10)
            return 0;
        ans = ans * 10 + A % 10;
        A/=10;
    }
    return ans * sign;
}
