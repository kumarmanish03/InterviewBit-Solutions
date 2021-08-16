// Manish Kumar, IIIT Allahabad
// Medium-Hard

https://www.interviewbit.com/old/problems/word-break-ii/


bool is_possible(string &A,int ind,unordered_set<string> &mp,vector<int> &dp,int m, string temp, vector<string> &res)
{
    if(ind==A.size()){
        temp.pop_back();
        res.push_back(temp);
        return true;
    }
    
    // if(dp[ind]!=-1)
    //     return (bool)dp[ind];
    
    bool flag=false;
    string s="";
    for(int i=ind;i<A.size();i++)
    {
        s+=A[i];
        if(mp.find(s)!=mp.end()){
            flag |= is_possible(A,i+1,mp,dp,m, temp + s + " ", res);
        }
        if(s.size()==m)
            break;
    }
    return dp[ind] = flag;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    vector<int>dp(n+1,-1);
    int m=-1;
    unordered_set<string>mp;
    for(int i=0;i<B.size();i++)
    {
        mp.insert(B[i]);
        m=max(m,(int)B[i].size());
    }
    string temp = "";
    vector<string> res;
    
    is_possible(A,0,mp,dp,m, temp, res);

    sort(res.begin(), res.end());

    return res;
}
