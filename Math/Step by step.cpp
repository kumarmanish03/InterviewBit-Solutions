// Manish Kumar, IIIT Allahabad
// Medium, Tricky

https://www.interviewbit.com/old/problems/step-by-step/


int Solution::solve(int A) {
    A = abs(A);
    if(A == 0) return 0;
    long long sum = 0;
    long long i = 1;
    while(1){
        sum += i;
        if(sum == A)
            return i;
        if(sum > A)
            break;
        i++;
    }
    // if we change any sign to -ve then sum will decrease by sum - 2(n) 
    // where n is no. whose sign is changed
    if((sum - 1LL * A) % 2 == 0) return i;
    if((sum + i + 1 - (1LL * A)) % 2 == 0) return i+1;
    else return i+2;
}
