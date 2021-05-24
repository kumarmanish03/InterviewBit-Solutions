// Manish Kumar, IIIT Allahabad
// Hard, Standard
// Time Complexity : O(nlog(m))
// Space Complexity : O(1)

https://www.spoj.com/problems/EKO/

https://www.youtube.com/watch?v=JAfJssvFgDI&t=1095s
// Watch video to understand the concept
// Must Try

#include<bits/stdc++.h>
using namespace std;

#define OJ \
        freopen("input.txt", "r", stdin); \
        freopen("output.txt", "w", stdout);

const long long N = 10e6+10;

long long n;
long long m;
long long trees[N];

bool isWoodSufficient(long long h){
  long long wood = 0;
  for(int i = 0; i < n; i++){
    if(trees[i] >= h){
      wood += (trees[i] - h);
    }
  }

  return wood >= m;
}

int main(){
 // OJ;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> trees[i];
  }
  long long lo = 0, hi = 2 * 10e9, mid;
  while(hi - lo > 1){
    mid = lo + (hi - lo) / 2;
    if(isWoodSufficient(mid)){
      lo = mid;
    }
    else {
      hi = mid - 1;
    }
  }

  if(isWoodSufficient(hi)){
    cout << hi << "\n";
  }
  else {
    cout << lo << "\n";
  }
}