// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/courses/programming/topics/hashing

// hash[n][i] stores the all occurances of 26 (i) characters of first n elements of A

int Solution::solve(string A) {
    int n = A.length();
    int odd = 0;
    vector<vector<int>> hash(n+1, vector<int>(26, false));

    for(int i = 1; i < n+1; i++){
        hash[i] = hash[i-1];
        hash[i][A[i-1]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(hash[n][i] % 2 == 1)
            odd++;
    }

    if(odd > 1)
        return 0;
    else
        return 1;
}
