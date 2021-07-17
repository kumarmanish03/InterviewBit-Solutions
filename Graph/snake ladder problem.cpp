// Manish Kumar, IIIT Allahabad
// Medium

https://www.interviewbit.com/old/problems/snake-ladder-problem/

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int, int> snake;
    unordered_map<int, int> ladder;
    for(auto i : A){
        ladder[i[0]] = i[1];
    }
    for(auto i : B){
        snake[i[0]] = i[1];
    }
    vector<bool> vis(101, false);
    // {pos, steps}
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int pos = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(pos == 100)
                return steps;
            for(int k = 1; k <= 6 and pos + k <= 100; k++){
                int newpos = pos + k;
                if(vis[newpos] == true) continue;
                vis[newpos] = true;
                if(newpos == 100) return steps+1;
                if(snake.count(newpos) > 0)
                    q.push({snake[newpos], steps + 1});
                else if(ladder.count(newpos) > 0)
                    q.push({ladder[newpos], steps + 1});
                else
                    q.push({newpos, steps + 1});
            }
        }
    }
    return -1;
}
