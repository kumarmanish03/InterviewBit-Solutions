// Manish Kumar, IIIT Allahabad
// Hard

https://www.geeksforgeeks.org/dynamic-programming-trees-set-2/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define for0(i,n)   for ( int (i)=0; (i)<(n); (i)++)
#define for1(i,n)   for ( int (i)=1; (i)<=(n); (i)++)
typedef vector<int> vi;
#define pb push_back
#define OJ \
        freopen("input.txt", "r", stdin); \
        freopen("output.txt", "w", stdout);

// dp[i] stores max length path in subtree i
int dp[100];

int solve(int u, vector<int> adj[], vector<bool> &vis, int &res){
    vis[u] = true;

    if(dp[u] != -1){
        return dp[u];
    }

    int mx = 0;
    for(auto v : adj[u]){
        if(!vis[v]){
            mx = max(mx, solve(v, adj, vis, res));
        }
    }

    vis[u] = false;

    res = max(res, mx + 1);

    return dp[u] = mx + 1;
}

// traversing all nodes so that find max from it
void dfs(int u, vector<int> adj[], vector<bool> &vis2, int &res){
    vis2[u] = true;
    vector<bool> vis(12, false);
    for(auto v : adj[u]){
        if(!vis2[v]){
            solve(v, adj, vis, res);
        }
    }
}

int main(){
    vector<int> v[12];
    vector<bool> vis2(12, false);
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[7].push_back(10), v[10].push_back(7);
    v[7].push_back(11), v[11].push_back(7);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);

    int res = INT_MIN;
    memset(dp, -1, sizeof(dp));
    dfs(1, v, vis2, res);
    
    cout << res;
}