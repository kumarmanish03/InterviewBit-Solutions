// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O(n)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> right(n, n);
    vector<int> left(n, -1);
    stack<int> s;
    int area;
    for(int k = 0; k < n; k++){
        while(!s.empty() && A[s.top()] >= A[k]){
            s.pop();
        }
        if(!s.empty()) left[k] = s.top();
        s.push(k);
    }

    while(!s.empty())
        s.pop();

    for(int k = n-1; k >= 0; k--){
        while(!s.empty() && A[s.top()] >= A[k]){
            s.pop();
        }
        if(!s.empty()) right[k] = s.top();
        s.push(k);
    }

    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        area = (right[i]-left[i]-1)*A[i];
        mx = max(mx, area);
    }
    return mx;
}
