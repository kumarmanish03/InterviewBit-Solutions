// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/generate-all-parentheses-ii/


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
