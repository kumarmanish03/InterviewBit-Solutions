// Manish Kumar, IIIT Allahabad
// Easy
// TC: O(n)
// SC: O(n)

// Same as: Find maximum sum subsequence such that no two are consecutive
// Trick : line : 19

int FindMaxSum(int arr[], int n)
    {
        // sum[i] is the max sum till i s.t. no adjacent
        int sum[n];
        if(n >=1)
            sum[0] = arr[0];
        if(n >= 2)
            sum[1] = max(arr[0], arr[1]);
        
        for(int i = 2; i < n; i++){
            sum[i] = max(sum[i-1], sum[i-2] + arr[i]);
        }
        
        return sum[n-1];
    }