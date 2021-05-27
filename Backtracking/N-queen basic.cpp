// Manish Kumar, IIIT Allahabad
// Easy, Backtrack

// From CC Handbook
// Question : 
// Consider the problem of calculating the number of ways n
// queens can be placed on an n × n chessboard so that no two queens attack each other. 

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

int qcount = 0;
int column[4] = {0};
int diag1[7] = {0};
int diag2[7] = {0};
int n;
void solve(int y){
    if(y == n){
        qcount++;
        return;
    }
    for(int x = 0; x < n; x++){
        if(diag1[x+y] || diag2[x-y+n-1] || column[x]) 
            continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        solve(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main(){
    OJ;
  cin >> n;
  solve(0);
    cout<< qcount << "\n";
}