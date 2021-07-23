// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    int cnt =0;
    for(auto c : A){
        if(c == '(') cnt++;
        if(c == '+' || c == '*' || c == '-' || c == '/') {
            if(cnt != 0)
                cnt--;
        }
            
    }
    if(cnt > 0)
        return 1;
    else
        return 0;
}
