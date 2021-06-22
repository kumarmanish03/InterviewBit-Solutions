// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(logp)  (p is posn of target element)
// Space Complexity : O(1)

// Similar problem 
https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

// Strategy (of above problem link):
// Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element, 
// if it is greater than high index element then copy high index in low index and double the high index. 
// if it is smaller, then apply binary search on high and low indices found. 

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
    int arr[] = {0, 1, 1, 1};

    int lo = 0, hi = 1;

    while(arr[hi] != 1){
        lo = hi;
        hi = hi*2;
    }

    while(hi >= lo){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == 1)
            return mid;
        else
            return mid+1;
    }  

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  OJ;
  int t = 1;
  //cin>>t;
  cout << solve();
}