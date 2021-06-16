// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/cycle-in-undirected-graph/
// Disjoint Set
//https://www.youtube.com/watch?v=eTaWFhPXPz4

// Using DFS
bool iscycleDFS(vector<vector<int> > &adj,vector<bool> &vis,int u,int parent)
{
    vis[u] = true;
    for(auto t : adj[u])
    {
        if(!vis[t])
        {
            if(iscycleDFS(adj,vis,t,u))
              return true;
        }
        else if(parent != t)
           return true;
    }
    vis[u] = false;
    return false;
}


int Solution::solve(int V, vector<vector<int> > &B) {
    int E = B.size();
    vector<vector<int> > adj(V+1);
    vector<bool> vis(V+1,false);
    for(int i=0;i<E;i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);    
    }
    for(int i=1;i<=V;i++)
    {
       if(iscycleDFS(adj,vis,i,-1))
         return true;
    }
    return false;
}


// =================
// Using Union and Find

// Note : Disjoint set union can only find cycle in undirected graph

int find(int i, vector<int> &dsuf){
    if(dsuf[i] == -1)
        return i;
    return find(dsuf[i], dsuf);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> dsuf(A+1, -1);     // Disjoint set union find
    for(auto i: B){
        int fromP = find(i[0], dsuf);
        int toP = find(i[1], dsuf);
        
        if(fromP == toP)
            return 1;
            
        // Making Union
        dsuf[fromP] = toP;
    }
    
    return 0;
}
