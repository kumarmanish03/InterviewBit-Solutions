// Manish Kumar, IIIT Allahabad
// Medum

// Prims Algorithm
// TC : O()

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


// Kruskals Algorithm
// TC : O(ElogE + EV)

bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int findP(int u, vector<int> &dsuf){
    if(dsuf[u] == -1){
        return u;
    }
    return findP(dsuf[u], dsuf);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> dsuf(A+1, -1);
    
    sort(B.begin(), B.end(), comp);
    
    int minCost = 0, cnt = 0, i = 0;
    while(cnt != A-1){
        vector<int> u = B[i];
        int fromP = findP(u[0], dsuf);
        int toP = findP(u[1], dsuf);
        
        if(fromP == toP){
            i++;
            continue;
        }
        
        dsuf[fromP] = toP;
        minCost += u[2];
        i++;
        cnt++;
    }
    
    return minCost;
}
