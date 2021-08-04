// Manish Kumar, IIIT Allahabad
// Easy

https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1#

int findMaxSum(int *arr, int n) {
	    if(n == 1){
	        return arr[0];
	    }
	    if(n == 2){
	        return max(arr[0], arr[1]);
	    }
	    //int dp[n] = {0};
	    int prev2 = arr[0];
	    int prev1 = max(arr[0], arr[1]);
	    int curr = 0;
	    for(int i = 2; i < n; i++){
	        curr = max(prev2 + arr[i], prev1);
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    return curr;
	}