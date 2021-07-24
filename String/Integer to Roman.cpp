// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/integer-to-roman/

// =================================================
// Soln 1
// Also see IB soln

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


// =======================================
// Soln 2

class Solution {
public:
    string intToRoman(int num) {
        // 1000, 2000, 3000
        string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
