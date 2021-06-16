// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/two-teams/

// Standard 2 color problem or Bipartite problem

bool dfs(int u, int c, int par, vector<vector<int> > &adj, vector<int> &team, vector<bool> &vis){
    vis[u] = true;
    team[u] = c;
    for(auto v:adj[u]){
        if(v == par)
            continue;
        if(team[v] == 0){
            if(!dfs(v, team[u]^3, u, adj, team, vis))
                return false;
        }
        if(team[v] == team[u]){
            return false;
        }
    }

    return true;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > adj(A+1);
    for(auto i:B){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    // team 0 : noteam
    // team 1 : 1st team
    // team 2 : 2nd team
    vector<int> team(A+1, 0);
    vector<bool> vis(A+1, 0);
    for(int i = 1; i <= A; i++){
        if(!vis[i] && !dfs(i, 1, -1, adj, team, vis))
            return false;
    }
    
    return true;
}
