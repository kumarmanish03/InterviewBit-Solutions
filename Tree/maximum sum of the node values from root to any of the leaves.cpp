// Manish Kumar, IIIT Allahabad
// Medium
// https://www.geeksforgeeks.org/dynamic-programming-trees-set-1/

// Tree + dp

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

int solve(int u, int a[], vector<int> adj[], vector<bool> &vis){
    vis[u] = true;

    int mx = INT_MIN;
    for(auto v : adj[u]){
        if(!vis[v]){
            mx = max(mx, solve(v, a, adj, vis));
        }
    }

    return mx == INT_MIN ? a[u-1] : mx + a[u-1];
}

int main(){
    vector<int> v[15];
    vector<bool> vis(15, false);
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);
    v[4].push_back(10), v[10].push_back(4);
    v[5].push_back(11), v[11].push_back(5);
    v[5].push_back(12), v[12].push_back(5);
    v[7].push_back(13), v[13].push_back(7);
    v[7].push_back(14), v[14].push_back(7);

    int a[] = { 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8 };

    cout << solve(1, a, v, vis);
}