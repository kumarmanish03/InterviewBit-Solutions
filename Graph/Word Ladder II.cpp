// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/word-ladder-ii/
https://www.youtube.com/watch?v=mIZJIuMpI2M&t=1130s

// =======================================================

vector<vector<string>> ans;    //Stores all possible paths
    
void DFS(string &A, string &B, unordered_map<string, unordered_set<string> > &adj, vector<string> &path){
    path.push_back(A);
    
    if(A == B){
        ans.push_back(path);
        path.pop_back();
        return;
    }
    
    for(auto x:adj[A]){
        DFS(x, B, adj, path);
    }
    
    path.pop_back();
}

vector<vector<string> > Solution::findLadders(string A, string B, vector<string> &C) {
    ans.clear();
    unordered_set<string> dict(C.begin(), C.end());
    queue<string> q;
    q.push(A);
    unordered_map<string, unordered_set<string> > adj;
    unordered_map<string, int> vis;
    vis[A] = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            string temp = q.front();
            q.pop();

            string newt = temp;
            for(int k = 0; k < temp.size(); k++){
                for(int i = 'a'; i <= 'z'; i++){
                    newt[k] = i;
                    if(newt[k] == temp[k])
                        continue;
                    if(dict.count(newt) > 0){
                        if(vis.count(newt) == 0){
                            q.push(newt);
                            vis[newt] = vis[temp] + 1;
                            adj[temp].insert(newt);
                        }
                        else if(vis[newt] == vis[temp] + 1)
                            adj[temp].insert(newt);
                    }
                }
                newt[k] = temp[k];
            }
        }
    }
    
    vector<string> path;
    DFS(A, B, adj, path);
    
    return ans;
    
}
