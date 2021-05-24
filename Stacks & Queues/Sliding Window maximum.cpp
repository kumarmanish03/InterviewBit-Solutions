// Manish Kumar, IIIT Allahabad
// Medium, Classes and Objects
// Time Complexity : O(n)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/sliding-window-maximum/

https://www.youtube.com/watch?v=39grPZtywyQ

// Watch video for Explanation

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    vector<int> v;
    if(B > n){
        return {*max_element(A.begin(), A.end())};
    }
    
    deque<int> dq;
    dq.push_front(0);
    for(int i = 1; i < B; i++){
        while(!dq.empty() && A[dq.front()] < A[i]){
            dq.pop_front();
        }
        dq.push_front(i);
    }
    v.push_back(A[dq.back()]);
    for(int i = B; i < A.size(); i++){
        while(!dq.empty() && dq.back() <= i-B){
            dq.pop_back();
        }
        while(!dq.empty() && A[dq.front()] < A[i]){
            dq.pop_front();
        }
        dq.push_front(i);
        v.push_back(A[dq.back()]);
    }
    
    return v;
}