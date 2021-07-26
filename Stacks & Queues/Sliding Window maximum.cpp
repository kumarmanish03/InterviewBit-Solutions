// Manish Kumar, IIIT Allahabad
// Hard, Standard
// Time Complexity : O(n)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/sliding-window-maximum/

// Soln 1
// Deque s.t. it always stores Maximum in front
// cpalgorithms.com [min stack, min queue topic]

deque<int> dq;

int getMax(){
    return dq.front();
}

void push(int element){
    while(!dq.empty() && dq.back() < element)
        dq.pop_back();
    dq.push_back(element);
}

void pop(int element){
    if(!dq.empty() && element == dq.front()){
        dq.pop_front();
    }
}

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    dq.clear();
    vector<int> v;
    if(B >= n){
        return {*max_element(A.begin(), A.end())};
    }

    for(int i = 0; i < B; i++){
        push(A[i]);
    }
    v.push_back(getMax());

    for(int i = B; i < n; i++){
        // Pushing current element
        push(A[i]);
        
        // Poping last max_element
        pop(A[i-B]);
        
        v.push_back(getMax());
    }
    
    return v;
}


// ==========================================
// Soln 2

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