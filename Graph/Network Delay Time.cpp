// Manish Kumar, IIIT Allahabad
// Medium, Dijkstta problem

class Solution {
public:

    int dijkstra(int n, vector<pair<int, int>> adj[], int k){
        vector<bool> processed(n+1, false);
        vector<int> value(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        value[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            processed[u] = true;
            for(auto [v, cw] : adj[u]){
                if(!processed[v] && w+cw < value[v]){
                    value[v] = w + cw;
                    pq.push({value[v], v});
                }
            }
        }
        
        int time = 0;
        for(int i = 1; i < n+1; i++){
            if(value[i] == INT_MAX)
                return -1;
            time = max(time, value[i]);
        }
        
        return time;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto e: times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        return dijkstra(n, adj, k);
    }
};
