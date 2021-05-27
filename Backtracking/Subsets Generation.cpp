// Manish Kumar, IIIT ALlahabad

// Subset generation using Bit Manupulation
// Subset generation using Recursion

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

vector<int> subset;

// Subset generation using Bit Manupulation
void getSubsets(int n){
	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < i; j++){
			if(1<<j & i) cout << j << " ";
		}
		cout << "\n";
	}
}


// Subset generation using Recursion
void solve(int i, int n){
	if(i == n){
		for(auto i:subset){
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	solve(i+1, n);
	subset.push_back(i+1);
	solve(i+1, n);
	subset.pop_back();
}

int main(){
  OJ;
	int n;
  cin >> n;

	solve(0, n);
	getSubsets(n);

}