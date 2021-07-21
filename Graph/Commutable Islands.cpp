// Manish Kumar, IIIT Allahabad
// Medum

// Prims Algorithm

https://www.interviewbit.com/old/problems/commutable-islands/

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pair<int, int>> adj[A+1];
    for(auto e : B){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    vector<bool> mst(A+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int minCost = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(!mst[u]){
            minCost += dist;
            mst[u] = true;
            for(auto v : adj[u]){
                if(!mst[v.first])
                    pq.push({v.second, v.first});
            }
        }
    }
    return minCost;
}
