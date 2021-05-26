// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/substring-concatenation/

// Earlier i used compute_hash() for hashing, but it give wrong answer in some test cases(So use map instead)
// The below soln sort the vector of strings and concatenate them, then see similar in given string
// This ques also be done using map, see complete soln interviewbit



// long long compute_hash(string s) {
//     const int p = 31;
//     const int m = 1e9 + 9;
//     long long hash_value = 0;
//     long long p_pow = 1;
//     for (char c : s) {
//         hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
//         p_pow = (p_pow * p) % m;
//     }
//     return hash_value;
// }


string findHash(string s, int wsize, int tsize){
    long long m = 10e9 + 9;
    string sum = "";
    vector<string> sv;
    for(int i = 0; i < tsize*wsize; i+=wsize){
        sv.push_back(s.substr(i, wsize));
        //cout << s.substr(i, wsize) << " ";
    }
    sort(sv.begin(), sv.end());
    for(auto i:sv){
        sum += i;
    }
    
    return sum;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    vector<int> ans;
    long long m = 10e9 + 9;
    int wsize = B[0].size();
    int tsize = B.size();
    vector<string> C = B;
    for(int i = 0; i < C.size(); i++){
        sort(C.begin(), C.end());
    }
    string hash_sum = "";
    for(auto i:C){
        hash_sum += i;
    }
    for(int i = 0; i+wsize*tsize <= A.size(); i++){
        string hash_temp = findHash(A.substr(i, wsize*tsize), wsize, tsize);
        if(hash_temp == hash_sum)
            ans.push_back(i);
    }
    //cout<<"\n";
    return ans;
}
