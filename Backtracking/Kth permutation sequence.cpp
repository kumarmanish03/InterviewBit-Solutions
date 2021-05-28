// Manish Kumar, IIIT Allahabad
// Hard, Maths, Must try, V.IMP.

https://leetcode.com/problems/permutation-sequence/


class Solution {
public:
    
    
    string getPermutation(int A, int B) {
        if(A > 12) return to_string(INT_MAX);
        int fact[12];
        fact[0] = fact[1] = 1;
        for(int i = 1; i <= A; i++){
            fact[i] = i * fact[i-1];
        }
        string s;
        vector<int> temp;
        vector<bool> chosen(A,false);
        set<int> v;
        for(int i = 0; i < A; i++){
            v.insert(i+1);
        }
        int k = B;
        int n = A;

        int i = 1;
        while(n > 0){
            if(k - fact[n-1] > 0){
                k = k - fact[n-1];
                i++;
            }
            else{
               for(auto s:v){
                 i--;
                 if(i == 0){
                  temp.push_back(s);
                  v.erase(s);
                  break;
                 }
               }
               i = 1;
               n = n-1;
            }
        }

        for(auto i:v){
            temp.push_back(i);
        }

      for(auto i:temp){
        s += to_string(i);
      }

      return s;
    }
};