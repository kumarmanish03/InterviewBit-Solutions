// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/problems/word-ladder-i/


int Solution::solve(string A, string B, vector<string> &C) {
    // Use unordered set, unless it may give TLE
    unordered_set<string> dict(C.begin(), C.end());
    queue<string> q;
    int depth = 0;
    q.push(A);
    while(!q.empty()){
        int size = q.size();
        depth++;
        while(size--){
            string temp = q.front();
            q.pop();
            
            if(temp.compare(B) == 0)
                return depth;
                
            for(int k = 0; k < temp.size(); k++){
                string newt = temp;
                for(int i = 'a'; i <= 'z'; i++){
                    newt[k] = i;
                    if(newt.compare(temp) == 0)
                        continue;
                    if(dict.find(newt) != dict.end()){
                        q.push(newt);
                        // remove word if found
                        dict.erase(newt);
                    }
                }
            }
        }
    }
    
    return 0;
}
