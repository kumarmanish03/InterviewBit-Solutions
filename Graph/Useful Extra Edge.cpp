// Manish Kumar, IIIT Allahabad
// Hard
// Standard Dijkstra Problem

https://www.interviewbit.com/problems/useful-extra-edges/


int dijkstra(int A, vector<pair<int, int>> adj[], int C, int D){
    vector<bool> processed(A+1, false);
    vector<int> value(A+1, INT_MAX);
    value[C] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, C});
    
    while(!pq.empty()){
        pair<int, int> u = pq.top();
        pq.pop();
        
        processed[u.second] = true;
        
        for(auto v:adj[u.second]){
            if(!processed[v.first] && u.first+v.second < value[v.first]){
                value[v.first] = u.first + v.second;
                pq.push({value[v.first], v.first});
            }
        }
    }
    
    return value[D];
}


int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    int minPath = INT_MAX;
    vector<pair<int, int>> adj[A+1];
    for(auto i: B){
        // i[2] is weight of edge from i[0] -> i[1]
        adj[i[0]].push_back({i[1], i[2]});
    }
    
    for(auto i:E){
        if(i[0] > A || i[1] > A)
            continue;
        
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});   // Undirected edges
        
        minPath = min(minPath, dijkstra(A, adj, C, D));
        
        adj[i[0]].pop_back();
        adj[i[1]].pop_back();
    }
    
    if(minPath == INT_MAX)
        return -1;
        
    return minPath;
}
