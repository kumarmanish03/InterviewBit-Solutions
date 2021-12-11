// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/generate-all-parentheses-ii/

// soln

class Solution {
public:
    
    void fun(int op, int cl, vector<string> &ans, string temp, int n){
        if(op == cl && n == op){
            ans.push_back(temp);
            return;
        }
        if(op > n){
            return;
        }
        
        if(op == cl){
            temp.push_back('(');
            fun(op+1, cl, ans, temp, n);
            temp.pop_back();
        }else if(op > cl){
            temp.push_back('(');
            fun(op+1, cl, ans, temp, n);
            temp.pop_back();
            temp.push_back(')');
            fun(op, cl+1, ans, temp, n);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        fun(0, 0, ans, temp, n);
        return ans;
    }
};

// Another soln
// For checking parenthesis
bool isCorrect(string A) {
    stack<char> s;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '('){
            s.push(A[i]);
        }
        else {
            if(s.empty())
                return 0;
            else
                s.pop();
        }
    }
    
    if(s.empty()) return 1;
    else return 0;
}

void compute(int A, string temp, set<string> &v){
    if(temp.size() == 2*A){
        if(isCorrect(temp))
            v.insert(temp);
        return;
    }
    
    temp.push_back('(');
    compute(A, temp, v);
    temp.pop_back();
    temp.push_back(')');
    compute(A, temp, v);
    temp.pop_back();
}

vector<string> Solution::generateParenthesis(int A) {
    set<string> v;
    string temp = "";
    compute(A, temp, v);
    vector<string> ans;
    for(auto i:v){
        ans.push_back(i);
    }
    
    return ans;
}
