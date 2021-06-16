// Manish Kumar, IIIT Allahabad
// Easy, Greedy

https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

// Strategy : 
// Chosse just min fibonacci no

// This ques is similar to coin change but for large cases it give MLE / TLE, Hence use greedy

int Solution::fibsum(int A) {
    if(A < 2) return A;
    vector<int> fibo = {1, 1};
    int f = 1;
    int s = 1;
    while(f + s <= A){
        fibo.push_back(f+s);
        f = s;
        s = fibo.back();
    }
    int mn = 0;
    
    for(int i = fibo.size()-1; i>=0; i--){
        if(A >= fibo[i]){
            A = A - fibo[i];
            mn++;
        }
        
        if(A == 0) return mn;
    }
        
    return mn;
}
