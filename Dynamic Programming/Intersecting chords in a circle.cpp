// Manish Kumar, IIIT Allahabad
// Medium

// nth Catalen number

https://www.interviewbit.com/old/problems/intersecting-chords-in-a-circle/

#define m 1000000007
int Solution::chordCnt(int n) {
    if(n == 1) return 1;
    //int n = 2 * A;
    long long res[n+1] = {0};
    res[0] = res[1] = 1;
    for(int i = 2; i <= n; i+=1){
        for(int j = 0; j < i; j+=1){
            res[i] = (res[i] % m + (res[j] % m * res[i-j-1] % m) % m) % m;
        }
    }
    return res[n] % m;
}
