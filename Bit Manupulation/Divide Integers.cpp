// By Manish Kumar (IEC2019068), IIIT Allahabad
// Medium
// See Soln

https://www.interviewbit.com/old/problems/divide-integers/

int Solution::divide(int C, int D) {
    long long A = C;
    long long B = D;
    if(A == 0) return 0;
    if(A == INT_MIN && B == -1) return INT_MAX;
    if(B == 0) return INT_MAX;
    if(B == 1) return A;
    if(B == -1) return -A;
    int sign = ((A > 0) ^ (B > 0)) ? -1 : 1;
    A = abs(A);
    B = abs(B);
    long long int temp = 0, qtn = 0;
    for(int i = 31; i >= 0; i--){
        if(temp + (B << i) <= A){
            temp += B << i;
            qtn += 1LL << i;
        }
    }
    
    return qtn * sign;
}
