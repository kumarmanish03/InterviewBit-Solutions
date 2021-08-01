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

int solve(int u, vector<vector<int>> &adj, vector<bool> &vis, int &remove, int k){

    vis[u] = true;
    int nodes = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            nodes += solve(v, adj, vis, remove, k);
        }
    }
    vis[u] = false;

    if(nodes > k){
        remove++;
        nodes = 0;
    }
    
    return nodes;
}

void addEdge(vector<vector<int>> &adj, int a, int b){
  adj[a].push_back(b);
  adj[b].push_back(a);
}

int main(){
    vector<vector<int>> adj(20);
    vector<bool> vis(20, false);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 6);

    int k = 3;
    int remove = 0;
    solve(1, adj, vis, remove, k);
    cout << remove;
}