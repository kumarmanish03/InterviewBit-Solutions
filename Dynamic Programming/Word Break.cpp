// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/courses/programming/topics/dynamic-programming/

bool is_possible(string &A,int ind,unordered_set<string> &mp,vector<int> &dp,int m)
{
    if(ind==A.size())
        return true;
    
    if(dp[ind]!=-1)
        return (bool)dp[ind];
    
    bool flag=false;
    string s="";
    for(int i=ind;i<A.size();i++)
    {
        s+=A[i];
        if(mp.find(s)!=mp.end())
            flag |= is_possible(A,i+1,mp,dp,m);
        if(s.size()==20)
            break;
    }
    return dp[ind] = flag;
}

int Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    vector<int>dp(n+1,-1);
    int m=-1;
    unordered_set<string>mp;
    for(int i=0;i<B.size();i++)
    {
        mp.insert(B[i]);
        m=max(m,(int)B[i].size());
    }
    
    return is_possible(A,0,mp,dp,m);
}