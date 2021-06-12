// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

// This is a problem of catalen numbers
// Just calculate : nth catalen no. = no. of BSTs formed

long long int catalen(int n){
    if(n <= 1)
        return 1;
        
    long long int res = 0;
    for(int i = 0; i <n; i++){
        res += catalen(i) * catalen(n-i-1);
    }
    
    return res;
}

int Solution::numTrees(int A) {
    return catalen(A);
}
