// Manish Kumar, IIIT Allahabad
// Medium, Tricky
// Time Complexity : O(n)
// Space Complexity : O(n)

https://www.interviewbit.com/problems/longest-substring-without-repeat/

// All you need to do is use two pointers to keep a window with no repetitions of characters.
// Keep moving the right pointer and if you encounter any repeating character start moving left pointer untill no character is repeated.

// Hasing can also be done without using map, using bool array[256] to store existence

int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<int, int> m;
    int max_count = INT_MIN;
    int i = 0;
    int j = 0;
    int count = 0;
    while(j < A.size() && i < A.size()){
        //Not found
        if(m.find(A[j]) == m.end()){
            m[A[j]]++; 
            if(count < j - i + 1){
                count = j-i+1;
                //cout << j<<" "<<i<<"\n";
            }
            j++;
        }
        // found
        else{
            while(m.find(A[j]) != m.end()){
                m.erase(A[i]);
                i++;
            }
        }
        
    }
    
    return count;
}
