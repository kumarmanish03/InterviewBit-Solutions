// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/scramble-string/
https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=41


unordered_map<string, bool> m;

bool scramble(string A, string B){
    int i = 0;
    int j = A.size()-1;
    int n = A.size();
    
    if(A.size() == 0)
        return false;
    if(A.size() == 1 && A.compare(B) == 0)
        return true;
    if(A.size() == 1 && A.compare(B) != 0)
        return false;
    if(A.compare(B) == 0)
        return true;
    
    // temp is storing a unique key
    string temp = A;
    temp.push_back(' ');
    temp.append(B);
    if(m.find(temp) != m.end())
        return m[temp];
    
    bool flag = false;
    for(int k = i; k <= j-1; k++){
        bool cond1 = scramble(A.substr(0, k+1), B.substr(0, k+1)) && scramble(A.substr(k+1, n-k-1), B.substr(k+1, n-k-1));
        bool cond2 = scramble(A.substr(0, k+1), B.substr(n-k-1, k+1)) && scramble(A.substr(k+1, n-k-1), B.substr(0, n-k-1));
        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    
    return m[temp] = flag;
}

int Solution::isScramble(const string A, const string B) {
    m.clear();
    int n = A.size();
    return scramble(A, B);
}
