// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://www.interviewbit.com/problems/majority-element/

// A simple soln is using unordered_map but this ques could be solved without using it i.e, in SP : O(1)
// Greedy Approach : 
// The greedy approach is since no. is always present more than half in the array
// then it is surely that atleast one pair of given no. is present adjacent OR given no. may present at both ends of the array

// Soln using unordered_map, Space Complexty : O(n);

int Solution::majorityElement(const vector<int> &A) {
    unordered_map<int, int> m;
    int n = A.size();
    for(int i = 0; i < n; i++){
        m[A[i]]++;
    }
    // int maximum = INT_MIN;
    
    for(auto i:m){
        if(i.second > n / 2){
            return i.first;
        }
    }
}

// Soln using simple traversing, Space Complexity : O(1)

int Solution::majorityElement(const vector<int> &A) {
    int elem=0, count=1;
    for(int i=1; i<A.size(); ++i)
    {
        if(A[i]==A[elem]) ++count;
        else --count;
        if(count==0) elem=i, count=1;
    }
    return A[elem];
}

