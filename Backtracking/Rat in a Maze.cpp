// Manish Kumar, IIIT Allahabad
// Easy, Standard

https://www.codechef.com/problems/BPHC03/

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

// 0 is a open cell
// 1 is a blocked cell

int qcount = 0;
//int arr[7][7];

void solve(vector<vector<int> > &v, int i, int j, int n){
	// If invalid cell, return 
	 if(i >= n || j >= n || i < 0 || j < 0 || v[i][j]) return;

	// Base Condition is below above condition(think why?)
	// Since Vaid cell and reached the end, so count it and return
	 if(i == n-1 && j == n-1){
		 qcount++;
		 return;
	 }

	 v[i][j] = 1;
	 solve(v,i+1, j, n);
	 solve(v,i-1,j, n);
		solve(v,i, j-1, n);
		solve(v,i, j+1, n);
	 v[i][j] = 0;

}

int main(){
  OJ;
	int n;
  cin >> n;
	vector<vector<int> > v(n, vector<int>(n, 0));


  for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j++){
				cin >> v[i][j];
      }
  }

	solve(v, 0, 0, n);

	cout<< qcount << "\n";
}