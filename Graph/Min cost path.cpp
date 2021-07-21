// Manish Kumar, IIIT Allahabad
// Hard

// Can be done with better complexity using 0-1 BFS approach

https://www.interviewbit.com/old/problems/min-cost-path/

#define ti tuple<int,int,int>

int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};
char dpos[4] = {'U', 'L', 'R', 'D'};

bool isValid(int i, int j, int A, int B){
    if(i < 0 || j < 0 || i > A-1 || j > B-1){
        return false;
    }
    return true;
}

int Solution::solve(int A, int B, vector<string> &C) {
    priority_queue<ti,vector<ti>,greater<ti>> pq;
    if(A ==1 && B == 1) return 0;
    vector<vector<bool>> vis(A, vector<bool>(B, false));
    vector<vector<int>> dis(A, vector<int>(B, INT_MAX));
    pq.push({0, 0, 0});
    dis[0][0] = 0;
    
    while(!pq.empty()){
        auto [cost, i, j] = pq.top();
        pq.pop();
        vis[i][j] = true;
        
        if(i == A-1 && j == B-1)
            return cost;
        
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!isValid(ni, nj, A, B) || vis[ni][nj]) continue;
            
            if(dpos[k] == C[i][j]){
                dis[ni][nj] = cost;
                pq.push({cost, ni, nj});
            }
            else if(dis[ni][nj] > dis[i][j]+1){
                dis[ni][nj] = dis[i][j]+1;
                pq.push({dis[ni][nj], ni, nj});
            }
        }
    }
    return dis[A-1][B-1];
}
