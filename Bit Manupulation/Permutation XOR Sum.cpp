// Manish Kumar, IIIT Allahabad
// Medium, Observation
// TC: log2(n)

https://www.codechef.com/problems/PERMXORSUM

// For a no. if we reverse its bits and then do xor to that no, then xor will max
// Ex. 10(1010) its rever(10) = 5(0101). Then 10^5 = 15(1111)
// And no. b/w 10 to 5 all can have 15 xors. Then for next rever(4) = 3 all no. b/w 4 to 3 have 4^3(111) and so on.

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 0;

int rever(int n){
  int x = 0;
  for(int i = 0; n > 1; i++){
    x += ((n & 1) ^ 1) << i;
    n = n >> 1;
  }
  return x;
}


int solve(){
  int n;
  cin >> n;
  int ans = 0;
  while(n > 0){
    int r = rever(n);
    // cout << rever(n);
    if(r == 0){
      n--;
      continue;
    }
    ans += (n-r+1)*(r ^ n);
    // cout << ans << " ";
    n = r-1;
  }
  cout << ans << "\n";
  
  return 0;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin>>t;
  while(t--) solve();
}
