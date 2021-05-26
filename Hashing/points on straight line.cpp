// Manish Kumar
// Hard, Must try

https://www.interviewbit.com/problems/points-on-the-straight-line/

vector<double> slope(int x1, int y1, int x2, int y2)
{
    double m;
    if(x1 == x2)
        m = INT_MAX;
    else 
        m = (double)(y2-y1)/(x2-x1);
    
    double c = y1 - m*x1;
    return {m, c};
}

int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    if(A.size() <= 2)
        return A.size();

    map<vector<double>, set<vector<int> > > m;
    for(int i = 0; i < A.size(); ++i)
    {
        int x1 = A[i], y1 = B[i];
        for(int j = i+1; j < A.size(); ++j)
        {
            int x2 = A[j], y2 = B[j];
            vector<double> mc = slope(x1, y1, x2, y2);
            m[mc].insert({x1, y1, i});
            m[mc].insert({x2, y2, j});
        }
    }
    
    int ans = 0;
    for(auto it = m.begin(); it != m.end(); ++it)
        ans = max(ans, (int)(it->second).size());
    
    return ans;
}