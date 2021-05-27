// Manish Kumar, IIIT ALlahabad

// Generate permutations (3 methods)
// Method 1
// Method 2 (generate all permutation of vector v having distinct elements)
// Method 3 (generate all permutations of vector v having similar elements also)

// STL function : next_permutations(v.begin(), v.end()); using do while loop

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

vector<int> permutations;

// Method 1
void solve(int n, vector<bool> &chosen){
	if(permutations.size() == n){
		for(auto i:permutations)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for(int i = 0; i < n; i++){
		if(chosen[i]) continue;
		chosen[i] = true;
		permutations.push_back(i);
		solve(n, chosen);
		chosen[i] = false;
		permutations.pop_back();
	}
}

// Method 2 (generate all permutation of vector v having distinct elements)
void permute(int idx, vector<int> &v){
	if(idx == v.size()){
		for(auto i:v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for(int i = idx; i < v.size(); i++){
		swap(v[i], v[idx]);
		permute(idx+1, v);
		swap(v[i], v[idx]);
	}
}

// Method 3 (generate all permutations of vector v having similar elements also)
void permuteDistinct(int idx, vector<int> &v){
	if(idx == v.size()){
		for(auto i:v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for(int i = idx; i < v.size(); i++){
		if(i != idx && v[i] == v[idx])
			continue;
		swap(v[i], v[idx]);
		permuteDistinct(idx+1, v);
		swap(v[i], v[idx]);
	}
}


int main(){
	OJ;
	int n;
	cin >> n;

	vector<bool> chosen(n);
	solve(n, chosen);

	vector<int> v{1,2,3};
	permute(0, v);

	vector<int> v1{1,2,3,3};
	permuteDistinct(0, v1);
}