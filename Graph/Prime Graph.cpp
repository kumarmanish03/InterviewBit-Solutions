// Manish Kumar, IIIT Allahabad
// Medium, Observation

// Since max degree for n nodes is n(n-1)/2 and degree should be prime hence 
// n(n-1)/2 >= (k * n)/2 where k : degree of each node 
// Hence (n-1) >= k, find k st less than (n-1)
// Above is for only even nodes. For odd just add +1

https://www.codechef.com/COOK137B/problems/PRIMEGRAPH

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,n)   for ( int (i)=(a); (i)<(n); (i)++)

const int N = 100000;
vector<bool> is_prime(N+1, true);
vector<int> arr(N+1);


void pre(){
  int n = N;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
  }

  arr[3] = 3;
  for(int i = 4; i < N+1; i+=2){
    int k = i;
    while(is_prime[k] == false){
      k--;
    }
    arr[i] = (k * i) / 2;
    arr[i+1] = arr[i] + 1;
  }
}

int solve(){
  int n;
  cin >> n;
  cout << arr[n] << "\n";
  
  return 0;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  int t = 1;
  cin>>t;
  while(t--) solve();
}
