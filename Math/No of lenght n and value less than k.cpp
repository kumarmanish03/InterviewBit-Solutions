// By Manish Kumar (IEC2019068), IIIT Allahabad
// Hard
// https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
// Try to understand Case 3rd, and implement it


int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size() == 0) return 0;
    
    int count = 0, ans = 0;
    int temp = C;
    vector<int> nC;
    while(temp){
        count++;
        nC.push_back(temp%10);
        temp /= 10;
    }
    reverse(nC.begin(), nC.end());
    
    if(count < B) {return 0;}    // Case 1
    
    if(count > B) {             // Case 2
        if(A[0] == 0) {
            ans += (A.size() - 1) * pow(A.size(), B - 1);
            if(B == 1) ans++;
        }
        else {
            ans += pow(A.size(), B);
        }
        
        return ans;
    }
    
    if(count == B) {    // Case 3
        if(B == 1){
            for(auto i:A)
                if(i < C) ans++;
            
            return ans;
        }
        else {
            int flag = 0, j = 0;
            do{
                int temp1 = 0;
                flag = 0;
                for(auto i:A){
                    if(i == nC[j]) flag = 1;
                    if(i < nC[j]) temp1++;
                    if(j == 0 && i == 0) temp1--;
                }
                ans += temp1 * pow(A.size(),count - j - 1);
                j++;
                // cout << "Yes" << flag;
            }while(flag == 1 && j < count);
            
            return ans;
        }
        
    }
}
