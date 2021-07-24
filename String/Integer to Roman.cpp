// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    map<pair<int, int>, char> m;
    m[{1,4}] = 'M';
    m[{5,3}] = 'D';
    m[{1,3}] = 'C';
    m[{5,2}] = 'L';
    m[{1,2}] = 'X';
    m[{5,1}] = 'V';
    m[{1,1}] = 'I';
    string num = to_string(A);
    string res;
    for(int i = 0; i < num.size(); i++){
        int k = num.size()-i;
        if(num[i] == '9'){
            res.push_back(m[{1,k}]);
            res.push_back(m[{1,k+1}]);
        }else if(num[i] == '4'){
            res.push_back(m[{1,k}]);
            res.push_back(m[{5,k}]);
        }else if(num[i] >= '5'){
            res.push_back(m[{5, k}]);
            int t = num[i]-'5';
            while(t--) res.push_back(m[{1, k}]); 
        }else {
            int t = num[i]-'0';
            while(t--) res.push_back(m[{1, k}]);
        }
    }
    return  res;
}
