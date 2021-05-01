// By Manish Kumar (IEC2019068), IIIT Allahabad
// Medium
// https://www.codechef.com/COOK128A/problems/OROFAND
// Must read!

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

int solve(){
  int n, q;
	cin >> n >> q;
	int arr[n];
	int ans = 0;
	int bitcount[32] = {0};
	for(int i = 0; i < n; i++){
		cin >>  arr[i];
		for(int j = 0; j < 32; j++){
			if(arr[i] & 1 << j) bitcount[j]++;
		}
	}

	for(int i = 0; i < 32; i++){
		if(bitcount[i])
			ans += 1 << i;
	}

	cout << ans << "\n";

	while(q--){
		int x, v;
		ans = 0;
		cin >> x >> v;
		for(int j = 0; j < 32; j++){
			if(arr[x-1] & 1 << j) bitcount[j]--;
		}
		arr[x-1] = v;
		for(int j = 0; j < 32; j++){
			if(arr[x-1] & 1 << j) bitcount[j]++;
		}

		for(int i = 0; i < 32; i++){
			if(bitcount[i])
				ans += 1 << i;
		}

		cout << ans << "\n";

	}


  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 // OJ;
  int t = 1;
  cin>>t;
  while(t--) solve();
}