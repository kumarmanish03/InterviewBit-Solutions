// Manish Kumar, IIIT Allahabad
// Medium, Important
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/maximum-ones-after-modification/

// Try to implement this once more

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0;
    int w = 0; // width of maximum subarray
    int k = 0; //zero count
    for(int j = 0; j < n; j++){
        if(A[j] == 0)
            k++;
            
        while(k > B) {
            if(A[i] == 0)
                k--;
            i++;
        }
        
        if(j - i + 1 > w){
            w = j - i + 1;
        }
        
    }
    
    return w;
    
}

