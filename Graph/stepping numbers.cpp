// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/old/problems/stepping-numbers/

/*
Strategy:

Assume that we have a graph where the starting node is 0 and we need to traverse it from the start node to all the reachable nodes.
With the restrictions given in the graph about the stepping numbers, what do you think should be the restrictions defining the next transitions in the graph.
*/

vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    if(A == 0)
        res.push_back(A);
    queue<int> q;
    for(int i = 1; i < 10; i++){
        if(i >= A && i <= B){
            res.push_back(i);
        }
        if(i > B)
            continue;
        q.push(i);
    }
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int n = q.front();
            q.pop();
            int t = n%10;
            n = n * 10;
            int newNum;
            if(t!=0){
                newNum = n + t-1;
                if(newNum <= B){
                    q.push(newNum);
                    if(newNum >= A) res.push_back(newNum);
                }
            } 
            if(t!=9){
                newNum = n + t+1;
                if(newNum <= B){
                    q.push(newNum);
                    if(newNum >= A) res.push_back(newNum);
                }
            } 
        }
    }
    return res;
}
