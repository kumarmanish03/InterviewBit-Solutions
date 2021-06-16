// Manish Kumar, IIIT Allahabad
// Hard

https://www.interviewbit.com/problems/knight-on-chess-board/
https://www.youtube.com/watch?v=FhwNdxnb738

// BFS

// Strategy: 
// cell represents a vertex, 'dist' represents its distance from source cell
// we start from source and move to possible valid cells and increment 'dist' 
// As soon as we find our Destination, we return the 'dist' (which obviously give minimum steps)

struct cell {
    int x;
    int y;
    int dist;
    cell() {}
    cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isInside(int x, int y, int A, int B){
    if(x >= 0 && x < A && y >= 0 && y < B)
        return true;
    return false;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1 ,-1, -2, -2, -1};
    vector<vector<bool>> vis(A, vector<bool> (B, false));
    queue<cell> q;
    cell src(C-1, D-1, 0);
    q.push(src);
    int x, y;
    while(!q.empty()){
        cell t = q.front();
        q.pop();
        if(t.x == E-1 && t.y == F-1)
            return t.dist;
        for(int i = 0; i < 8; i++){
            x = t.x + dx[i];
            y = t.y + dy[i];
            if(isInside(x, y, A, B) && !vis[x][y]){
                vis[x][y] = true;
                cell c(x, y, t.dist+1);
                q.push(c);
            }
        }
    }
    
    return -1;
}
