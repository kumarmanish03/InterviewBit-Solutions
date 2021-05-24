// Manish Kumar, IIIT Allahabad
// Hard, Standard
// Time Complexity : O(nlog(m))
// Space Complexity : O(1)

https://www.interviewbit.com/problems/painters-partition-problem/

// This is similar to EKO-EKO & Allocate books, but catch here is interger overflow
// Since in this ques constrains are like that it may overflow in int, hence use long long
// Since in below soln I'm have not intialize in long long so alternately I converted to like (long long)
// You can also compare the Complete Solution of InterviewBit for more

// Catch : In this ques catch is using long long wisely, unless you may end up with wrong answer

bool isPossible(int capacity, vector<int> v, int painters){
    int sum = 0;
    int count = 1;
    for(int i = 0; i < v.size(); i++){
        sum = ((long long)sum % 10000003 + (long long)v[i] % 10000003) % 10000003;
        if(sum > capacity){
            count++;
            sum = v[i];
        }
    }
    
    return count <= painters;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int lo = INT_MIN;
    int hi = 0;
    for(auto i: C){
        hi = ((long long)hi % 10000003 + (long long)i % 10000003) % 10000003;
        lo = max(lo, i);
    }
    
    if(A >= C.size()){
        return (lo % 10000003 * B % 10000003) % 10000003;
    }
    
    //  cout << (hi % 10000003 * B % 10000003) % 10000003;
    // return isPossible(10, C, A);
    
    while(hi - lo > 1){
        int mid = lo + (hi - lo) / 2;
        if(isPossible(mid, C, A)){
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    
    if(isPossible(lo, C, A)){
        return ((long long)lo % 10000003 * (long long)B % 10000003) % 10000003;
    }
    else 
        return ((long long)hi % 10000003 * (long long)B % 10000003) % 10000003;
    
}
