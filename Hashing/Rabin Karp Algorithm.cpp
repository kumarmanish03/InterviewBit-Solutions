// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O(s + t)
// Space Complexity : O(s + t)

https://cp-algorithms.com/string/rabin-karp.html

#include<bits/stdc++.h>
using namespace std;

#define IO \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main(){
  IO;
  int t;
  cin >> t;
  while(t--){
    string s;
    string t;
    cin >> t;
    cin >> s;
    int T = t.size();
    int S = s.size();
    
    const int p = 31;
    const int m = 10e9+7;
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for(int i = 1; i < p_pow.size(); i++){
      p_pow[i] = (p_pow[i-1] * p) % m;
    }

    vector<long long> tHash(T+1, 0);
    for(int i = 0; i < T; i++){
      tHash[i+1] = (tHash[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }
    long long sHash = 0;
    for(int i = 0; i < S; i++){
      sHash = (sHash + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    vector<int> occurances;
    bool found = false;
    for(int i = 0; i + S - 1 < T; i++){
      long long curr = (tHash[i+S] - tHash[i]) % m;
      if(curr == sHash * p_pow[i]){
        occurances.push_back(i+1);
        found = true;
      }
    }

    if(!found) cout << "Not Found";
    else {
      cout << occurances.size() << "\n";
      for(auto i : occurances){
        cout << i << " ";
      }
    }
    cout << "\n\n";
  }

}