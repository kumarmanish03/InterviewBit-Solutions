// Manish Kumar, IIIT Allahabad

// https://www.codechef.com/problems/TRAINPLN

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
	double ans = 0.0;
	vector<int> a(n);
	vector<int> b(n);
	map<int, vector<int>> m;
	for(int &x:a)
		cin >> x;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		m[b[i]].push_back(a[i]);
	}

	priority_queue<int> pq;
	int sum = 0;
	double mx = 0.0;
	for(int i = 0; i < n; i++){
		for(int x:m[i])
			pq.push(x);
		if(pq.empty())
			break;
		sum += pq.top();
		pq.pop();
		double temp = (double)sum / (i + 1);
		mx = max(temp, mx);
	}

	cout << fixed << setprecision(6) << mx << "\n";
	
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin>>t;
	while(t--) solve();
}
