// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/path-in-directed-graph/


bool dfs(int u, int A, vector<vector<int> > &adj, vector<bool> &vis){
    if(u == A){
        return true;
    }
    if(adj[u].size() == 0)
        return false;
    
    bool ans = false;
    vis[u] = true;
    for(auto v:adj[u]){
        if(!vis[v])
            ans |= dfs(v, A, adj, vis);
    }
    
    return ans;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > adj(A+1);
    for(auto i:B){
        adj[i[0]].push_back(i[1]);
    }
    vector<bool> vis(A+1, false);
    return dfs(1, A, adj, vis);
}
