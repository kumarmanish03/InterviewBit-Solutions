// Manish Kumar, IIIT Allahabad

https://www.codechef.com/problems/SEGDIV

#include<bits/stdc++.h>
using namespace std;

#define int long long

// Solution 1
const int N = 505;
int arr[N];

void pre(){
  for(int i = 0; i < N; i++){
    arr[i] = i+1;
    if(i%2)
      swap(arr[i], arr[i-1]);
  }
}

int solve(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
  
  return 0;
}


// Solution 2

// const int N = 100000;
// int arr[505];

// bool isValid(int i, int j){
//   int sum = i, len = 1;
//   for(int k = j; k >= 1; k--){
//     sum += arr[k];
//     len++;
//     if(sum % len == 0){
//       return false;
//     }
//   }
//   return true;
// }

// void pre(){
//   arr[1] = 1;
//   arr[2] = 2;
//   int j = 2;
//   for(int i = 3; i <= N && j < 505; i++){
//     if(isValid(i, j)){
//       arr[++j] = i;
//     }
//   }
// }

// int solve(){
//   int n;
//   cin >> n;
//   for(int i = 1; i <= n; i++){
//     cout << arr[i] << " ";
//   }
//   cout << "\n";

//   return 0;
// }

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  int t = 1;
  cin>>t;
  while(t--) solve();
}
