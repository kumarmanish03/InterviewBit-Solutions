// Manish Kumar, IIIT Allahabad

https://www.codechef.com/problems/STBMEX

// Refer:
// https://discuss.codechef.com/t/stbmex-editorial/100446

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";

#define int long long

int solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    set<int> m;
    for(int &x:v){
        cin >> x;
        m.insert(x);
    }

    int MEX = 0;
    while(1){
        if(m.find(MEX)!=m.end())
            MEX++;
        else{
            break;
        }
    }

    // print(MEX);

    int ans = 0;
    if(MEX == 0){
        int mn = *min_element(v.begin(), v.end());
        ans = mn-1;
    }
    else if(MEX == 1){
        ans = -1;
    }
    else{
        vector<int> arr;
        for(auto i:m)
            arr.push_back(i);
        int curr = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1]+1 == arr[i]){
                curr++;
            }
            else{
                if(curr >= MEX-1)
                    ans++;
                curr = 1;
            }
        }
        if(curr >= MEX-1)
            ans++;
        ans--;
    }

    print(ans);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--) solve();
}
