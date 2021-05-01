// By Manish Kumar (IEC2019068), IIIT Allahabad
// Hard

//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

int maxSubarraySum(int arr[], int n){
    
    int curr_sum = 0, max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        if(curr_sum < 0){
            curr_sum = 0;
        }
        
        max_sum = max(max_sum, curr_sum);
    }
    
    return max_sum;
}