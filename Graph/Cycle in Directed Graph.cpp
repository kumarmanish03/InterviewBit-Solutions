// Manish Kumr, IIIT Allahabad
// Easy-Medium

https://www.interviewbit.com/problems/cycle-in-directed-graph/


bool dfs(int u, vector<vector<int> > &adj, vector<bool> &vis){
    
    vis[u] = true;
    for(auto v:adj[u]){
        if(!vis[v])
            if(dfs(v, adj, vis))
                return true;
        // Since only at least 2 nodes in cycle 
        // For atleast 3 nodes question, see ques 'Cycle in undirected graph'
        if(vis[v] && v != u){
            return true;
        }
    }
    vis[u] = false;
    
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > adj(A+1);
    for(int i = 0; i < B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<bool> vis(A+1, 0);
    for(int i = 1; i <= A; i++){
        if(dfs(i, adj, vis))
            return true;
    }
    return false;
}
