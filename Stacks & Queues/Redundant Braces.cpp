// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    int n = A.size();
    stack<char> s;
    for(int i = 0; i < n; i++){
        if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/'){
            s.push(A[i]);
        }
        if(A[i] == ')'){
            if(s.top() == '('){
                return 1;
            }
            else{
                while(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return 0;
}

