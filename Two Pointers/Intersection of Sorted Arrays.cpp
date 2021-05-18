// Manish Kumar, IIIT Allahabad
// Easy, But notice the concept of two pointers
// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

// Read last paragraph of Solution Approach(InterviewBit)

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> v;
    int i = 0;
    int j = 0;
    while(1) {
        if(i == A.size() || j == B.size()) break;
        if(A[i] == B[j]){
            v.push_back(A[i]);
            j++;
            i++;
            continue;
        } 
        else if(A[i] > B[j]) j++;
        else if(A[i] < B[j]) i++;
    }
    
    return v;
}
