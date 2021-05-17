// By Manish Kumar (IEC2019068), IIIT Allahabad
// Medium, Tricky
// https://www.interviewbit.com/problems/remove-consecutive-characters/
// Making cases combination is difficult 

string Solution::solve(string A, int B) {
    if(B == 1) return "";
    
    int cnt = 1;
    for(int i = 1; i < A.size(); i++){
        if(A[i] == A[i-1]){
            cnt++;
        }
        else {
            if(cnt == B) {
                A.erase(i - cnt, cnt);
                i -= cnt;
                cnt = 1;
            }
            else cnt = 1;
        }
        
        if(i == A.size() - 1 && cnt == B)
            A.erase(i-cnt+1, cnt);
    }
    
    return A;
}
